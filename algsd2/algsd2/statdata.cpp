#include <iostream>//cout,cin
#include <stdlib.h>//����������� ����������
#include <time.h>//������ �� ��������
#include <locale.h>//������������ �������
#include <ctime>//clock()

using namespace std;//����������� ������������ ���


void multiphase(int*arr, long size, int* reversion, int* checks);//������� ����������
int vsort(char* Fname,int* reversion, int* checks);

void zap(int *arr, int size, char metk);
void write_file(int n, char flag);
//������ �����
int statdata()
{
/*	setlocale(LC_ALL,"Russia");//������������
	srand(time(0));//������ ������� ������� � ����

	bool flag1 = true, flag = true, flag2 = true;
	char otv_sp, otv_method;
	int RangeStart,RangeEnd, step, reversion, checks, n;
	unsigned int start_time, end_time;
	double serch_time; 
	char str[45];
	
	//������ ���������� �������
	while(flag1)
	{
		cout<<"������� ������ ���������� �������\n";
		cout<<"1.���������� ����������\n2.� ������� �����������\n3.����������� � ������� ��������\n";
		cin>>otv_sp;
		cin.clear();
		cin.sync();		
		if ((otv_sp == '1')||(otv_sp == '2')||(otv_sp == '3'))
			flag1 = false;
	}

	//�������� ��������
	cout<<"������� �������� �������� �������\n";
	cin>>RangeStart>>RangeEnd;

	//��� ��������� �������� �������
	cout<<"������� ��� ��������� �������� �������\n";
	cin>>step;
		
	//����� ����������
	while(flag)
	{
		cout<<"�������� ����� ����������\n";
		cout<<"1.�������������\n2.�������\n";
		cin>>otv_method;
		cin.clear();
		cin.sync();
		if ((otv_method == '1')||(otv_method == '2'))
			flag = false;
	}

	n = RangeStart;
	while (flag2)
	{
		write_file(n, flag1);
		switch(otv_method)
		{
		case '1'://������������� ����������
			start_time = clock(); 
			vsort(Fname,&reversion, &checks);
			end_time = clock();	
			serch_time = (end_time-start_time)/1000.0;
			break;
		case '2'://������� ����������
			start_time = clock();
			//multiphase(mas, n, &reversion, &checks); 
			end_time = clock();
			serch_time = (end_time-start_time)/1000;
			break;
		}	
		//write_stat(n,serch_time,str);//������ �����������
		n+=step;
		if(n>=RangeEnd)
			flag2 = false;
	}*/
	return 0;
}