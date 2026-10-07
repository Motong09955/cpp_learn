#include <iostream>
#include <fstream>

/*
对于从文件读取流和向文件写入流这个问题，c++提供了标准库<fstream>,定义了三个新的数据类型
|ofstream|该数据类型表示输出文件流，用于创建文件并向文件写入信息
|ifstream|该数据类型表示输入文件流，用于从文件读取信息
| fstream|该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，这意味着它可以创建文件，向文件写入信息，从文件读取信息
*/

/*
打开文件使用"open"函数
void open(const char *filename,ios::openmode)
其中filename指定打开文件的名称和位置，openmode指定打开文件的模式
|ios::app|追加模式。所有写入都追加到文件末尾
|ios::ate|文件打开后定位到文件末尾
|ios::in|打开文件用于读取
|ios::out|打开文件用于写入
ios::trunc|如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0
可以使用类似"ios::out | ios::trunc"的方式来结合多个模式来使用
*/

//关闭文件使用"close()"函数，close是fstream，ifstream，ofstream对象的一个成员

//具体实例见下

int main()
{  
    char data[100];

    std::ofstream outfile;//定义打开文件的类       
          
    outfile.open("./docx/test.txt");

    std::cout << "Writing to the file" <<std::endl;
    std::cout << "Please input the txt u want to write:" << std::endl;
    std::cin.getline(data , 100);
    //与getline(cin,s)相比，配std::string ，不用给长度，string会自己变长
    //cin.getline()是流对象的成员函数配 char 数组，必须告诉它缓冲大小
    
    outfile << data <<std::endl;//将data的内容写入文件

    std::cout << "Enter your age:" << std::endl;
    std::cin >> data;
    std::cin.ignore();//作用：丢掉输入缓冲区里的一个字符，不写参数时就是丢 1 个
    //敲 25 再按回车时，>> 只把 25 取走，回车留下的换行符 \n 还留在缓冲区里。
    //如果不清理，后面若有 getline 之类的读取，会先读到这个残留的换行——结果就是"还没等你输入，它就读到一个空行"。这是 cin >> 和 getline 混用时的经典坑。
    //ignore() 就是把那个残留字符专门清掉。

    outfile << data << std::endl;
    outfile.close();

    std::ifstream infile;
    infile.open("./docx/test.txt");

    std::cout << "Reading the file " << std::endl;
    infile >> data;

    std::cout << data <<std::endl;

    infile >>data;
    std::cout << data <<std::endl;

    infile.close();

    return 0;
}