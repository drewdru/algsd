#include<iostream>
#include<cstdlib>
#include<fstream>
#include<stdlib.h>

using namespace std;

struct Node       //��������� ���������� ������ ������
{
	int x;     //�������� x ����� ������������ � ������
	Node *Next,*Prev; //��������� �� ������ ���������� � ����������� ��������� ������
};

class List   //������� ��� ������ ������
{
	Node *Head,*Tail; //��������� �� ������ ������ ������ � ��� �����
public:
	List():Head(NULL),Tail(NULL){}; //�������������� ������ ��� ������
	~List(); //����������
	void Add_start(int x); //������� ���������� ��������� � ������ �������
	void Add_end(int x); //������� ���������� ��������� � ����� ������
	void Add_num(int x, int p);//������� ���������� ��������� �� ������� � ������
	int Del_end(bool*kkk);//������� �������� ���������� �������� ������
	int Del_start(bool*kkk);//������� �������� ������� �������� ������	
	int Del_num(int pos, bool*kkk);//������� �������� ��������� � ������� � ������
	void Clear();
	bool Show(); //������� ����������� ������ �� ������
	void Show_number(int p);
	void Find(int p, bool*kkk);
	int del_often(bool*kkk);
	int size();
	void clear_not_lis2(List& lst2);
};

List::~List() //����������
{   
	while (Head) //���� �� ������ �� ������ ������ ���-�� ����
	{
		Tail=Head->Next; //��������� ����� ������ ���������� ����� ������
		delete Head; //������� ������ �� ������� �����
		Head=Tail; //����� ������ ������ �� ����� ���������� ��������
	}
}

int List::size()
{
	Node *temp=Tail;
	int cnt = 1;
	temp=Head; //�������� ��������� �� ����� ������� ��������
	while (temp!=NULL) //���� �� �������� ������ ��������
	{
		temp=temp->Next; //����� ������ �� ����� ���������� ��������
		cnt++;
	}
	return cnt;
}

void List::Add_start(int x)
{
	Node *temp=new Node; //��������� ������ ��� ����� ������� ���������
	temp->Prev=NULL;  //���������, ��� ���������� �� ����������� ������ �����
	temp->x=x;//���������� �������� � ���������
 
	if (Head!=NULL) //���� ������ �� ����
	{
		temp->Next=Head; //��������� ����� �� ��������� ������� � �����. ����
		Head->Prev=temp; //��������� ����� ����������� �� ������� ��������
		Head=temp; //������ ����� ������
	}
	else //���� ������ ������
	{
		temp->Next=NULL; //��������� ������� ��������� � �������
		Head=Tail=temp; //������=�����=��� �������, ��� ������ ��������
	}
}


void List::Add_end(int x)
{
	Node *temp=new Node; //��������� ������ ��� ����� ������� ���������
	temp->Next=NULL;  //���������, ��� ���������� �� ���������� ������ �����
	temp->x=x;//���������� �������� � ���������
 
	if (Head!=NULL) //���� ������ �� ����
	{
		temp->Prev=Tail; //��������� ����� �� ���������� ������� � �����. ����
		Tail->Next=temp; //��������� ����� ���������� �� ������� ��������
		Tail=temp; //������ ����� ������
	}
	else //���� ������ ������
	{
		temp->Prev=NULL; //���������� ������� ��������� � �������
		Head=Tail=temp; //������=�����=��� �������, ��� ������ ��������
	}
}

//�������� ���� � ������ � ����������� �������
void List::Add_num(int x, int p)
{
	Node *temp=new Node; //��������� ������ ��� ����� ������� ���������
	temp->Next=NULL;  //���������, ��� ���������� �� ���������� ������ �����
	temp->Prev=NULL;  //���������, ��� ���������� �� ����������� ������ �����
	temp->x=x;//���������� �������� � ���������
 
	if (Head!=NULL) //���� ������ �� ����
	{
		Node *t = Head;
		for(int i=p;i>1;i--,t=t->Next);
		t->Prev->Next=temp;
		temp->Prev=t->Prev; //��������� ����� �� ���������� ������� � �����. ����
		temp->Next=t;//��������� ������� ����� t
		t->Prev=temp;
	}
	else //���� ������ ������
	{
		temp->Prev=NULL; //���������� ������� ��������� � �������
		temp->Next=NULL; //���������� ������� ��������� � �������
		Head=Tail=temp; //������=�����=��� �������, ��� ������ ��������
	}
}

int List::Del_start(bool*kkk)//������� ���� �� ������� �� ������
{
	int val;
	if(Head==NULL) 
	{
		*kkk = false;
		return 0;//����� ����	
	}
	if(Head->Next==NULL)//���� ��� ��������� ������� � ������
	{
		val=Head->x;
		delete Head;
		Head=NULL;
	}
	else
	{	
		Node *t = Head;
		val = Head->x;
		Head = Head->Next;
		delete t;
	}
	return val;
}

int List::Del_end(bool*kkk)
{
	int val;
	if(Head==NULL) 
	{
		*kkk = false;
		return 0;//����� ����	
	}
	if(Head->Next==NULL)//���� ��� ��������� ������� � ������
	{
		val=Head->x;
		delete Head;
		Head=NULL;
	}
	else
	{	
		Node *t = Tail;
		val = Tail->x;
		Tail = Tail->Prev;
		Tail->Next = NULL;
		delete t;
	}
	return val;}

