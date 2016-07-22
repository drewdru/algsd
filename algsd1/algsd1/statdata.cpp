#include <iostream>//cout,cin
#include <stdlib.h>//����������� ����������
#include <time.h>//������ �� ��������
#include <locale.h>//������������ �������
#include <ctime>//clock()

using namespace std;//����������� ������������ ���

void korp_sotr(int*arr, long size, int* reversion, int* checks);//������������� ����������
void fast_sort(int*arr, long size, int* reversion, int* checks);//������� ����������
void zap(int *arr, int size, char metk);//���������� �������
int write_stat(int size, double time, char* file_name);	//����� � ���� �����������

//������ �����
int statdata()
{
	setlocale(LC_ALL,"Russia");//������������
	srand(time(0));//������ ������� ������� � ����

	bool flag1 = true, flag = true, flag2 = true;
	char otv, otv_sp, otv_method;
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
	
	puts("������� ��� ���� ��� ������ ����������� ���������");
	gets(str);	

	n = RangeStart;
	while (flag2)
	{
		int *mas = new int[n];//��������� ������ ������������� �������
		zap(mas, n, otv_sp);//���������� �������
		switch(otv_method)
		{
		case '1'://������������� ����������
			start_time = clock(); 
			korp_sotr(mas, n, &reversion, &checks);
			end_time = clock();			
			break;
		case '2'://������� ����������
			start_time = clock();
			fast_sort(mas, n, &reversion, &checks); 
			end_time = clock();
			break;
		}	
		delete[] mas; //������������ ������	�� �������
		serch_time = (end_time-start_time)/*/1000.0*/;//����� ����������
		write_stat(n,serch_time,str);//������ �����������
		n+=step;
		if(n>=RangeEnd)
			flag2 = false;
	}
	return 0;
}

//����� � ����
int write_stat(int size, double time, char* file_name_out)	
{
	FILE *out;
	
	//�������� �� ����������� �������� �����
	if((out = fopen(file_name_out,"a+"))==0)
	{
		fprintf(stderr,"���������� ������� ���� %s\n",file_name_out);
		return 1;
	}
	
	//����� � ���� ������ ������� � ������� ������
	fprintf(out,"%d\t\t",size);
	fprintf(out,"%f\n",time);

	fclose(out);

	return 0;
}