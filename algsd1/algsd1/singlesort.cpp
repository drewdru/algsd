#include <iostream>//cout,cin
#include <stdlib.h>//����������� ����������
#include <time.h>//������ �� ��������
#include <locale.h>//������������ �������
#include <ctime>//clock()

using namespace std;///����������� ������������ ���


void korp_sotr(int*arr, long size, int* reversion, int* checks);//������������� ����������
void fast_sort(int*arr, long size, int* reversion, int* checks);//������� ����������
int write_mas(int*arr,  int nlen);//����� �������

//������ �����
int singlesort()
{
	setlocale(LC_ALL,"Russia");//������������ �������
	srand(time(0));//������ ������� ������� � ����

	int RangeStart,RangeEnd, i, reversion, checks;
	long n;
	char otv;
	bool flag = true;
	unsigned int start_time, end_time;
	double serch_time; 

	//������ �������
	printf("������� ������ �������\n");
	cin>>n;

	int *mas = new int[n];//������������ ������
	
	//�������� ��������
	cout<<"������� �������� �������� �������\n";
	cin>>RangeStart>>RangeEnd;

	//���������� �������
	for(i=0;i<n;i++)
		if(RangeStart>=0)
			mas[i] = rand()%(RangeEnd - RangeStart) + RangeStart;
		else
			mas[i] = rand()%(RangeEnd - RangeStart + 1) + RangeStart;

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
			printf("����� ��������� �������\n");
			write_mas(mas, n);//����� �������
			start_time = clock();
			korp_sotr(mas, n, &reversion, &checks);//������������� ����������
			end_time = clock();
			printf("����� ���������������� �������\n");
			write_mas(mas, n);	//����� �������	
			//����� ������ ����������
			cout<<"����� ������������� ����������: ";
			serch_time = (end_time-start_time)/1000.0;
			cout<<serch_time<<" ���\n";
			break;
		case '2'://������� ����������
			printf("����� ��������� �������\n");
			write_mas(mas, n);//����� �������	
			start_time = clock();
			fast_sort(mas, n, &reversion, &checks); //������� ����������
			end_time = clock();
			printf("����� ���������������� �������\n");
			write_mas(mas, n);//����� �������	
			//����� ������ ����������
			cout<<"����� ������� ����������: ";
			serch_time = (end_time-start_time)/1000;
			cout<<(serch_time)<<" ���\n";
			break;
		default: flag = true;
		}	
		cout<<"���������� ������������: "<<reversion<<"\n";
		cout<<"���������� ��������: "<<checks<<"\n";
	}

	delete[] mas;//������������ ������

	return 0;
}

//����� �������
int write_mas(int*arr, int nlen)
{	
	int i,k = 12;
	char file_name_out[45];
	FILE *out;
	puts("������� ��� ���� ��� ������ �������");
	gets(file_name_out);
	
	//�������� �� ����������� ������� ����
	if((out = fopen(file_name_out,"a+"))==0)
	{
		fprintf(stderr,"���������� ������� ���� %s\n",file_name_out);
		return 1;
	}
	
	//����� ������� � ����
	for (i = 0; i<nlen; i++)
	{
		fprintf(out,"%d, ",arr[i]);
		if(i == k)
		{
			fprintf(out,"\n");
			k+=12;
		}
	}
	
	fprintf(out,"\n\n\n");
	fclose(out);//�������� �����

	return 0;
}