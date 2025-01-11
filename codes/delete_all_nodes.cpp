#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node*next;
    Node*prev;
};
class Linked_list
{
public:
    Node*head;
    Linked_list()
    {
        head=NULL;
    }
    void Delete()
    {
        if(head==NULL)
        {
            cout <<"the linked list already empty\n";
            return ;
        }
        while(head!=NULL)
        {
            Node*temp=head;
            Node*NextNode=head->next;
            delete temp;
            head=NextNode;
        }
        cout<<"the linked list is empty\n";
    }
    void display()
    {
        Node*temp=head;
        if(temp==NULL)
        {
            return ;
        }
        else
        {
            int i=1;
            while(temp!=NULL)
            {
               cout <<i++<<": Element: "<<temp->data;
                if(i==2)
                {
                cout <<"  head";
                }
                cout <<"\n";
                temp=temp->next;
            }
        }
    }
};
int main()
{
    Linked_list l1;
    Node*first=new Node();
    Node*second=new Node();
    Node*third=new Node();
    Node*fourth =new Node();
    Node*fifth=new Node();
    first ->data=12;
    second ->data=34;
    third->data=55;
    l1.head=first;
    first->next=second;
    first->prev=NULL;
    second ->next=third;
    second->prev=first;
    third ->next=NULL;
    third->prev=second;
    cout <<"Original Linked List\n";
    l1.display();
    cout <<"After Deleting all nodes \n";
    l1.Delete();
    l1.display();
    return 0;
}