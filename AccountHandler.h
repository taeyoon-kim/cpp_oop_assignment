/*
*Banking System Ver 0.7
*�����̸�: AccountHandler.h
*�ۼ���: ������
*����: ���� ����
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	BoundCheckAccountPtrArray accArr;
	int accnum;
public:
	AccountHandler() : accnum(0) {}
	void ShowMenu(void) const;
	void MakeAccout(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccount(void);

	~AccountHandler()
	{
		for (int i = 0; i < accnum; i++)
			delete accArr[i];
	};

	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};

#endif