/*c++允许在同一作用域中的某个函数和运算符指定多个定义，分别称为函数重载和运算符重载
重载声明是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明，但是它们的参数列表和定义（实现）不相同。
当您调用一个重载函数或重载运算符时，编译器通过把您所使用的参数类型与定义中的参数类型进行比较，决定选用最合适的定义。
选择最合适的重载函数或重载运算符的过程，称为重载决策      */

//=====================================================================
// #include <iostream>

// class PrintData
// {
//     public :
//         void print(int i)
//         {
//             std::cout << "整数为: " << i << std::endl;
//         }
//         void print(double f)
//         {
//             std::cout << "浮点数为: " << f << std::endl;
//         }
//         void print(char c[])
//         {
//             std::cout << "字符串为: " << c << std::endl;
//         }

// };

// int main()
// {
//     PrintData pd;

//     // 调用重载函数
//     pd.print(5);
//     pd.print(500.263);
//     char c[] = "Hello C++";
//     pd.print(c);

//     return 0;    
// }

//============================================================================

/*重载运算符：
重载的运算符是带有特殊名称的函数，函数名由operator关键字和运算符本身组成
eg：Box operator+(const Box& class_name),这里的"&"表示引用*/

/*
可重载的运算符包括：
双目算术运算符|+，-，*，/，%|
关系运算符|==，!=，>，<，>=，<=|
逻辑运算符|&&，||，!|
单目运算符|+(正),-(负)，*(指针)，&(取地址)，++(自增)，--(自减)|
赋值运算符|=，+=，-=，*=，/=，%=|
位运算符|&，|，^，~，<<，>>|
空间申请和释放运算符|new，delete|
其他运算符|()(函数调用),->(成员访问),[](下标),,（逗号）|
不可重载的运算符包括：
范围解析运算符|::|
成员选择运算符|.||
条件运算符|?:|  
sizeof，长度运算符
#，预处理符号
.*,->*，成员指针访问  
运算符

*/

#include <iostream>
using namespace std;
 
class Box
{
   public:
 
      double getVolume(void)
      {
         return length * breadth * height;
      }
      void setLength( double len )
      {
          length = len;
      }
 
      void setBreadth( double bre )
      {
          breadth = bre;
      }
 
      void setHeight( double hei )
      {
          height = hei;
      }
      // 重载 + 运算符，用于把两个 Box 对象相加
      Box operator+(const Box& b)
      {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }
   private:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
};
// 程序的主函数
int main( )
{
   Box Box1;                // 声明 Box1，类型为 Box
   Box Box2;                // 声明 Box2，类型为 Box
   Box Box3;                // 声明 Box3，类型为 Box
   double volume = 0.0;     // 把体积存储在该变量中
 
   // Box1 详述
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // Box2 详述
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
 
   // Box1 的体积
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // Box2 的体积
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;
 
   // 把两个对象相加，得到 Box3
   Box3 = Box1 + Box2;
 
   // Box3 的体积
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;
 
   return 0;
}
