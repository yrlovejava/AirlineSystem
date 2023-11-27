#pragma once

#include<stdbool.h>
#ifndef _FUN_H
#define _FUN_H

#define SIZE 20
#define MAX_LEN 100

typedef struct flight_information* flight_info;
struct flight_information {
	char flightNum[SIZE];//飞机编号
	char from[SIZE];//从哪里起飞
	char to[SIZE];//在哪里降落
	char take_off_Time[SIZE];//起飞时间
	char land_Time[SIZE];//降落时间
	float pre_Price;//之前的价格
	float discount;//优惠
	float now_Price;//现在的价格
	int tickets;//剩余票数
	flight_info Next;
};

struct user_information {
	char username[MAX_LEN];//用户姓名
	char id_Number[MAX_LEN];//身份证号码
	char password[MAX_LEN];//密码
	struct flight_information user_info[SIZE];
};

struct admin_information {
	char adminname[MAX_LEN];//管理员姓名
	char id_Number[MAX_LEN];//管理员身份证
	char password[MAX_LEN];//管理员密码
	//管理员没有航班信息
};

//录入航班信息
void input_fight();
//包含文件操作
//判断信息是否完整，如果不完整就不录入


//查询所有航班的信息
int check_all_fights();
//管理员和用户都可以完成


//查找个人的航班信息
void search_myflight();



//修改个人的航班信息
void change_myfligt();
//先判断是否有
//然后先删除，调用delete_myflight,
//再实现添加


//修改整体的航班信息(管理员的范围)
void change_flight();
//同样判断是否有
//先删除，再添加


//用户退票
void delete_myflight();
//先判断是都已经购票
//这里注意需要将飞机票的数量加1


//取消航班(管理员范围)
void delete_flight();
//实际上是对文件的操作


//增加航班(管理员范围)
void add_flight();
//先要判断是否有这个航班，如果没有，才可添加


//既是购票，也是添加
void add_myflight();
//需要显示票价
//设置一个输入(相当于付钱)
//如果输入的数字等于价格，才显示购票成功，否则是购票失败


//注册的只能是用户
void userRegister();
//需要判断身份证的格式，这里可以用正则
//需要验证码，随机生成验证码(这个方法我在后面有定义)


void login();
//输入用户名，判断用户名，不存在直接弹出
//成功后再验证是管理员还是用户
//需要验证码，验证成功后弹出对应的界面
//注意，验证机会只有三次，每一次失败之后需要提醒用户还剩几次机会


//用户界面
void user_interface();
//在里面要写很多函数，可以通过输入数字实现对功能的选择


//管理员界面
void admin_interface();
//同用户界面


//验证用户名，返回值为bool类型
bool checkName();



//验证身份证号码,返回值为bool类型
bool checkIdNumber();



//验证密码,返回值为bool类型
bool checkPassword();



//获取验证码
char* getCode();
//注意是随机获取，5位验证码，包含大小写字母，还有数字，随机排列


int getRandomNumber(int min, int max);
//获取一个随机数，从而在后面的函数得到一位随机字符


char getRandomChar();
//获取验证码的一位字符


void code_free(char* code);
//清空验证码的内存

//验证身份证格式
bool checkIdNumberFormat();

#endif 