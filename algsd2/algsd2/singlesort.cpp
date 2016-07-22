#include <iostream>//cout,cin
#include <stdlib.h>//����������� ����������
#include <time.h>//������ �� ��������
#include <locale.h>//������������ �������
#include <ctime>//clock()
#include <fstream>//��������� ������ � �������

using namespace std;///����������� ������������ ���

void multiphase(int*arr, long size, int* reversion, int* checks);//������� ����������
int vsort(char* Fname,int* reversion, int* checks);

//������ �����
int singlesort()
{
	setlocale(LC_ALL,"Russia");//������������ �������
	srand(time(0));//������ ������� ������� � ����

	int RangeStart,RangeEnd, mas, i, reversion = 0, checks = 0;
	long n;
	char otv;
	bool flag = true;
	unsigned int start_time, end_time;
	double serch_time; 
	
	//������ �������
	printf("������� ������ �������\n");
	cin>>n;

	//�������� ��������
	cout<<"������� �������� �������� �������\n";
	cin>>RangeStart>>RangeEnd;

	char*Fname = "massiv.txt\0";
	ofstream txtout(Fname, ios::out|ios::trunc);//�������� ����� ��� ������
	//���������� �����
	for(i=0;i<n;i++)
		if(RangeStart>=0)
		{
			mas=(rand()%(RangeEnd - RangeStart) + RangeStart);
			txtout<<mas<<" ";
		}
		else
		{
			mas=(rand()%(RangeEnd - RangeStart + 1) + RangeStart);
			txtout<<mas<<" ";
		}
	txtout.close();//�������� �����

	//����� ������ ����������
	while(flag)
	{
		cout<<"�������� ����� ����������\n";
		cout<<"1.�������������\n2.�������\n";
		cin>>otv;
		cin.clear();
		cin.sync();

		flag = false;
		switch(otv)
		{
		case '1'://������������� ����������
			start_time = clock();
			vsort(Fname,&reversion, &checks);//������������� ����������
			end_time = clock();
			//����� ������ ����������
			cout<<"����� ������������� ����������: ";
			serch_time = (end_time-start_time)/1000.0;
			cout<<serch_time<<" ���\n";
			break;
		case '2'://������� ����������
			start_time = clock();
			//multiphase(mas, n, &reversion, &checks); //������� ����������
			end_time = clock();
			//����� ������ ����������
			cout<<"����� ������� ����������: ";
			serch_time = (end_time-start_time)/1000;
			cout<<(serch_time)<<" ���\n";
			break;
		default: flag = true;
		}	
//		cout<<"���������� ������������: "<<reversion<<"\n";
//		cout<<"���������� ��������: "<<checks<<"\n";
	}
		
	return 0;
}