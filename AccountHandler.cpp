/*
*Banking System Ver 0.7
*파일이름: AccountHandler.cpp
*작성자: 김태윤
*내용: 파일 분할
*/

#include"AccountHandler.h"
#include"BankingCommonDecl.h"
#include "Account.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"
#include "string.h"

void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccout(void)
{
	int sel;
	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌" << endl;
	cout << "2. 신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	//char name[20];
	String name;
	int balance;
	int interRate;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << endl;

	accArr[accnum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id;
	//char name[20];
	String name;
	int balance;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << "신용등급(1->A, 2->B, 3->C): "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accnum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accnum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accnum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}

void AccountHandler::DepositMoney(void)
{
	int id;
	int money;

	cout << "[입 금]" << endl;

	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;

	for (int i = 0; i < accnum; i++)
	{
		if (accArr[i]->GetaccID() == id) {
			accArr[i]->deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다" << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int id;
	int money;

	cout << "[출 금]" << endl;

	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;

	for (int i = 0; i < accnum; i++)
	{
		if (accArr[i]->GetaccID() == id) {
			if (accArr[i]->withdraw(money) == 0)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다" << endl << endl;
}

void AccountHandler::ShowAllAccount(void)
{
	for (int i = 0; i < accnum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}