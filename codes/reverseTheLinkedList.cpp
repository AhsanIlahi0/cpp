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
    
   void reversed() {
    Node*prev=NULL;
    Node*current =head;
    Node*Next=NULL;
    while(current!=NULL)
    {
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
        
    }
    head=prev;
}
    void display()
    {
        cout <<"original linked list\n";
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
    Node*first=new Node();
    Node*second=new Node();
    Node*third=new Node();
    Node*fourth=new Node();
    l1.head=first;
    first->data=10;
    first->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=NULL;
    l1.display();
    l1.reversed();
    cout <<"after reversed\n";
    l1.display();
    return 0;
}