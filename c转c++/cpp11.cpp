#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    auto x=13;
    auto y=13.333;//使用auto直接推断变量类型，不能用于输入
    cout <<"x="<<x<<endl;
    cout << "y=" << y << endl;
    //用于迭代器，前面已经写了，这里不想在写一遍了
    //stl中部分的可以用迭代器，vector,set,map

    //for循环的传值与传址
    
    return 0;
}