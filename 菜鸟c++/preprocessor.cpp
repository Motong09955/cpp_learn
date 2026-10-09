/*
预处理指令都是以#开头的指令

#define 预处理
    #define macro-name replacement-text 

    参数宏
    #define macro-name(parameter-list) replacement-text
    eg: #define MIN(a,b) ((a)<(b)?(a):(b))

    条件编译
    #if expression
    #ifdef macro-name
    #ifndef macro-name

#和##运算符
    #运算符：将宏参数转换为字符串
    ##运算符：将两个宏参数连接成一个标记

    #define concat(a,b) a##b
    int main()
    {
        int xy = 100;
        printf("%d\n", concat(x,y)); // 输出100
        return 0;
    }
    
预处理宏
    __FILE__：当前源文件名，会在程序编译时包含当前文件名
    __LINE__：当前行号，会在程序编译时包含当前行号
    __DATE__：编译日期，会在程序编译时包含编译日期，foramt: "Mmm dd yyyy"
    __TIME__：编译时间，会在程序编译时包含编译时间，format: "hh:mm:ss"
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "当前源文件名: " << __FILE__ << endl;
    cout << "当前行号: " << __LINE__ << endl;
    cout << "编译日期: " << __DATE__ << endl;
    cout << "编译时间: " << __TIME__ << endl;

    return 0;
}