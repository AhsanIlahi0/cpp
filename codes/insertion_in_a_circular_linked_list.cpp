#include<iostream>
using namespace std;
struct Node{
int data;
Node *next;
};
class linked_list
{
    public:
    Node *head;
    linked_list()
    {
        head=NULL;
    }
	void insert_at_head(int val)
	{
		Node*newNode=new Node();
		newNode->data=val;
		newNode->next=NULL;
		if(head==NULL)
		{
			head=newNode;
			newNode->next=head;
		}
		else
		{
			Node*temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			newNode->next=head;
			head=newNode;
			temp->next=head;
		}
	}
	void insert_at_last(int val)
	{
		Node*newNode=new Node();
		newNode->data=val;
		if(head==NULL)
		{
			head =newNode;
			newNode->next-head;
		}
		else
		{
			Node*temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=newNode;
			newNode->next=head;
		}
	}
	void insert_at_pos(int val,int pos)
	{
		int count=1;
		Node*newNnode=new Node();
		newNnode->data=val;
		Node*temp=head;
		if(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
		while(temp->next!=head)
		{
			count++;
			temp=temp->next;
		}
		
		if(head==NULL&&pos==1)
		{
			head=newNnode;
			newNnode->next=head;
		}
		else if(pos<1||pos>count)
		{
			cout <<"invalid position\n";
		}
		else 
		{
			Node*temp=head;
			Node*p;
			int i=1;
			while(i!=pos-1)
			{
				temp=temp->next;
				i++;
			}
			p=temp->next;
			temp->next=newNnode;
			newNnode->next=p;
		}

	}
    void display()
    {
        Node*temp=head;
		int i=1; 
		cout <<i<<": Element: "<<temp->data<<"  head\n";
        temp=temp->next;i++;
		while(temp!=head)
        {
            cout <<i<<": Element: "<<temp->data<<"\n";
            temp=temp->next;
			i++;
        }
		
}
  
};
int main()
{  	system("cls");
	linked_list l1;
	//initializing Nodes
    Node*first=new Node();
    Node*second=new Node();
    Node*third=new Node();
    Node*fourth=new Node();
    //giving data and adress of next Node
    l1.head=first;
    first->data=7;
    first->next=second;
    second->data=8;
    second->next=third;
    third->data=9;
    third->next=fourth;
    fourth->data=10;
    fourth->next=first;
	cout<<"original linked list\n";
    l1.display();
	cout<<"after insert 2 at head\n";
	l1.insert_at_head(2);
	l1.display();
	cout <<"after insert 4 at last \n";
	l1.insert_at_last(4);
	l1.display();
    cout <<"after insert 6 at 3rd position\n";
	l1.insert_at_pos(6,4);
	l1.display();
    return 0;
}