/*
 *Banking System Ver 0.6
 *�ۼ���: ������
 *����: ���ڰ��� ���� Ŭ������ �߰�
 */

#include <iostream>
#include <cstring>

using namespace std;

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

class Account
{
private:
	int ID;
	char * name; //�����Ҵ� ����
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

	virtual void deposit(int money)
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
		cout << "����ID: " << ID<< endl;
		cout << "�� ��: " << name << endl;
		cout << "�� ��: " << balance << endl;
	}

	~Account()
	{
		delete[]name;
	}
};
class NormalAccount : public Account
{
private:
	int interRate;
public:
	NormalAccount(int ID, int money, char * name, int rate)
		:Account(ID, name, money), interRate(rate) { }

	void deposit(int money)
	{
		Account::deposit(money);
		Account::deposit(money * (interRate / 100.0));
	}
};

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int ID, int money, char * name, int rate, int special)
		:NormalAccount(ID, money, name, rate), specialRate(special) { }
	void deposit(int money)
	{
		NormalAccount::deposit(money);
		Account::deposit(money * (specialRate / 100.0));
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

	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};

void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccout(void)
{
	int sel;
	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ���" << endl;
	cout << "2. �ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[20];
	int balance;
	int interRate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << endl;

	accArr[accnum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id;
	char name[20];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << "�ſ���(1->A, 2->B, 3->C): "; cin >> creditLevel;
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

	cout << "[�� ��]" << endl;

	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;

	for (int i = 0; i < accnum; i++)
	{
		if (accArr[i]->GetaccID() == id) {
			accArr[i]->deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int id;
	int money;

	cout << "[�� ��]" << endl;

	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;

	for (int i = 0; i < accnum; i++)
	{
		if (accArr[i]->GetaccID() == id) {
			if (accArr[i]->withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;
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

		cout << "����: ";
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
