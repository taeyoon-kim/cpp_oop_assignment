/*
*Banking System Ver 0.7
*파일이름: AccountHandler.h
*작성자: 김태윤
*내용: 파일 분할
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