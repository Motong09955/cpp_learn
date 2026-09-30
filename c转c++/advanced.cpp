#include <iostream>
using namespace std;

// #include<bitset>
// int main(void)
// {
//     //位运算，存储时，数组的低位对应二进制的低位
//     bitset <6> b(28);//表示长度为6的二进制数
//     bitset <5> b1("11");//表示b1的最低两位为11
//     cout << b << endl;
//     cout << b1 << endl;
//     for (int i=0;i<b.size();i++)
//         cout<<b[i]<<" ";
//     cout << endl;
//     cout << "b中是否有1："<<b.any()<<endl;
//     cout << "b中是否不存在1:" << b.none() <<endl;
//     cout << "b中1的个数：" << b.count() <<endl;
//     cout << "b中元素个数/b的长度：" << b.size() << endl;
//     cout << "下标为1的元素是不是1:" << b.test(1) << endl;
//     b.flip(1);//对b的第i位进行取反,括号内不加元素则表示全部位取反
//     cout << b << endl;
//     b.flip();
//     cout << b << endl;
//     b.reset(0);//对b的第i位取0，括号内不带元素则表示全部取0
//     cout << b << endl;
//     b.reset();
//     cout << b << endl;
//     b.set(4);
//     unsigned long a = b.to_ullong();//将b转为无符号长整型
//     cout << a << endl;
//     return 0;
// }

// #include<algorithm>
// #include <vector>
// // bool cmp(int x,int y)
// // {
// //     return x>y;//返回值为假则交换
// // }
// // int main(void)
// // {
// //     //sort排序，可以自定义cmp函数来定义排列规则
// //     vector <int> a;
// //     vector <int> a1;
// //     for(int i=10;i>=0;i--)
// //         a.push_back(i);
// //     for(int i=10;i>=0;i--)
// //         a1.push_back(10-i);
// //     cout <<"a的原始排列：";
// //     for (auto p=a.begin();p!=a.end();p++)
// //         cout  << *p <<" ";
// //     cout <<endl;
// //     sort(a.begin(),a.end());//明确要对数组的哪一部分进行排序，默认按照从小到大排序，左闭右开
// //     cout <<"a sort后的排列：";
// //     for (auto p=a.begin();p!=a.end();p++)
// //         cout << *p <<" ";
// //     cout <<endl;
// //     cout <<"a1的原始排列：";
// //     for (auto p=a1.begin();p!=a1.end();p++)
// //         cout  << *p <<" ";
// //     cout << endl;
// //     sort(a1.begin(),a1.end(),cmp);
// //     cout <<"a1 sort后的排列：";
// //     for (auto p=a1.begin();p!=a1.end();p++)
// //         cout << *p <<" ";
// //     cout <<endl;
// //     return 0;
// // }
// struct stu{
//     string name;
//     int age;
// };
// bool cmp(stu a,stu b)
// {
//     if (a.age!=b.age)
//         return a.age<b.age;
//     else
//         return a.name<b.name;
// }
// int main(void)
// {
//     stu s[3];
//     for(int i=0;i<3;i++)
//         cin >> s[i].name >>s[i].age;
//     sort(s,s+3,cmp);
//     cout << "排序后结果："<< endl;
//     for(int i=0;i<3;i++)
//         cout << s[i].name <<" " << s[i].age << endl;
//     return 0;
// }


#include<cctype>
int main(void)
{
    //ctype类型使用
    //要用的时候再看吧
    return 0;
}