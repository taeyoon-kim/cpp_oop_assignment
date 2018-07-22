/*
*Banking System Ver 0.7
*파일이름: Account.h
*작성자: 김태윤
*내용: 파일 분할
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int ID;
	char * name; //동적할당 수정
	int balance;
public:
	Account(int ID, char * name, int money);
	Account(const Account& ref);
	int GetaccID() const; 
	virtual void deposit(int money);
	int withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

#endif