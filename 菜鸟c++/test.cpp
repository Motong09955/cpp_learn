#include<iostream>  
#include <limits>
#include <ctime>
 
/* 
 * 这个程序演示了有符号整数和无符号整数之间的差别
*/
int main()
{
//    short int i;           // 有符号短整数
//    short unsigned int j;  // 无符号短整数
 
//    j = 50000;
 
//    i = j;
//    std::cout << i << " " << j;
//    std::cout << std::endl;

    // int d = 10;   //  测试自增、自减

    // int c = d++;
    // std::cout << "Line 6 - c 的值是 " << c << std::endl ;
    // std::cout << "Line 6 - d 的值是 " << d << std::endl ;
       // 基于当前系统的当前日期/时间
//    time_t now = time(0);
   
//    // 把 now 转换为字符串形式
//    char* dt = ctime(&now);
 
//    std::cout << "本地日期和时间：" << dt << std::endl;
 
//    // 把 now 转换为 tm 结构
//    tm *gmtm = gmtime(&now);
//    dt = asctime(gmtm);
//    std::cout << "UTC 日期和时间："<< dt << std::endl;
//    return 0;

    time_t now = time(0);
 
    std::cout << "1970 到目前经过秒数:" << now << std::endl;

    tm *ltm = localtime(&now);

    // 输出 tm 结构的各个组成部分
    std::cout << "年: "<< 1900 + ltm->tm_year << std::endl;
    std::cout << "月: "<< 1 + ltm->tm_mon<< std::endl;
    std::cout << "日: "<<  ltm->tm_mday << std::endl;
    std::cout << "时间: "<< ltm->tm_hour << ":";
    std::cout << ltm->tm_min << ":";
    std::cout << ltm->tm_sec << std::endl;
}