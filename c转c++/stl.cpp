/*
stl中的类型大小可以用size来获取
*/

#include <iostream>


using namespace std;

// #include <vector>//引入 向量or可变数组
// int main(void)
// {
//     vector <int> v(10,2);
//     vector <int> v1;
//     vector <int> v2(10);//vector中元素值默认为0，括号内第一个元素指定vector空间长度，第二个元素指定默认元素值
//     cout<<v.size()<<endl;
//     for(int i = 0;i<v.size();i++)
//         cout<<v[i]<<" ";//使用[]访问vector中元素
//     v.resize(6);//vector定义后重新指定大小
//     cout<<"v resize后的空间：";
//     for(int i;i<v.size();i++)
//         cout << v[i]<<" ";
//     cout<<endl;
//     cout<<v.size()<<endl;
//     cout<<"v1的值：";
//     for(int i;i<v2.size();i++)
//         cout << v2[i];
//     cout<<endl;
//     v2.push_back(5);//在vector末尾添加元素
//     for(int i;i<v2.size();i++)
//         cout << v2[i];
//     cout << endl;
//     for(auto p=v.begin();p!=v.end();p++)
//         cout << *p << "  ";//这里应该是用指针来取地址
//     //不知道vector内具体内容时可以用这种方法遍历
//     return 0;
// }

// #include<set>
// int main(void)
// {
//     //set表示集合，一般情况下会自动对内容进行排序
//     set <int> a;//不能在开始时就赋予a空间长度：set <int> a(10)❌
//     a.insert(2);
//     a.insert(4);
//     a.insert(1);
//     for (auto p=a.begin();p!=a.end();p++)
//         cout<<*p<<" ";
//     cout<<endl;
//     cout <<(a.find(2) != a.end())<<endl;
//     cout << (a.find(1) != a.begin()) << endl;//find的返回值是一个指针，递增搜索
//     a.erase(3);//删除元素，不存在的元素也可以填入，不报错
//     for (auto p=a.begin();p!=a.end();p++)
//         cout<<*p<<" ";
//     cout<<endl;
//     return 0;
// }

// #include <map>
// int main(void)
// {
//     //map: 键值对，会自动将所有的键值对按照键从小到大排序
//     map <string,int> m;//创建键值对，第一个表示键的类型，第二个表示值的类型
//     m["hello"]=2;
//     m["ros2"] = 66;//添加键值对
//     m["first"] = 99;
//     cout << "ros2:"" " << m["ros2"] << endl;
//     for(auto p=m.begin();p!=m.end();p++)
//         cout<<p->first <<": "<<p->second<<endl;//迭代器访问键值对
//     cout<<m.size()<<endl;
//     return 0;
// }\

// #include <stack>
// int main(void)
// {
//     //栈FILO
//      ========================
//       1 2  4  5 6 7 7 8 8  ||
//      ========================
//     stack <int> s;
//     s.push(1);//压栈
//     s.push(12);
//     s.push(41);
//     cout<<s.top()<<endl;//栈只能访问栈顶元素
//     s.pop();
//     cout<<s.top()<<endl;
//     s.push(3);
//     s.push(5);
//     cout<<s.size()<<endl;
//     //无法在不取出栈顶的情况下使用“begin”,"end"等迭代器操作
//     return 0;
// }

// #include<queue>
// int main(void)
// {
//     //队列FIFO\
//     // ========================
//     // 1 2  4  5 6 7 7 8 8  2 4
//     // ========================
//     queue <int> q;
//     q.push(1);
//     q.push(3);
//     q.push(5);
//     for(int i=0;i<10;i=i+2)
//         q.push(i);
//     cout << "队首： " << q.front()<<endl;//访问队首
//     cout << "队尾： "<< q.back() << endl;//访问队尾
//     q.pop();
//     cout << "队首： " << q.front()<<endl;//访问队首
//     return 0;
// }

//unordered_map   
//unordered_set
//无序map与set，引用头文件<unordered_map>,<unordered_set>即可，可以减少程序运行时间