#pragma once

#ifndef _FUN_H
#define _FUN_H

#define SIZE 20
#define MAX_LEN 100

typedef struct flight_information *flight_info;
struct flight_information{
	char flightNum[SIZE];//�ɻ����
	char from[SIZE];//���������
	char to[SIZE];//�����ｵ��
	char take_off_Time[SIZE];//���ʱ��
	char land_Time[SIZE];//����ʱ��
	float pre_Price;//֮ǰ�ļ۸�
	float discount;//�Ż�
	float now_Price;//���ڵļ۸�
	int tickets;//ʣ��Ʊ��
	flight_info Next;
};

struct user_information{
	char username[MAX_LEN];//�û�����
	char id_Number[MAX_LEN];//����֤����
	char password[MAX_LEN];//����
	struct flight_information user_info[SIZE];
};

struct admin_information{
	char adminname[MAX_LEN];//����Ա����
	char id_Number[MAX_LEN];//����Ա����֤
	char password[MAX_LEN];//����Ա����
	//����Աû�к�����Ϣ
};

//¼�뺽����Ϣ
void input_fight();
	//�����ļ�����
	//�ж���Ϣ�Ƿ�����������������Ͳ�¼��


//��ѯ���к������Ϣ
void check_all_fights() ;
	//����Ա���û����������


//���Ҹ��˵ĺ�����Ϣ
void search_myflight();



//�޸ĸ��˵ĺ�����Ϣ
void change_myfligt() ;
	//���ж��Ƿ���
	//Ȼ����ɾ��������delete_myflight,
	//��ʵ������


//�޸�����ĺ�����Ϣ(����Ա�ķ�Χ)
void change_flight() ;
	//ͬ���ж��Ƿ���
	//��ɾ����������


//�û���Ʊ
void delete_myflight() ;
	//���ж��Ƕ��Ѿ���Ʊ
	//����ע����Ҫ���ɻ�Ʊ��������1


//ȡ������(����Ա��Χ)
void delete_flight() ;
	//ʵ�����Ƕ��ļ��Ĳ���


//���Ӻ���(����Ա��Χ)
void add_flight() ;
	//��Ҫ�ж��Ƿ���������࣬���û�У��ſ�����


//���ǹ�Ʊ��Ҳ������
void add_myflight() ;
	//��Ҫ��ʾƱ��
	//����һ������(�൱�ڸ�Ǯ)
	//�����������ֵ��ڼ۸񣬲���ʾ��Ʊ�ɹ��������ǹ�Ʊʧ��


//ע���ֻ�����û�
void userRegister() ;
	//��Ҫ�ж�����֤�ĸ�ʽ���������������
	//��Ҫ��֤�룬���������֤��(����������ں����ж���)


void login() ;
	//�����û������ж��û�����������ֱ�ӵ���
	//�ɹ�������֤�ǹ���Ա�����û�
	//��Ҫ��֤�룬��֤�ɹ��󵯳���Ӧ�Ľ���
	//ע�⣬��֤����ֻ�����Σ�ÿһ��ʧ��֮����Ҫ�����û���ʣ���λ���


//�û�����
void user_interface();
	//������Ҫд�ܶຯ��������ͨ����������ʵ�ֶԹ��ܵ�ѡ��


//����Ա����
void admin_interface() ;
	//ͬ�û�����


//��֤�û���������ֵΪbool����
bool checkName() ;



//��֤����֤����,����ֵΪbool����
bool checkIdNumber() ;



//��֤����,����ֵΪbool����
bool checkPassword() ;



//��ȡ��֤��
char* getCode() ;
	//ע���������ȡ��5λ��֤�룬������Сд��ĸ���������֣��������


int getRandomNumber(int min,int max);
	//��ȡһ����������Ӷ��ں���ĺ����õ�һλ����ַ�


char getRandomChar();
	//��ȡ��֤���һλ�ַ�


void code_free(char *code);
	//�����֤����ڴ�

//�������ж�������Ϣ��������һ��˳������

#endif 

