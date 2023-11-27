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
//�޸�����ĺ�����Ϣ(����Ա�ķ�Χ)
void change_flight() ;
	//ͬ���ж��Ƿ���
	//��ɾ���������

    //ȡ������(����Ա��Χ)
void delete_flight() ;
	//ʵ�����Ƕ��ļ��Ĳ���


//���Ӻ���(����Ա��Χ)
void add_flight() ;
	//��Ҫ�ж��Ƿ���������࣬���û�У��ſ����


//��֤�û���������ֵΪbool����
bool checkName(const char *enteredName, FILE *file) {
    rewind(file);  // ���ļ�ָ���ƻ��ļ���ͷ
    struct user_information user;
    while (fscanf(file, "%s %s %s", user.username, user.id_Number, user.password)==3) {
        if (strcmp(user.username, enteredName) == 0) {
            return true;  // �ҵ�ƥ����û���
        }
    }
    printf("û�и��û�\n");
    return false;  // δ�ҵ�ƥ����û���
}



//��֤���֤����,����ֵΪbool����
bool checkIdNumber(const char *enteredIdNumber,FILE *file){
    rewind(file);
    struct user_information user;
    while(fscanf(file,"%s %s %s",user.username,user.id_Number,user.password)==3){
        if(strcmp(user.id_Number,enteredIdNumber)==0){
            return true;
        }
        printf("��Ч���֤����\n");
        return false;
    }
}



//��֤����,����ֵΪbool����
bool checkPassword(const char* enteredPassword,FILE *file){
    rewind(file);
    struct user_information user;
    while(fscanf(file,"%s %s %s",user.username,user.id_Number,user.password)==3){
        if(strcmp(user.password,enteredPassword)==0){
            return true;
        }
        printf("�������\n");
        return false;
    }
}


int getRandomNumber(int min,int max){
	//��ȡһ����������Ӷ��ں���ĺ����õ�һλ����ַ�
    return rand()%(max - min + 1) + min;
}
char getRandomChar(){
	//��ȡһλ�����
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int charset_size = sizeof(charset) - 1;
    return charset[getRandomNumber(0,charset_size)];
}
char* getCode(){
    //ע���������ȡ��5λ��֤�룬������Сд��ĸ���������֣��������
    srand((unsigned int)time(NULL));
    const int code_length = 5;
    int i;
    char* code = (char*)malloc((code_length + 1)*sizeof(char));  //��1��Ϊ�˴洢'\0'
    for(i=0;i<code_length;i++) code[i] = getRandomChar();
    code[code_length] = '\0';
    return code;
}

void code_free(char *code){
	//�����֤����ڴ�
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

    // ����Ա���ڣ�������¼����
    int passwordAttemptsLeft = 3;

    while (passwordAttemptsLeft > 0) {
        printf("Enter password: ");
        scanf("%s", enteredPassword);
        printf("Enter verification code:\n");
        printf("%s\n",register_code);
        scanf("%s",enteredCode);

        if (checkPassword(enteredPassword, file)) {
            // ������ȷ������������֤��
            while (1) {
                if (strcmp(enteredCode,register_code)==0) {
                    printf("Verification code correct!\n");
                    printf("Welcome, administrator!\n");
                    // �������Ա����
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

    // �û����ڣ�������¼����
    int passwordAttemptsLeft = 3;

    while (passwordAttemptsLeft > 0) {
        printf("Enter password: ");
        scanf("%s", enteredPassword);
        printf("Enter verification code:\n");
        printf("%s\n",register_code);
        scanf("%s",enteredCode);

        if (checkPassword(enteredPassword, file)) {
            // ������ȷ������������֤��
            while (1) {
                if (strcmp(enteredCode,register_code)==0) {
                    printf("Verification code correct!\n");
                    printf("Welcome, user!\n");
                    // �������Ա����
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