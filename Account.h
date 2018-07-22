/*
*Banking System Ver 0.7
*�����̸�: Account.h
*�ۼ���: ������
*����: ���� ����
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int ID;
	char * name; //�����Ҵ� ����
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