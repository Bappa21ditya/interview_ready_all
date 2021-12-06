#include<bits/stdc++.h>
using namespace std;\
struct node 
{
	int data;
	struct node *next;
}*head,*current;
struct node* create_node(int x)
{
	struct node *p;
	p=new node();
	p->data=x;
	p->next=NULL;
}
void apppend(int x)
{
	struct node *t;
	t=create_node(x);
	if(head==NULL)
	{
		head=t;
		current=t;
	}
	current->next=t;
	current=t;
}
void insert_at_beg(int x)
{
	struct node *t;
	t=create_node( x);
	t->next=head;
	head=t;
}
void insert_at_midddel(int x,int pos)
{
  	struct node *t,*temp;
	t=create_node(x);
	temp=head;
	for(int i=0;i<pos-1;i++)
	{
		temp=temp->next;
	}
	t->next=temp->next;
	temp->next=t;	
}
int delete1(int pos)
{
	int x=-1;
	if(pos==1)
	{
		struct node *t;
		t=head;
		head=head->next;
		x=t->data;
		delete(t);
		return x;	
	}
	else
	{
	 struct node *p,*q;
	 p=head;
	 for(int i=0;i<pos-1;i++)
	 {
	 	q=p;
	 	p=p->next;
		}
		x=p->data;
		q->next=p->next;
		delete(p);
		return x;	
	}
}
void show()
{
	cout<<"\n the elements of the linked list :";
	struct node *t;
	t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<"\n";
}
int main()
{
	for(int i=1;i<=5;i++)
    {
	   apppend(i);	
	}
    show();
	insert_at_beg(-10);
	 show();
	 cout<<"\ninsert at middle:";
	insert_at_midddel(3,4);
	show();
	cout<<"\ndeleted node is:"<<delete1(4)<<"\n";
	show();
}

