#include <iostream>
#include <locale.h>
#include "class_spisok.h"
using namespace std;

int menu(List& lst, int metk);
int main()
{
	setlocale(LC_ALL, "Russian");

	List lst1;
	List lst2;
	
	cout<<"���������� ������:\n";
	while (true)
	{
		int flag = 0;
		flag = menu(lst1,1);
		if (flag == 1)
		{
			flag = menu(lst2,2);		
		}
		if (flag == 0)
			return 0;
		if (flag == 2)
		{
			lst1.clear_not_lis2(lst2);
			cout<<"� 1 ������ �������� ��������:\n";
			lst1.Show();
		}
	}
}

int menu(List& lst, int metk)
{
	int otv, otv2;
	int elem;
	int num, n;
	int res;
	bool k,b;

	while (true)
	{
		cout<<"\n1.���������� �������� � ������ ������\n";
		cout<<"2.���������� �������� � ����� ������\n";
		cout<<"3.���������� �������� �� � ������� ������\n";
		cout<<"4.�������� �������� �� ������ ������\n";
		cout<<"5.�������� �������� �� ����� ������\n";
		cout<<"6.�������� �������� �� � ������� ������\n";
		cout<<"7.�������� ������\n";
		cout<<"8.����� ��������� ������ �� ��������\n";
		cout<<"9.����� �������� ������ �� ������\n";
		cout<<"10.����� ��������� ������ �� �����\n";
		cout<<"11.������� �������� ������ � �������� ����� ���������� ���������\n";
		if (metk == 1)
			cout<<"12.������� ����� ������ � ������� �� �������� �� ��������,\n������� ��� �� ������\n";
		else
			cout<<"12.��������� ���������� ������� ������\n";
		cout<<"13.�����\n";
		cin>>otv;
		cin.clear();
		cin.sync();

		switch (otv)
		{
		case 1:
			cout<<"������� �������: ";
			cin>>elem;
			cin.clear();
			cin.sync();
			lst.Add_start(elem);
			cout<<"\n������� �������� � ������ ������\n";
			break;
		case 2:
			cout<<"������� �������: ";
			cin>>elem;
			cin.clear();
			cin.sync();
			lst.Add_end(elem);
			cout<<"\n������� �������� � ����� ������\n";
			break;
		case 3:
			cout<<"������� ������� ��� ���������� �������� � ������: ";
			cin>>num;
			cin.clear();
			cin.sync();
			cout<<"\n������� �������: ";
			cin>>elem;
			cin.clear();
			cin.sync();
			lst.Add_num(elem, num);
			cout<<"\n������� �������� � ������ �� ������� �"<<num<<"\n";
			break;
		case 4:
			k = true;
			res = lst.Del_start(&k);
			if (k)
				cout<<"������ ������� �� ��������� "<<res<<" ����� �� ������\n";
			else
				cout<<"������� ������ �� ���������\n";
			break;
		case 5:
			k = true;
			res = lst.Del_end(&k);
			if (k)
				cout<<"��������� ������� �� ��������� "<<res<<" ����� �� ������\n";
			else
				cout<<"������� ������ �� ���������\n";
			break;		
		case 6:
			cout<<"������� ������� ��� �������� �������� �� ������: ";
			cin>>num;
			cin.clear();
			cin.sync();
			k = true;
			elem = lst.Del_num(num,&k);
			if (k)
				cout<<"\n������� �"<<num<<" �� ��������� "<<elem<<" ����� �� ������\n";
			else
				cout<<"������� ������ �� ���������\n";
			break;
		case 7:
			lst.Clear();
			cout<<"������ ������\n";
			break;
		case 8:
			cout<<"������� ������� ��������: ";
			cin>>elem;
			cin.clear();
			cin.sync();
			cout<<"\n������� ��������� � ������� ���������:\n";
			k = true;
			lst.Find(elem, &k);
			if(!k)
				cout<<"��������� � ������ ��������� �� �������\n";
			break;
		case 9:
			cout<<"������� ����� � ������ ������� ��������: ";
			cin>>num;
			cin.clear();
			cin.sync();
			cout<<"\n�������� �������� ��������:\n";
			lst.Show_number(num);
			break;
		case 10:
			cout<<"� ������ ����������� ��������� ��������:\n";
			k = lst.Show();
			break;
		case 11:
			cout<<"� ������ ����������� ��������� ��������:\n";
			k = lst.Show();
			if (k)
			{
				b = true;
				n = lst.del_often(&b);
				if(b)
					cout<<"�������� � �������� ����� ���������� ���������: "<<n<<" �������\n";
				else
					cout<<"������ ����\n";
			}
			break;
		case 12:
			if (metk == 1)
			{
				cout<<"�� ��������� ������ 1?(1/0)\n";
				cin>>otv2;
				if (otv2 == 1)
					return 1;
			}
			else if (metk == 2)
			{
				cout<<"�� ��������� ������ 2?(1/0)\n";
				cin>>otv2;
				if (otv2 == 1)
					return 2;
			}
			break;
		case 13:
			return 0;
		default: break;
		}
	}
}