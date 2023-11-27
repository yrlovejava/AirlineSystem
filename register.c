#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include"AirlineSystem.h"
int main() {
    login_switch();
    return 0;
}
//修改整体的航班信息(管理员的范围)
void change_flight() ;
	//同样判断是否有
	//先删除，再添加

    //取消航班(管理员范围)
void delete_flight() ;
	//实际上是对文件的操作


//增加航班(管理员范围)
void add_flight() ;
	//先要判断是否有这个航班，如果没有，才可添加


//验证用户名，返回值为bool类型
bool checkName(const char *enteredName, FILE *file) {
    rewind(file);  // 将文件指针移回文件开头
    struct user_information user;
    while (fscanf(file, "%s %s %s", user.username, user.id_Number, user.password)==3) {
        if (strcmp(user.username, enteredName) == 0) {
            return true;  // 找到匹配的用户名
        }
    }
    printf("没有该用户\n");
    return false;  // 未找到匹配的用户名
}



//验证身份证号码,返回值为bool类型
bool checkIdNumber(const char *enteredIdNumber,FILE *file){
    rewind(file);
    struct user_information user;
    while(fscanf(file,"%s %s %s",user.username,user.id_Number,user.password)==3){
        if(strcmp(user.id_Number,enteredIdNumber)==0){
            return true;
        }
        printf("无效身份证号码\n");
        return false;
    }
}



//验证密码,返回值为bool类型
bool checkPassword(const char* enteredPassword,FILE *file){
    rewind(file);
    struct user_information user;
    while(fscanf(file,"%s %s %s",user.username,user.id_Number,user.password)==3){
        if(strcmp(user.password,enteredPassword)==0){
            return true;
        }
        printf("密码错误\n");
        return false;
    }
}


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



void login_switch(){
    int num;
    printf("Enter user type(0 for user, 1 for administrator)\n");
    scanf("%d",&num);
    if(num==0) loginUser();
    else if(num==1) loginAdmin();
    else printf("No such type");    
}

void loginAdmin() {
    FILE *file = fopen("D:\\vscc\\C\\AirlineSystem\\admin_info.txt", "r");

    if (file == NULL) {
        perror("ERROR");
        return;
    }

    char enteredName[MAX_LEN], enteredPassword[MAX_LEN], enteredCode[SIZE];
    char register_code[SIZE];
    strcpy(register_code,getCode());

    printf("Enter username:\n");
    scanf("%s", enteredName);

    if (!checkName(enteredName, file)) {
        printf("Username does not exist.\n");
        fclose(file);
        return;
    }

    // 管理员存在，继续登录过程
    int passwordAttemptsLeft = 3;

    while (passwordAttemptsLeft > 0) {
        printf("Enter password: ");
        scanf("%s", enteredPassword);
        printf("Enter verification code:\n");
        printf("%s\n",register_code);
        scanf("%s",enteredCode);

        if (checkPassword(enteredPassword, file)) {
            // 密码正确，继续输入验证码
            while (1) {
                if (strcmp(enteredCode,register_code)==0) {
                    printf("Verification code correct!\n");
                    printf("Welcome, administrator!\n");
                    // 进入管理员界面
                    fclose(file);
                    return;
                } else {
                    printf("Incorrect verification code.\n");
                    strcpy(register_code,getCode());
                    printf("Enter verification code:\n");
                    printf("%s\n",register_code);
                    scanf("%s",enteredCode);
                }
            }
        } else {
            printf("Incorrect administrator password.\n");
            passwordAttemptsLeft--;

            if (passwordAttemptsLeft > 0) {
                printf("Password attempts left: %d\n", passwordAttemptsLeft);
            } else {
                printf("Password attempts exhausted.\n");
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
}

void loginUser(){
    
    FILE *file = fopen("D:\\vscc\\C\\AirlineSystem\\user_info.txt", "r");

    if (file == NULL) {
        perror("ERROR");
        return;
    }

    char enteredName[MAX_LEN], enteredPassword[MAX_LEN], enteredCode[SIZE];
    char register_code[SIZE];
    strcpy(register_code,getCode());

    printf("Enter username:\n");
    scanf("%s", enteredName);

    if (!checkName(enteredName, file)) {
        printf("Username does not exist.\n");
        fclose(file);
        return;
    }

    // 用户存在，继续登录过程
    int passwordAttemptsLeft = 3;

    while (passwordAttemptsLeft > 0) {
        printf("Enter password: ");
        scanf("%s", enteredPassword);
        printf("Enter verification code:\n");
        printf("%s\n",register_code);
        scanf("%s",enteredCode);

        if (checkPassword(enteredPassword, file)) {
            // 密码正确，继续输入验证码
            while (1) {
                if (strcmp(enteredCode,register_code)==0) {
                    printf("Verification code correct!\n");
                    printf("Welcome, user!\n");
                    // 进入管理员界面
                    fclose(file);
                    return;
                } else {
                    printf("Incorrect verification code.\n");
                    strcpy(register_code,getCode());
                    printf("Enter verification code:\n");
                    printf("%s\n",register_code);
                    scanf("%s",enteredCode);
                }
            }
        } else {
            printf("Incorrect user password.\n");
            passwordAttemptsLeft--;

            if (passwordAttemptsLeft > 0) {
                printf("Password attempts left: %d\n", passwordAttemptsLeft);
            } else {
                printf("Password attempts exhausted.\n");
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
}