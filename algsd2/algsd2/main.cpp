#include <iostream>//cout,cin
#include <locale.h>//������������ ������ � �������

using namespace std;//����������� ������������ ���

int singlesort();//������ �����
int statdata(); //������ �����

int main()//����� ����� � ���������
{
	setlocale(LC_ALL,"Russian");//������������ �������

	bool flag = true;
	char otv;

	//���� ������ ���������
	while (flag)
	{
		cout<<"����:\n";
		cout<<"1.���������� �������\n2.���������� ����������\n3.�����\n";
		
		cin>>otv;		
		cin.clear();
		cin.sync();

		switch(otv)
		{
		case '1'://����� ������� ������ ���������
			singlesort();
			break;
		case '2'://����� ������� ������ ���������
			statdata();
			break;
		case '3'://����� �� ���������
			flag=false;
			break;
		default: flag=true;
		}
		cin.clear();
		cin.sync();
		cout<<"\n";
	}

	return 0;//������� �� �������
}