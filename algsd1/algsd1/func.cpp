#include <time.h>//������ �� ��������
#include <stdlib.h>//����������� ����������

//���������� �������
void zap(int *arr, int size, char metk)
{
	srand(time(0));//������ ������� ������� � ����
	unsigned long i;
	switch(metk)
	{
	case '1'://���������� ���������� ����������
		for(i=0;i<size;i++)
			arr[i] = rand()%2001 -2000;	
		break;
	case '2'://���������� � ������� �����������
		for(i=0;i<size;i++)
			arr[i] = i;	
		break;
	case '3': //���������� � ������� ��������
		for(i=0;i<size;i++)
			arr[i] = size-i-1;	
		break;
	}
}