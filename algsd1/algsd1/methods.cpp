#include <iostream>//cout,cin
#include <stdio.h>
#include <stdlib.h>//����������� ����������

#define MAXSTACK 2048//��������� ������������� (������ MAXSTACK �� 2048)

using namespace std;//����������� ������������ ���

unsigned long rev, check;//���������� ����������

void downHeap(int*arr, long k, long n);//������������� ���������� ���������� ��������

//������������� ����������
void korp_sotr(int*arr, long size, int* reversion, int* checks)
{
	long i;
	int temp; 
	rev = 0;//������� ������������
	check = 0;//������� ��������

	// ������ �������� 
	for(i=size/2-1; i >= 0; i--) downHeap(arr, i, size-1);
  
	// ������ a[0]...a[size-1] �������� 
	for(i=size-1; i > 0; i--) 
	{
		rev++;
		// ������ ������ � ��������� 
		temp=arr[i]; arr[i]=arr[0]; arr[0]=temp;

    // ��������������� ��������������� a[0]...a[i-1] 
		downHeap(arr, 0, i-1); 
	}

	*reversion = rev;
	*checks = check;
}

//���������� ��������
void downHeap(int*arr, long k, long n) 
{
	//  ��������� ����������� ���������� �������� 
	//  �� ���������: a[k+1]...a[n]  - �������� 
	//  �����:  a[k]...a[n]  - �������� 
	int new_elem;
	long child;
	new_elem = arr[k];

	while(k <= n/2) 
	{  	// ���� � a[k] ���� ���� 
		child = 2*k;
		//  �������� �������� ���� 
		if( child < n && arr[child] < arr[child+1] ) 
		{
			check++; 
			child++;
		}
		else
		{
			check++;
		}
		if( new_elem >= arr[child] ) 
		{
			check++;
			break;
		}
		else
		{
			check++;
			rev++;
			arr[k] = arr[child]; 	// ��������� ���� ������ 
			k = child;
		}
	}
	arr[k] = new_elem;
}

//������� ����������
void fast_sort(int*arr, long size, int* reversion, int* checks)
{
	rev = 0;
	check = 0;
	long i, j;   			// ���������, ����������� � ����������  
	long lb, ub;  		// ������� ������������ � ����� ���������
	long lbstack[MAXSTACK], ubstack[MAXSTACK]; // ���� ��������
                        // ������ ������ �������� ����� ��������,
                        // � ������: �����(lbstack) � ������(ubstack) 
                        // ��������� ����������
	long stackpos = 1;   	// ������� ������� �����
	long ppos;            // �������� �������
	double pivot;              // ������� �������
	int temp; 

	lbstack[1] = 0;
	ubstack[1] = size-1;

	do { 
		// ����� ������� lb � ub �������� ������� �� �����. 
		lb = lbstack[ stackpos ];
		ub = ubstack[ stackpos ];
		stackpos--;
		do {
			// ��� 1. ���������� �� �������� pivot
			 ppos = ( lb + ub ) >> 1;
			i = lb; 
			j = ub; 
			pivot = arr[ppos];

			do {
				while ( arr[i] < pivot ) i++;
				while ( pivot < arr[j] ) j--;

				if ( i <= j ) {
					check++;
					temp = arr[i]; 
					arr[i] = arr[j]; 
					arr[j] = temp;
					rev++;
					i++; 
					j--;
				}
			} while ( i <= j );

			// ������ ��������� i ��������� �� ������ ������� ����������,
			// j - �� ����� ������ (��. ����������� ����), lb ? j ? i ? ub.
			// �������� ������, ����� ��������� i ��� j ������� �� ������� �������

			// ���� 2, 3. ���������� ������� ����� � ����  � ������� lb,ub
			if ( i < ppos ) 
			{     // ������ ����� ������
				check++;
				if ( i < ub ) 
				{     //  ���� � ��� ������ 1 �������� - ����� 
					check++;
					stackpos++;       //  �����������, ������ � ����
					lbstack[ stackpos ] = i;
					ubstack[ stackpos ] = ub;
				}
				ub = j;     //  ��������� �������� ����������
                            //  ����� �������� � ����� ������
			} 
			else 
			{       	    // ����� ����� ������
				if ( j > lb )
				{ 
					check++;
					stackpos++;
					lbstack[ stackpos ] = lb;
					ubstack[ stackpos ] = j;
				}
				lb = i;
			}
		} while ( lb < ub );        // ���� � ������� ����� ����� 1 ��������
	} while ( stackpos != 0 );    // ���� ���� ������� � �����
	
	*reversion = rev;
	*checks = check;
}

