/*
*Banking System Ver 0.7
*�����̸�: NormalAccount.h
*�ۼ���: ������
*����: ���� ����
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
	int interRate;
public:
	NormalAccount(int ID, int money, char * name, int rate)
		:Account(ID, name, money), interRate(rate) { }

	virtual void deposit(int money)
	{
		Account::deposit(money);
		Account::deposit(money * (interRate / 100.0));
	}
};

#endif __NORMAL_ACCOUNT_H__