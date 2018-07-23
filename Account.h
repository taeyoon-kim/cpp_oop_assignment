/*
*Banking System Ver 0.7
*파일이름: Account.h
*작성자: 김태윤
*내용: 파일 분할
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include"string.h"

class Account
{
private:
	int accID;
	String cusName; //동적할당 수정
	int balance;
public:
	//Account(int ID, char * name, int money);
	Account(int ID, String name, int money);
	//Account(const Account& ref);
	//Account& operator=(const Account& ref);

	int GetaccID() const; 
	virtual void deposit(int money);
	int withdraw(int money);
	void ShowAccInfo() const;
	//~Account();
};

#endif