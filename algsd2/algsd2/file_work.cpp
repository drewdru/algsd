#include <iostream>//��������� ����/�����
#include <fstream>//��������� ������ � �������
#include <stdio.h>//������ � �������
#include <time.h>//������ �� ��������
#include <stdlib.h>//����������� ����������
using namespace std;//����������� ������������ ���

//���������� ������ �� �����
int read_file(int *B, long n)
{
	char*Fname = "massiv.txt\0";
	ifstream txtin(Fname, ios::in);//�������� ����� ��� ����������
	txtin.seekg(0,ios::beg);//��������� ��������� ������� � ������ �����
	//���������� ������
	for (int i = 0; i<n; i++)
		txtin>>B[i];
	txtin.close();//�������� �����
	return 0;
}
//����������� ���������� ������� � �����
long lenght_file(char*Fname)
{	
	ifstream txtin(Fname, ios::in);//�������� ����� ��� ����������
	long cnt = 0;
	int temp;
	//������� ���������� ������� � �����
	while(txtin.cur != txtin.eof())
	{
		txtin>>temp;
		cnt++;
	}
	txtin.clear();//�������� ��������� ������ �����
	txtin.close();//�������� �����
	return cnt;//������� ���������� �������
}
//������ ������ � �����
void write_file(int n, char flag)
{
	char*Fname = "massiv.txt\0";
	ofstream txtout(Fname, ios::out|ios::trunc);//�������� ����� ��� ������	
	//������ ������

	if (flag == '1')
	{
		for(int i=0;i<n;i++)
			txtout<<(rand()%2001 - 2001)<<" ";
		txtout.close();//�������� �����
	}
	else if (flag == '2')
	{
		for(int i=0;i<n;i++)
			txtout<<i<<" ";	
	}
	else if (flag == '3')		
	{
		for(int i=0;i<n;i++)
			txtout<<(n-i-1)<<" ";	
	}
}

//���������� �������
void zap(int *arr, int size, char metk)
{
	srand(time(0));//������ ������� ������� � ����
	long i;
	char*Fname = "massiv.txt\0";
	ofstream txtout(Fname, ios::out);//�������� ����� ��� ������
	switch(metk)
	{
	case '1'://���������� ���������� ����������
		for(i=0;i<size;i++)
			txtout<<(rand()%2001-2000)<<" ";	
		break;
	case '2'://���������� � ������� �����������
		for(i=0;i<size;i++)
			txtout<<i;	
		break;
	case '3': //���������� � ������� ��������
		for(i=0;i<size;i++)
			txtout<<(size-i-1);	
		break;
	}
	txtout.close();//�������� �����
}
