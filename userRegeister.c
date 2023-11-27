#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"AirlineSystem.h"
#include<stdbool.h>

bool checkIdNumberFormat(const char* idNumber) {
	// ������֤����ĳ����Ƿ�Ϊ18λ
	if (strlen(idNumber) != 18) {
		return false;
	}

	// ���ǰ17λ�Ƿ�������
	for (int i = 0; i < 17; i++) {
		if (idNumber[i] < '0' || idNumber[i] > '9') {
			return false;
		}
	}

	// ������һλ�Ƿ������ֻ��д��ĸ 'X'
	char lastChar = idNumber[17];
	if ((lastChar < '0' || lastChar > '9') && lastChar != 'X') {
		return false;
	}

	return true;
}

void userRegister(struct user_information* userInfo) {
	//����Ҫע����û���
	printf("Please enter the username you want to register:\n");
	fgets(userInfo->username, MAX_LEN, stdin);
	userInfo->username[strcspn(userInfo->username, "\n")] = '\0';

	//�������֤��
	printf("Please enter your ID card number:\n ");
	bool validIdNumber = false;
	while (true)
	{
		fgets(userInfo->id_Number, MAX_LEN, stdin);
		userInfo->id_Number[strcspn(userInfo->id_Number, "\n")] = '\0';

		validIdNumber = checkIdNumberFormat(userInfo->id_Number);

		if (!validIdNumber) {
			//���֤��ʽ����ȷ
			printf("The format of the ID card number is incorrect. Please re-enter it.\n");
		}
		else {
			//���֤��ʽ��ȷ
			printf("The format of the ID card number is correct. Please continue with the next step��\n");
			break;
		}
	}

	//�����λ����
	printf("Please enter an 8-digit password: \n");
	while (true) {
		fgets(userInfo->password, MAX_LEN, stdin);
		userInfo->password[strcspn(userInfo->password, "\n")] = '\0';
		if (strlen(userInfo->password) != 8) {
			//�����ʽ����
			printf("The password format is incorrect. Please re-enter it\n");
		}
		else {
			break;
		}
	}
	//�ٴ�ȷ������
	printf("Please confirm your password again��\n");
	while (true) {
		char confirmPassword[MAX_LEN];
		fgets(confirmPassword, MAX_LEN, stdin);
		confirmPassword[strcspn(confirmPassword, "\n")] = '\0';
		if (!strcmp(userInfo->password, confirmPassword) == 0) {
			printf("The passwords entered twice are different. Please enter them again\n");
		}
		else {
			printf("Password verification successful\n");
			break;
		}
	}

	//������֤��
	printf("Please enter the verification code\n");
	while (true) {
		char code[MAX_LEN];
		srand((unsigned int)time(NULL));
		char* generated_code = getCode();
		printf("%s", generated_code);
		fgets(code, MAX_LEN, stdin);
		code_free(generated_code);
		if (!strcmp(code, generated_code) == 0) {
			printf("Incorrect verification code. Please re-enter it");
		}
		else {
			printf("Registration successful");
			break;
		}
	}
}

int main() {
	struct user_information user;

	userRegister(&user);

	printf("Username: %s\n", user.username);
	printf("ID card number: %s\n", user.id_Number);
	printf("Password: %s\n", user.password);

	return 0;
}