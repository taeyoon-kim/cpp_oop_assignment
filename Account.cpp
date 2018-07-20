/*
 *Banking System Ver 0.5
 *작성자: 김태윤
 *내용: Account 클래스 정의, 객체 포인터 배열 적용
 */

#include <iostream>
#include <cstring>

using namespace std;

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
	int ID;
	char * name; //동적할당 수정
	int balance;
public:
	Account(int ID, char * name, int money)
	{
		this->ID = ID;
		this->balance = money;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	Account(const Account& ref)
	{
		this->ID = (ref.ID);
		this->balance = (ref.balance);
		this->name = new char[strlen(ref.name) + 1];
		strcpy(this->name, ref.name);
	}

	int GetaccID() const { return ID; }

	void deposit(int money)
	{
		balance += money;
	}

	int withdraw(int money)
	{
		if (balance < money)
			return 0;

		balance -= money;
		return 1;
		
	}
	
	void ShowAccInfo() const
	{
		cout << "계좌ID: " << ID<< endl;
		cout << "이 름: " << name << endl;
		cout << "잔 액: " << balance << endl;
	}

	~Account()
	{
		delete[]name;
	}
};

class AccountHandler
{
private:
	Account * accArr[100];
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
};

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
	int id;
	char name[20];
	int balance;

	cout << "[계좌개설]" << endl;

	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << endl;

	accArr[accnum++] = new Account(id, name, balance);
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

int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();

		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccout();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccount();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}