int List::Del_num(int pos, bool*kkk)//������� ���� �� ������� �� ������
{
	int val;
	if(Head==NULL) 
	{
		*kkk = false;
		return 0;//����� ����	
	}
	if((pos>size()-1)||(pos<1))
	{
		*kkk = false;
		return 0;
	}
	if(Head->Next==NULL)//���� ��� ��������� ������� � ������
	{
		val=Head->x;
		delete Head;
		Head=NULL;
	}
	else if(pos==1)
	{
		val = Del_start(kkk);
	}
	else if(pos==size() - 1)
	{
		val = Del_end(kkk);
	}
	else
	{			
		Node *t=Head;
		for(int i=pos;i>1;i--,t=t->Next);
		if(t==Head)Head=t->Next;//���� �������� ������� 1-�� ������� �� ������ ��������� �� 2-��
		t->Prev->Next=t->Next;//������� t �������
		t->Next->Prev=t->Prev;
		val=t->x;
		delete t;		
	}
	return val;
}

void List::Clear()
{
	List ls;
	Node *temp=Tail;
	temp=Head; //�������� ��������� �� ����� ������� ��������
	while (temp!=NULL) //���� �� �������� ������ ��������
	{		
		Head = Head->Next;
		temp = Head;
	}
}


bool List::Show()
{
	Node *temp=Tail;
	int cnt = 0;
//������� ������ � ������
	temp=Head; //�������� ��������� �� ����� ������� ��������
	while (temp!=NULL) //���� �� �������� ������ ��������
	{
		cout<<temp->x<<" "; //������� ������ ��������� �������� �� �����
		temp=temp->Next; //����� ������ �� ����� ���������� ��������
		cnt++;
	}
	if(cnt == 0)
	{
		cout<<"� ������ �� ���������� ��������\n";
		return false;
	}
	cout<<"\n";
	return true;
 }

void List::Show_number(int p)
{
	if (Head!=NULL) //���� ������ �� ����
		{
			Node *t = Head;
			for(int i=p;i>1;i--,t=t->Next);
			cout<<t->x<<"\n";
		}
	else
		cout<<"������ ����\n";
}

void List::Find(int p, bool*kkk)
{
	Node *temp=Tail;
	int cnt = 1;
	int cnt2 = 1;
	temp=Head; //�������� ��������� �� ����� ������� ��������
	while (temp!=NULL) //���� �� �������� ������ ��������
	{
		if(temp->x==p)
		{
			cout<<cnt<<" ";
			cnt2++;
		}
		temp=temp->Next; //����� ������ �� ����� ���������� ��������
		cnt++;
	}
	cout<<endl;
	if (cnt2==1)
		*kkk = false;
}

void sort(Node *start)
{
	Node *tmp;
    Node *a;
    int t=0;
    bool flag=1;
    while(flag==1)
    {
        tmp=start;
        a=tmp->Next;
        flag=0;
        while(a)
        {
            if((tmp->x)>(a->x))
            {
                t=tmp->x;
                tmp->x=a->x;
                a->x=t;
                flag=1;
            }
            tmp=tmp->Next;
            a=a->Next;
        }
    }
}

int List::del_often(bool*kkk)
{
	int del_elem, del;
	int max = 0;
	sort(Head);
	Node *temp=Head;
	int cnt = 0;
	if(Head == NULL)
		*kkk = false;
	del_elem = Head->x;
	temp=Head->Next; //�������� ��������� �� ����� ������� ��������	
	while (temp!=NULL) //���� �� �������� ������ ��������
	{
		if(temp->x==temp->Prev->x)
			cnt++;
		else
		{
			if(max < cnt)
			{
				max = cnt;
				del_elem = temp->Prev->x;				
			}		
			cnt = 0;
		}
		temp=temp->Next; //����� ������ �� ����� ���������� ��������		
	}

	temp=Head; //�������� ��������� �� ����� ������� ��������
	int n = 1;
	while (temp!=NULL) //���� �� �������� ������ ��������
	{
		Node*t =temp->Next;
		if(temp->x==del_elem)
			del = Del_num(n,kkk);
		else
			n++;

		temp=t; //����� ������ �� ����� ���������� ��������				
	}
	return del_elem;
};

void List::clear_not_lis2(List& lst2)
{
	Node* temp;
	bool qwe, ddd;
	bool kkk = true;
	if(Head==NULL) 
	{
		kkk = false;
		cout<<"������ 1 ����\n";
	}
	if(lst2.size()-1<1)
	{
		kkk = false;
		cout<<"������ 2 ����\n";
	}
	if (kkk)
	{
		int cnt = 1;
		temp = Head;
		while (temp!=NULL) //���� �� �������� ������ ��������
		{
			qwe = true;
			lst2.Find(temp->x, &qwe);
			ddd = true;
			if (qwe)
			{							
				cnt++;
				temp = temp->Next;
			}
			else
			{
				int del = Del_num(cnt,&ddd);	
				temp = Head;
				for(int i=cnt;i>1;i--,temp=temp->Next);
			}
		}		
	}
}