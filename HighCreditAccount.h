/*
*Banking System Ver 0.7
*�����̸�: HighCreditAccount.h
*�ۼ���: ������
*����: ���� ����
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int ID, int money, char * name, int rate, int special)
		:NormalAccount(ID, money, name, rate), specialRate(special) { }
	virtual void deposit(int money)
	{
		NormalAccount::deposit(money);
		Account::deposit(money * (specialRate / 100.0));
	}

};

#endif __HIGHCREDIT_ACCOUNT_H__