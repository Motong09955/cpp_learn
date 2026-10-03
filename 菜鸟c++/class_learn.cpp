#include <iostream>

class Box //类提供数据对象的蓝图/模板，用于后续创建一个是该类的对象
{
    public :        //public or private or protected 为访问修饰符，public内的成员可以在类的外部访问，
                    //private内的成员只能在类的内部访问，protected内的成员可以在类的内部和派生类中访问。
                    //目的是为了隐藏类的实现细节，保护数据成员不被随意访问和修改，保证数据的安全性和完整性。只提供必要的接口给外部使用。
                    //当不著名访问修饰符时，默认是private的。⭐
                    
                    //protected访问修饰符主要用于继承关系中，允许派生类访问基类的成员，但不允许外部访问。
                    //它提供了一种在继承层次结构中共享数据的方式，同时仍然保持对外部的封装性。
        //变量
        double length;
        double width;
        double height;
        
        //方法
        /*类的成员函数是指那些把定义和原型写在类定义内部的函数，就像类定义中的其他变量一样。
          类成员函数是类的一个成员，它可以操作类的任意对象，可以访问对象中的所有成员。
          成员函数可以定义在类定义内部，（见下get_volume）或者单独使用范围解析运算符 :: 来定义。
        */
        double get_volume(void);
            // {
            //     return length * width * height;
            // }
        void set(double len, double wid, double hei);


        Box();      //类的构造函数，在创建类的新对象时自动执行
                    //构造函数的名字与类名相同，且没有返回类型，也不能被声明为const或volatile。通常用于为成员变量设定初始值
                    //未显式定义构造函数时，编译器会提供一个默认的无参构造函数。
                    //可以使用带参数的构造函数来初始化对象的成员变量，也可以使用初始化列表来初始化成员变量（推荐⭐）。

        ~Box();     //类的析构函数，在对象生命周期结束时自动执行，用于释放对象占用的资源
                    //析构函数的名字与类名相同，前面加上波浪号（~），没有返回类型，也不能被声明为const或volatile。
                    //析构函数通常用于释放对象在其生命周期内分配的资源，如动态内存、文件句柄等。

        //使用初始化列表来初始化字段：
            // Box(): length(0.0), width(0.0), height(0.0) {
            //     std::cout << "Object is being created" << std::endl;
            // };

        Box(const Box &obj);        //拷贝构造函数，使用一个对象来初始化另一个对象时调用
        
    private :
        int *ptr;
};

//构造函数定义
Box::Box()
{
    std::cout << "Object is being created" << std::endl;
    length =0.0;
}

//析构函数定义
Box::~Box()
{
    std::cout << "Object is being deleted" << std::endl;
}

//拷贝构造函数定义
Box::Box(const Box &obj)
{
    std::cout << "调用拷贝构造函数并为指针ptr分配内存" << std::endl;
    ptr =new int;       //new的作用：在堆上分配一块内存，（并立刻调用构造函数）（当对象是类时），然后返回指向这个新对象的指针
    *ptr =*obj.ptr; //拷贝值
}

//定义成员函数
double Box::get_volume(void)
{
    return length * width * height;
};

void Box::set(double len, double wid, double hei)
{
    length = len;
    width = wid;
    height = hei;//相比python中的类，这里隐式地使用了self参数（c++中为this指针），python中需要显式地传入self参数
};



int main()
{
    Box Box1;
    Box Box2;       // 声明 Box1，Box2，Box3 为 Box 类的对象
    Box Box3;
    double volume = 0.0;     // 用于存储体积

    Box1.set(5,6,7);
    Box2.height = 10;
    Box2.width = 20;

    Box3.height = 20;
    Box3.length = 30;
    Box3.width = 40;

    //对于private或protected成员，不能通过"."访问，必须通过类的public成员函数来访问⭐
    volume = Box1.get_volume();//调用Box的成员函数
    std::cout << "Box1的体积： " <<volume << std::endl;
    volume = Box1.length * Box1.width * Box1.height;
    std::cout << "BOx1通过直接数据计算得到的体积：" <<volume << "\n";
    volume = Box2.get_volume();
    std::cout << "Box2的体积： " <<volume << std::endl;

    volume = Box3.get_volume();
    std::cout << "Box3的体积： " <<volume << std::endl;

}