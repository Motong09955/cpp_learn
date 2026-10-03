/*
    c++的多态
    多态就是多种形态
    c++多态允许使用基类指针或引用来调用子类的重写方法，从而使得同一个接口可以表现出不同的行为
    多态是面向对象编程的三大特征之一，另外两个是封装和继承
    多态有几个关键点⭐：
    1.虚函数
        ~ 在基类中声明一个函数为虚函数，使用关键字virtual修饰，这样在派生类中重写该函数时，
          基类指针或引用就可以调用派生类的版本，而不是基类的版本
        ~ 派生的类可以重写这个虚函数
        ~ 调用虚函数时，会同过具体的对象类型来决定调用哪个版本的函数，这种机制称为动态绑定或运行时多态
    2.动态绑定
        ~ 在运行时根据对象的实际类型来决定调用哪个函数版本，而不是在编译时就确定
        ~ 需要使用指向基类的指针或引用来调用虚函数
    3.纯虚函数和抽象类
        ~ 纯虚函数是没有实现的虚函数，使用=0来声明
        ~ 抽象类是包含至少一个纯虚函数的类，不能直接实例化对象，只能作为基类来派生子类
        ~ 纯虚函数强制派生类提供具体的实现
    4.多态的实现机制
        ~ 通过虚函数表（vtable）和虚函数指针（vptr）来实现
        ~ 每个包含虚函数的类都有一个虚函数表，存储了该类的虚函数地址
        ~ 每个对象都有一个指向其类的虚函数表的指针，当调用虚函数时，通过这个指针查找正确的函数地址并调用
    5.多态的优点
        ~ 代码的复用性 通过基类指针或引用可以操作不同的派生类对象，减少代码重复
        ~ 可扩展性 新增派生类时无需修改现有代码，只需实现基类的接口即可
        ~ 可维护性 通过统一的接口来操作不同的对象，降低了代码的耦合度，提高了可维护性
    6.多态的缺点
        ~ 性能开销 由于动态绑定需要在运行时查找函数地址，相比静态绑定有一定的性能开销
        ~ 复杂性 增加了程序的复杂性，理解和调试多态代码可能更困难
        ~ 内存开销 每个对象需要额外的内存来存储虚函数指针，增加了内存开销
    7.注意
        ~ 析构函数应该声明为虚函数，以确保通过基类指针删除派生类对象时，派生类的析构函数能够被正确调用，避免资源泄漏
        ~ 多态只适用于通过指针或引用调用虚函数，直接通过对象调用不会产生多态效果
        ~ 多态不能用于静态成员函数和非成员函数，因为它们不属于对象实例
        ~ 多态的实现依赖于继承关系，只有在基类和派生类之间存在继承关系时才能实现多态
*/

/*
虚函数与纯虚函数的对比：
特性|虚函数|纯虚函数
定义|使用virtual关键字声明，并在函数声明后加上=0|使用virtual关键字声明，并在函数声明后加上=0
子类重写|选择性|必须重写
对象实例化|可以实例化对象|不能实例化对象
用途|提供默认实现，允许子类选择性重写|定义接口，强制子类提供具体实现

*/

//=====================EXAMPLE1============================
// #include <iostream>

// class Animal
// {
//     public:
//         virtual void speak() const 
//         {
//             std::cout << "Animal makes a sound" << std::endl;
//         }
//         virtual ~Animal()
//         {
//             std::cout << "Animal destroyed" << std::endl;
//         }
// };

// class Dog :public Animal
// {
//     public:
//         void speak() const override     
//         //这里override关键字向编译器声明“我这个函数是要重写基类虚函数的”，签名对不对让它来查。它本身不改变任何行为，纯粹是一道编译期检查
//         {
//             std::cout << "Dog barks" << std::endl;
//         }
//         ~Dog()
//         {
//             std::cout << "Dog destroyed" << std::endl;
//         }
// };

// class Cat :public Animal
// {
//     public:
//         void speak() const override
//         {
//             std::cout << "Cat meows" << std::endl;
//         }
//         ~Cat()
//         {
//             std::cout << "Cat destroyed" << std::endl;
//         }
// };

// int main()
// {
//     Animal* animalPtr;
//     animalPtr = new Dog();
//     animalPtr->speak();
//     delete animalPtr;

//     animalPtr = new Cat();
//     animalPtr->speak();
//     delete animalPtr;

//     return 0;
// }


//=================EXAMPLE2========================
// #include <iostream>
// class Shape
// {
//     protected:
//         int width,height;
//     public:
//         Shape(int a=0,int b=0):width(a),height(b){};
//         virtual int area()=0; 
// };

// class Rectangle:public Shape
// {
//     public:
//         Rectangle(int a=0,int b=0):Shape(a,b){};
//         int area() override
//         {
//             std::cout<<"Rectangle class area:"<<std::endl;
//             return (width*height);
//         }
// };

// class Triangle:public Shape
// {
//     public:
//         Triangle(int a=0,int b=0):Shape(a,b){};
//         int area() override
//         {
//             std::cout<<"Triangle class area:"<<std::endl;
//             return (width*height)/2;
//         }
// };

// int main()
// {
//     Shape* shape;
//     Rectangle rec(10,7);
//     Triangle tri(4,5);

//     shape = &rec;
//     std::cout<<shape->area()<<std::endl; 

//     shape = &tri;
//     std::cout<<shape->area()<<std::endl;

//     return 0;
// }

//=====================EXAMPLE3========================
#include <iostream>
class Shape
{
    public:
        virtual int area()=0;
};

class Rectangle:public Shape
{
    private:
        int width,height;
    public:
        Rectangle(int a=0,int b=0):width(a),height(b){};
        int area() override
        {
            std::cout<<"Rectangle class area:"<<std::endl;
            return (width*height);
        }
};

int main()
{
    Shape* shape;
    Rectangle rec(10,7);

    shape = &rec;
    std::cout<<shape->area()<<std::endl; 

    return 0;
}