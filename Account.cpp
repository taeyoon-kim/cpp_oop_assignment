/*
 *Banking System Ver 0.3
 *�ۼ���: ������
 *����: Account Ŭ���� ����, ��ü ������ �迭 ����
 */

#include <iostream>
#include <cstring>

using namespace std;

void ShowMenu(void);
void MakeAccout(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccount(void);

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

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
		this->name = new char[strlen(name)];
		strcpy(this->name, name);
	}

	Account(const Account& ref)
	{
		this->ID = (ref.ID);
		this->balance = (ref.balance);
		this->name = new char[strlen(ref.name) + 1];
		strcpy(this->name, ref.name);
	}

	int GetaccID() { return ID; }

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
	
	void ShowAccInfo()
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

Account * accArr[100];
int accnum = 0;

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();

		cout << "����: ";
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccout(void)
{
	int id;
	char name[20];
	int balance;

	cout << "[���°���]" << endl;

	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << endl;

	accArr[accnum++] = new Account(id, name, balance);
}

void DepositMoney(void)
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

void WithdrawMoney(void)
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

void ShowAllAccount(void)
{
	for (int i = 0; i < accnum; i++)
	{
		accArr[i]->ShowAccInfo();
	}
}