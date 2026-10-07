/*
模板是泛型编程的基础
    泛型编程：把“类型”也变成参数——代码只写一份，用的时候再填具体类型
可以使用模板来定义函数和类

函数模板：
    template <typename type> ret-type func-name(parameter list)
    {
        //函数主体
    }
    template：关键字——声明"下面这个东西是个模板"；
    <typename type>：模板参数列表，尖括号里定义类型占位符。typename 说明"type 代表一个类型"；而 type 这里是类型占位符
        这里的typename和class等价
    ret-type：返回类型。可以写具体类型（比如 int），也可以用占位符（比如 T，表示"返回类型等于某个占位符"）；
    func-name：函数名，正常起；
    (parameter list)：参数列表，正常写，但里面可以出现占位符（T a, T b 这种）；

类模板 ：
    template <class type> class class-name 
    {
    }
*/

//==========函数模板===========
// #include <iostream>
// #include <string>

// template <typename T>
// inline T const& Max (T const& a, T const& b)
// {
//     return a>b ? a:b;
// }

// int main()
// {
//     int i =39;
//     int j = 12;
//     int int_max = Max(i,j);
//     std::cout << "int_max: " << int_max <<std::endl;

//     double f1 = 12.34;
//     double f2 = 12.22;
//     double fmax = Max(f1,f2);
//     std::cout << "double_max: " << fmax << std::endl;

//     std::string s1 = "Hello";
//     std::string s2 = "World";
//     std::cout << "Max(s1,s2): " <<Max(s1,s2) << std::endl;
// }


//=============类模板=============
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

template <class T>
class Stack
{
    private:
        std::vector <T> elems;

    public:
        void push(T const&);
        void pop();
        T top() const;      //几个成员函数 第一眼看不明白多看两眼就懂了
        bool empty() const
        {
            return elems.empty();
        }
};

template <class T>
void Stack<T>::push (T const& elem)
{
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
    if(elems.empty())
    {
        throw std::out_of_range("Stack<>::pop()::empty stack");
    }
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if(elems.empty())
    {
        throw std::out_of_range("Stack<>::top():empty stack");
    }
    return elems.back();
}

int main()
{
    try
    {
        Stack<int> intStack;
        Stack<std::string> stringStack;

        intStack.push(7);
        std::cout << intStack.top() <<std::endl;

        stringStack.push("Hello");
        std::cout << stringStack.top() <<std::endl;
        stringStack.pop();
        // stringStack.pop();
    }
    catch(std::exception const& ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return -1;
    }
}