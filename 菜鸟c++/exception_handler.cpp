/*
异常是程序在执行期间产生的问题。C++ 异常是指在程序运行时发生的特殊情况，比如尝试除以零的操作。

异常提供了一种转移程序控制权的方式。C++ 异常处理涉及到三个关键字：try、catch、throw。

    throw: 当问题出现时，程序会抛出一个异常。这是通过使用 throw 关键字来完成的。
    catch: 在您想要处理问题的地方，通过异常处理程序捕获异常。catch 关键字用于捕获异常。
    try: try 块中的代码标识将被激活的特定异常。它后面通常跟着一个或多个 catch 块。

    可以使用try来包含一个代码块，当被保护的代码出现异常时，try后的catch关键字可以进行捕获
    try/catch语句的用法
    """
    try
    {
        //保护代码
    }catch(ExceptionName e1)
    {
        //处理ExceptionName 的异常代码
    }
    """
    通过catch关键字后括号内的内容来指定想要捕捉的异常类型，
    当想要让catch块能够处理try抛出的所有类型的异常时必须在catch后的括号内使用省略号"..."

    当try内的块在不同情境下会出现不同异常时可以在try后罗列多个catch语句

    可以使用throw赖在代码块的任何地方抛出异常。throw语句后跟着的表达式可以是任意的
    eg：
        double division(int a, int b)
        {
            if( b == 0 )
            {
                throw "Division by zero condition!";
            }
            return (a/b);
        }

    throw 404
    throw MyError("Bad Input!")

标准库提供了一系列标准的异常，定义在<exception>中⭐，他们以父子层次组织起来
|std:exception|
        |std::bad_alloc     new 分配内存失败时抛
        |std::bad_cast      dynamic_cast 转引用失败时抛
        |std::bad_typeid    对空指针做 typeid 时抛
        |std::bad_exception 在处理c++中无法预期的异常时非常有用
        |std::logic_error|
                |std::domain_error      数学定义域错误；标准库很少抛它，多用于自定义代码
                |std::invalid_argument  参数无效，比如 stoi("abc")
                |std::length_error      想造超过长度上限的东西
                |std::out_of_range      越界，比如 stoi 的数字超范围、容器的 at() 访问越界（[] 越界不检查、不抛）
        |std::runtime_error|
                |std::overflow_error    算术上溢（数值超出表示范围）
                |std::range_error       结果超出有意义范围
                |std::underflow_error   算数下溢
*/

#include <iostream>
#include <exception>

/*
通过继承和重载exception类来定义新的异常
*/
struct MyException : public std::exception
//这里用struct是为了少写一个public
//成员默认访问权限：struct 是 public，class 是 private；
//默认继承方式：struct 是 public 继承，class 是 private 继承
{
    // public:  //如果用class要加这一行
    const char* what() const throw()
    //这里的throw()不是 throw 语句——它是"异常规格"，声明"本函数不抛任何异常"，是老标准写法，等价于现在的 noexcept
    {
        return "C++ Exception";
    }
    //这里的what()是std:exception所包含的一个虚函数，用于子类重载
};

int main()
{
    try
    {
        throw MyException();
    }
    catch(MyException& e)
    {
        std::cout << "MyException Caught!" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e)
    {

    }
}