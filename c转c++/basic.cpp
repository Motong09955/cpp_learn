#include <iostream>//标准输入输出流

#include <cstring>
#include<cmath>//调用c中函数库在名字前加个c就可以

using namespace std;//名称空间

struct stu{
    string name;
    int age;
};

int main(void)
{
    // int n=3;
    // const int MAX = 150;//const量不可改变
    // // MAX = 100;

    // bool flag1 = true;//新增bool类型变量，非0值就认为是1
    // bool flag2 = -1;
    // bool flag3 = 0;
    // cout<<flag1<<endl;
    // cout<<flag2<<endl;
    // cout<<flag3<<endl;

    // cin >> n;    //输入，相当于scanf
    // cout<<"hello，c++!"<<++n<<endl;//输出，使用多个“<<”可以进行多个内容的输出
    // cout<<"wohaoshuai"<<"\n";//endl相当于“"\n"”

    // for(int i;i<10;i++)//可以直接在for循环中定义变量i
    // {
    //     cout<<n<<endl;
    // }

    // string s ="hello ";//string类
    // string s2 = "world!";
    // string s3 = s + s2;
    // cout << s3 << endl;

    // cin >> s;//cin只能用于输入没有空格的内容
    // cout << s << endl;

    // getline(cin,s);//getline用于获取一整句
    // // string s_sub=s.substr(4,2) ;//substr的两个参数（m,n），m用来指定起始位置，n用来指定截取长度，不指定n表示m以后全部截取
    // string s_sub=s.substr(4) ;
    // cout << s_sub << endl;
    // cout << s.length() << endl;//面向对象编程，获取字符串长度,全角“，”占3个位

    // stu a[10];//c++中使用定义结构体不用声明“struct”
    

    return 0;
}