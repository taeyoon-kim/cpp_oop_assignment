/*
 *Banking System Ver 0.1
 *작성자: 김태윤
 *내용: OOP 단계별 프로젝트의 기본 틀 구성
 */

#include<iostream>

using namespace std;

void ShowMenu(void);
void MakeAccout(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccount(void);

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
	int ID;
	char name[20];
	int balance;
}Account;

Account accArr[100];
int accnum = 0;

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();

		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccout();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccount();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccout(void)
{
	cout << "[계좌개설]" << endl;

	cout << "계좌ID: ";
	cin >> accArr[accnum].ID;
	cout << "이 름: ";
	cin >> accArr[accnum].name;
	cout << "입금액: ";
	cin >> accArr[accnum].balance;

	cout << endl;
	accnum++;
}

void DepositMoney(void)
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
		if (accArr[i].ID == id) {
			accArr[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다" << endl << endl;
}

void WithdrawMoney(void)
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
		if (accArr[i].ID == id) {
			if (accArr[i].balance < money)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다" << endl << endl;
}

void ShowAllAccount(void)
{
	for (int i = 0; i < accnum; i++)
	{
		cout << "계좌ID: " << accArr[i].ID << endl;
		cout << "이 름: " << accArr[i].name << endl;
		cout << "잔 액: " << accArr[i].balance << endl << endl;
	}
}