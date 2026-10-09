/*
线程是程序执行中的单一顺序控制流，多个线程可以在同一个进程中独立运行
线程共享进程的地址空间、文件描述符、堆和全局变量等资源，但每个线程有自己的栈、寄存器和程序计数器

使用时要包含<thread>头文件
多线程的核心组件包括：
1.std::thread : 用于创建和管理线程的类
2.st::mutex : 互斥锁，用于保护共享资源，防止多个线程同时访问同一资源导致数据竞争
3.std::lock_guard & std::unique_lock : 用于自动管理互斥锁的锁定和解锁，确保在作用域结束时释放锁
4.std::condition_variable : 条件变量，用于线程间的同步，允许线程等待
5.std::future & std::promise : 用于线程间的异步通信和结果传递

在程序完成后应该调用join()方法等待线程完成，或者调用detach()方法将线程分离，使其在后台运行，否则会导致程序崩溃

线程同步与互斥：
1.互斥锁（Mutex）：用于保护共享资源，确保同一时间只有一个线程可以访问该资源。C++提供了std::mutex类来实现互斥锁。
    使用std::lock_guard或std::unique_lock可以自动管理互斥锁的锁定和解锁
2.锁：
    std::lock_guard：一种RAII风格的互斥锁管理器，在构造时锁定互斥锁，在析构时自动解锁，适用于简单的锁定场景
    std::unique_lock：提供更灵活的锁管理，可以在需要时手动锁定和解锁，支持延迟锁定和条件变量的使用
3.条件变量（Condition Variable）：用于线程间的同步，允许线程等待某个条件的发生。
    C++提供了std::condition_variable类来实现条件变量，通常与互斥锁一起使用，以确保线程在等待条件时不会占用CPU资源
4.原子操作（Atomic Operations）：C++提供了std::atomic类模板，用于实现原子操作，确保对共享变量的操作是不可分割的，从而避免数据竞争
5.线程局部存储（Thread Local Storage）：C++提供了thread_local关键字，用于声明线程局部变量，每个线程都有自己的独立实例，避免了共享资源的竞争问题
6.死锁和避免策略：
    死锁是指两个或多个线程在等待对方释放资源，从而导致所有线程都无法继续执行的情况。为了避免死锁，可以采取以下策略：
    1.避免嵌套锁定：尽量减少同时持有多个锁的情况，避免嵌套锁定
    2.锁顺序：确保所有线程以相同的顺序获取锁，避免循环等待
    3.使用try_lock：尝试获取锁，如果无法获取，则放弃并稍后重试，避免长时间阻塞
    4.使用超时机制：在等待锁时设置超时，如果超过一定时间仍未获取锁，则放弃等待，避免无限期阻塞


这一部分教程也说的不清不楚，要用的时候再看吧
*/

#include <iostream>
#include <thread>

//=================================================创建线程的方法=================================================
// //使用函数指针创建线程
// void printMessage(int count)
// {
//     for (int i = 0; i < count; ++i)
//     {
//         std::cout << "Hello from thread (function pointer)!" << std::endl;
//     }
// }

// int main()
// {
//     std::thread t1(printMessage, 5); // 创建线程并传递参数
//     t1.join();                       // 等待线程完成
//     return 0;
// }

// //使用函数对象
// class PrintTask
// {
//     public:
//         void operator()(int count) const     //重载
//         {
//             for (int i = 0; i < count; ++i)
//             {
//                 std::cout << "Hello from thread " << i << std::endl;
//             }
//         }

// };

// int main()
// {
//     std::thread t2(PrintTask(), 5); // 创建线程并传递参数
//     t2.join();                      // 等待线程完成
// }

// //使用lambda表达式
// /*
// lambda = 就地写一个匿名函数——不起名字、不单独定义，直接写在用的地方（C++11 引入）。骨架是：
// [捕获列表](参数列表) { 函数体 }
// 捕获列表：指定lambda表达式可以访问的外部变量，可以是值捕获（拷贝外部变量的值）或引用捕获（引用外部变量），
// eg: [=]表示值捕获所有外部变量，[&]表示引用捕获所有外部变量，[x, &y]表示值捕获x，引用捕获y
// 参数列表：指定lambda表达式的参数类型和名称，类似于函数的参数
// */
// int main()
// {
//     std::thread t3(
//         [](int count)
//         {
//             for (int i = 0; i < count; ++i)
//             {
//                 std::cout << "Hello from thread (lambda)!" << std::endl;
//             }
//         },
//         5);    // 创建线程并传递参数
//     t3.join(); // 等待线程完成
//     return 0;
// }

//==========================================线程的传参=========================================
//值传递 参数可以通过值传递的方式传递给线程函数，线程函数会接收参数的副本，修改副本不会影响原始参数
//引用传递，需要使用std::ref()来传递引用参数，确保线程函数接收的是原始参数的引用，从而可以修改原始参数

// void increment(int &x)
// {
//     ++x;
// }

// int main()
// {
//     int num = 4;
//     std::thread t(increment, std::ref(num));   // 使用std::ref()传递引用参数
//     t.join();                                  // 等待线程完成
//     std::cout << "num = " << num << std::endl; // 输出结果
//     return 0;
// }

// //====================================互斥锁===================================
#include <mutex>
std::mutex mtx; // 创建互斥锁对象
// void safeFunction()
// {
//     mtx.lock(); // 锁定互斥锁，保护共享资源的访问
//     // 访问共享资源的代码
//     mtx.unlock(); // 在访问共享资源之前锁定互斥锁，访问完成后解锁
// }

// int main()
// {
//     std::thread t1(safeFunction);
//     std::thread t2(safeFunction);
//     t1.join();
//     t2.join();
//     return 0;
// }

//===================================锁===================================
void safeFunctionWithLockGuard()
{
    std::lock_guard<std::mutex> lock(mtx); // 使用std::lock_guard自动管理互斥锁的锁定和解锁
    // 访问共享资源的代码
}