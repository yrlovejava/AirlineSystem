#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "AirlineSystem (1).h"

int check_all_figlhts()
{
    SetConsoleOutputCP(65001);// 更改字符编码格式，防止输出中文时变成乱码
    FILE *fp;
    char ch;

    fp = fopen("Flight information.txt", "r"); // 打开.txt文件，以只读模式<--------------------------------------设置读取文件的位置

    if (fp == NULL) { // 判断文件是否成功打开
        printf("无法打开文件\n");
        return 1;
    }
    
    

    while ((ch = fgetc(fp)) != EOF) { // 使用fgetc函数逐个读取文件中的字符，直到文件结束
        printf("%c", ch); // 打印读取到的字符
    }

    fclose(fp); // 关闭文件
    system("pause");
    
    return 0;
}
int main()
{
    check_all_figlhts();
    return 0;
}