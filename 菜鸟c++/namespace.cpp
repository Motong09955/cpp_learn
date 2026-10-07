/*
命名空间就是先前使用的namespace之类的
能够避免出现当在不同头文件中定义同名文件时出现的无法判断问题

使用namespace 来创建命名空间

命名空间可以分布在几个不同的部分中，一个命名空间的各部分可以分散在多个文件中

嵌套的命名空间 命名空间可以进行嵌套
namespace namespace_name1
{
    namespace namespace_namee2
    {
    }
}

对于重名的全局变量与局部变量，
假设是a，那么::a表示全局变量的a
            a表示局部变量的a
*/

#include <iostream>

namespace first_space{
    void func(){
        std::cout << "Inside firet_space" << std::endl;
    }
}

namespace second_space{
    void func(){
        std::cout << "Second Inside" <<std::endl;
    }
}

using namespace first_space;

int main()
{
    func();
    second_space::func();
}