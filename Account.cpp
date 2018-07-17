/*
 *Banking System Ver 0.1
 *�ۼ���: ������
 *����: OOP �ܰ躰 ������Ʈ�� �⺻ Ʋ ����
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
	cout << "[���°���]" << endl;

	cout << "����ID: ";
	cin >> accArr[accnum].ID;
	cout << "�� ��: ";
	cin >> accArr[accnum].name;
	cout << "�Աݾ�: ";
	cin >> accArr[accnum].balance;

	cout << endl;
	accnum++;
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
		if (accArr[i].ID == id) {
			accArr[i].balance += money;
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
		if (accArr[i].ID == id) {
			if (accArr[i].balance < money)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
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
		cout << "����ID: " << accArr[i].ID << endl;
		cout << "�� ��: " << accArr[i].name << endl;
		cout << "�� ��: " << accArr[i].balance << endl << endl;
	}
}