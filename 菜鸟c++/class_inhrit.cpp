#include <iostream>

/*派生类定义方式：
clas  derived-class access-specifier base-class
其中base-class可以有多个，称为多重继承，access-specifier可以是public、protected或private，表示继承方式。
1. public继承：基类的public成员和protected成员在派生类中仍然保持其访问权限，public成员在派生类中仍然是public，protected成员在派生类中仍然是protected，private成员在派生类中不可访问
2. protected继承：基类的public成员和protected成员在派生类中都变为protected，private成员在派生类中不可访问
3. private继承：基类的public成员和protected成员在派生类中都变为private，private成员在派生类中不可访问
*/
//一个基类继承了所有的基类方法，但是不包括以下情况：
//一，基类的构造函数、析构函数和拷贝构造函数不能被继承
//二，基类的友元函数不能被继承
//三，基类的重载运算符不能被继承



// 基类
// class Shape 
// {
//    public:
//       void setWidth(int w)
//       {
//          width = w;
//       }
//       void setHeight(int h)
//       {
//          height = h;
//       }
//    protected:
//       int width;
//       int height;
// };
 
// // 派生类
// class Rectangle: public Shape
// {
//    public:
//       int getArea()
//       { 
//          return (width * height); 
//       }
// };
 
// int main(void)
// {
//    Rectangle Rect;
 
//    Rect.setWidth(5);
//    Rect.setHeight(7);
 
//    // 输出对象的面积
//    std::cout << "Total area: " << Rect.getArea() << std::endl;
 
//    return 0;
// }


/*多继承*/
#include <iostream>
 
using namespace std;
 
// 基类 Shape
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};
 
// 基类 PaintCost
class PaintCost 
{
   public:
      int getCost(int area)
      {
         return area * 70;
      }
};
 
// 派生类
class Rectangle: public Shape, public PaintCost
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};
 
int main(void)
{
   Rectangle Rect;
   int area;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
 
   area = Rect.getArea();
   
   // 输出对象的面积
   cout << "Total area: " << Rect.getArea() << endl;
 
   // 输出总花费
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;
 
   return 0;
}