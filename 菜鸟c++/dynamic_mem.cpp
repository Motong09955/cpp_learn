/*
在 C++ 中，可以使用"new"运算符为给定类型的变量在运行时分配堆内的内存，这会返回所分配的空间地址
当不再需要动态分配的内存空间，可以使用 delete 运算符，删除之前由 new 运算符分配的内存

new运算符为任意的数据类型动态分配内存的通用语法：
    new data-type
这里的data-type可以是包括数组在内的任意的内置的数据类型，也可以是类或结构在内的自定义的任何数据类型

eg:
    double* pvalue = NULL;
    pvalue = new double;

其中，为了避免出现自由存储区耗尽，无法成功分配内存的情况，建议检查new运算符是否返回空指针：
    eg:    
        double* pvalue = NULL;
        if(!(pvalue = new double))
        {
            std::cout << "Error: out of memory" << std::endl;
            exit(1);
        }
            delete pvalue;

在c++中建议尽量不适用malloc函数，new的主要优点在于不仅分配了内存，还创建了对象
*/

// #include <iostream>

// int main()
// {
//     double* pvalue = NULL;
//     std::cout << "the memory of * before new:" << pvalue << std::endl;
//     if(!(pvalue = new double))
//     {
//         std::cout << "Error: out of memory" << std::endl;
//         exit(1);
//     }
//     std::cout << "the memory of * after new:" << pvalue << std::endl;
//     *pvalue = 122324;
//     std::cout << "Value of pvalue: " << *pvalue << std::endl;
//     delete pvalue;
//     std::cout << "the memory of * after delete:" << pvalue << std::endl;
// }

/*
    数组内存的动态分配
假设要为一个字符数组分配内存，可以使用下面的语句：
eg:
    char* pvalue = NULL;
    pvalue = new char[20];

    delete []pvalue;    //new搭配delete；new[]搭配delete[]
*/

/*
二维数组eg：
    int **array;
    //假定一维长度为m，二维长度为n
    array = new int* [m];
    for (int i = 0; i < m;i++)
    {
        array[i] = new int [n];
    }
    
    //释放
    for (int i = 0; i < m;i++)
    {
        delete [] array[i];
    }
    delete [] array;

    std::vector<std::vector<int>> a(m, std::vector<int>(n));   // 一行：m 行 n 列，全 0
    使用vector要方便的多    
*/

// #include <iostream>

// int main()
// {
//     int **p;
//     int i,j;// p[4][8]
//     p = new int* [4];
//     for(i = 0;i < 4;i++)
//     {
//         p[i] = new int [8];
//     }

//     for(i=0; i<4; i++){
//         for(j=0; j<8; j++){
//             p[i][j] = j*i;
//         }
//     }   
//     //打印数据   
//     for(i=0; i<4; i++){
//         for(j=0; j<8; j++)     
//         {   
//             if(j==0) std::cout << std::endl;   
//             std::cout<<p[i][j]<<"\t";   
//         }
//     }   
//     //开始释放申请的堆   
//     for(i=0; i<4; i++){
//         delete [] p[i];   
//     }
//     delete [] p;   
//     return 0;
// }

/*
对象的动态内存分配
*/
#include <iostream>

class Box
{
    public:
        Box()
        {
            std::cout << "调用构造函数" <<std::endl;
        }
        ~Box()
        {
            std::cout << "调用析构函数" << std::endl;
        }
};

int main()
{
    Box *array = new Box[4];
    delete [] array;
}