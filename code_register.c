#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include"AirlineSystem.h"

int getRandomNumber(int min,int max){
	//获取一个随机数，从而在后面的函数得到一位随机字符
    return rand()%(max - min + 1) + min;
}
char getRandomChar(){
	//获取一位随机数
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int charset_size = sizeof(charset) - 1;
    return charset[getRandomNumber(0,charset_size)];
}
char* getCode(){
    //注意是随机获取，5位验证码，包含大小写字母，还有数字，随机排列
    srand((unsigned int)time(NULL));
    const int code_length = 5;
    int i;
    char* code = (char*)malloc((code_length + 1)*sizeof(char));  //加1是为了存储'\0'
    for(i=0;i<code_length;i++) code[i] = getRandomChar();
    code[code_length] = '\0';
    return code;
}

void code_free(char *code){
	//清空验证码的内存
    free(code);
}

int main(){
    char *generated_code = getCode();
    printf("%s",generated_code);
    code_free(generated_code);
    return 0;
}
