#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "AirlineSystem (1).h"

int check_all_figlhts()
{
    SetConsoleOutputCP(65001);// �����ַ������ʽ����ֹ�������ʱ�������
    FILE *fp;
    char ch;

    fp = fopen("Flight information.txt", "r"); // ��.txt�ļ�����ֻ��ģʽ<--------------------------------------���ö�ȡ�ļ���λ��

    if (fp == NULL) { // �ж��ļ��Ƿ�ɹ���
        printf("�޷����ļ�\n");
        return 1;
    }
    
    

    while ((ch = fgetc(fp)) != EOF) { // ʹ��fgetc���������ȡ�ļ��е��ַ���ֱ���ļ�����
        printf("%c", ch); // ��ӡ��ȡ�����ַ�
    }

    fclose(fp); // �ر��ļ�
    system("pause");
    
    return 0;
}
int main()
{
    check_all_figlhts();
    return 0;
}