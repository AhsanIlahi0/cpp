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
	
    void display()
    {
        Node*temp=head;
		int i=1; 
		cout <<i<<": Element: "<<temp->data<<"  head\n";
        temp=temp->next;i++;
		while(temp!=head)
        {
            cout <<i<<": Element: "<<temp->data<<"  next "<<temp->next->data<<"\n";
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
	l1.display();
    return 0;
}