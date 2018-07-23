/*
*Banking System Ver 0.7
*�����̸�: Account.cpp
*�ۼ���: ������
*����: ���� ����
*/

#include "Account.h"
#include "BankingCommonDecl.h"


Account::Account(int ID, String name, int money)
	: accID(ID), balance(money)
{
	cusName = name;
}

//Account::Account(int ID, char * name, int money)
//{
//	this->ID = ID;
//	this->balance = money;
//	this->name = new char[strlen(name) + 1];
//	strcpy(this->name, name);
//}
//
//Account::Account(const Account& ref)
//{
//	this->ID = (ref.ID);
//	this->balance = (ref.balance);
//	this->name = new char[strlen(ref.name) + 1];
//	strcpy(this->name, ref.name);
//}
//Account& Account::operator=(const Account& ref)
//{
//	ID = ref.ID;
//	balance = ref.balance;
//
//	delete[]name;
//	name = new char[strlen(ref.name) + 1];
//	strcpy(name, ref.name);
//	return *this;
//}

int Account::Account::GetaccID() const { return accID; }

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
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� ��: " << balance << endl;
}
//
//Account::~Account()
//{
//	delete[]name;
//}

