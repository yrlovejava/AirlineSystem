#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"AirlineSystem.h"
#include<stdbool.h>

bool checkIdNumberFormat(const char* idNumber) {
	// 检查身份证号码的长度是否为18位
	if (strlen(idNumber) != 18) {
		return false;
	}

	// 检查前17位是否都是数字
	for (int i = 0; i < 17; i++) {
		if (idNumber[i] < '0' || idNumber[i] > '9') {
			return false;
		}
	}

	// 检查最后一位是否是数字或大写字母 'X'
	char lastChar = idNumber[17];
	if ((lastChar < '0' || lastChar > '9') && lastChar != 'X') {
		return false;
	}

	return true;
}

void userRegister(struct user_information* userInfo) {
	//输入要注册的用户名
	printf("Please enter the username you want to register:\n");
	fgets(userInfo->username, MAX_LEN, stdin);
	userInfo->username[strcspn(userInfo->username, "\n")] = '\0';

	//输入身份证号
	printf("Please enter your ID card number:\n ");
	bool validIdNumber = false;
	while (true)
	{
		fgets(userInfo->id_Number, MAX_LEN, stdin);
		userInfo->id_Number[strcspn(userInfo->id_Number, "\n")] = '\0';

		validIdNumber = checkIdNumberFormat(userInfo->id_Number);

		if (!validIdNumber) {
			//身份证格式不正确
			printf("The format of the ID card number is incorrect. Please re-enter it.\n");
		}
		else {
			//身份证格式正确
			printf("The format of the ID card number is correct. Please continue with the next step。\n");
			break;
		}
	}

	//输入八位密码
	printf("Please enter an 8-digit password: \n");
	while (true) {
		fgets(userInfo->password, MAX_LEN, stdin);
		userInfo->password[strcspn(userInfo->password, "\n")] = '\0';
		if (strlen(userInfo->password) != 8) {
			//密码格式错误
			printf("The password format is incorrect. Please re-enter it\n");
		}
		else {
			break;
		}
	}
	//再次确认密码
	printf("Please confirm your password again：\n");
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

	//输入验证码
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