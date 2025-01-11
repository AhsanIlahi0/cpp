#include<iostream>
using namespace std;
struct Node{
int data;
Node *next;
};
class Linked_Lsit
{
    public:
    Node *head;
    Linked_Lsit()
    {
        head=NULL;
    }
    
   void merge_list(Node*head1,Node*head2)
   {
        Node*temp=head1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head2;
   }
    void display(Node*head)
    {
        Node*temp=head;
        while(temp!=NULL)
        {
            cout <<temp->data<<"\n";
            temp=temp->next;
        }
    }
};
int main()
{  Linked_Lsit l1;
    Node*first1=new Node();
    Node*second1=new Node();
    Node*third1=new Node();
    Node*fourth1=new Node();
    l1.head=first1;
    first1->data=10;
    first1->next=second1;
    second1->data=20;
    second1->next=third1;
    third1->data=30;
    third1->next=NULL;
    cout<<"linked list 1\n";  
    l1.display(l1.head);
    Linked_Lsit l2;
    Node*first2=new Node();
    Node*second2=new Node();
    Node*third2=new Node();
    Node*fourth2=new Node();
    l2.head=first2;
    first2->data=40;
    first2->next=second2;
    second2->data=50;
    second2->next=third2;
    third2->data=60;
    third2->next=NULL;
    cout<<"linked list 2\n";  
    l2.display(l2.head);
    l1.merge_list(l1.head,l2.head);
    cout<<"after merging linked list 1 and 2\n";
    l1.display(l1.head);  

    

    return 0;
}