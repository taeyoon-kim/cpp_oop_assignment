/*
*Banking System Ver 0.7
*파일이름: Account.cpp
*작성자: 김태윤
*내용: 파일 분할
*/

#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(int ID, char * name, int money)
{
	this->ID = ID;
	this->balance = money;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account& ref)
{
	this->ID = (ref.ID);
	this->balance = (ref.balance);
	this->name = new char[strlen(ref.name) + 1];
	strcpy(this->name, ref.name);
}

int Account::Account::GetaccID() const { return ID; }

 void Account::deposit(int money)
{
	balance += money;
}

int Account::withdraw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return 1;

}

void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << ID << endl;
	cout << "이 름: " << name << endl;
	cout << "잔 액: " << balance << endl;
}

Account::~Account()
{
	delete[]name;
}

