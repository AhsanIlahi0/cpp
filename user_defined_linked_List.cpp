#include<iostream>
using namespace std;
class Node{
    public:
int data;
Node* next;
Node(int val)
{
    data=val;
    next=NULL;
}
Node*traversal(Node*head)
{
    Node*ptr=head;
    while(ptr!=NULL)
    {
        cout <<ptr->data<<"  ";
        ptr=ptr->next;
    }
}
};
int main()
{
    system("cls");
    bool choice=true;
    Node*linkedlist=nullptr;
    Node*head=nullptr;
    cout <<"want to add something in the list\n";
    cin>>choice;
    int i=1;
    while(choice)
    {
    system("cls");
int value;
        cout <<"enter the value of node\n";
        cin>>value;
        Node*newNode=new Node(value);
        if(i==1)
        {
            head=newNode;
            linkedlist=head;
        }
        else
        {
            linkedlist->next=newNode;
            linkedlist=linkedlist->next;
        }
        i++;
        cout <<"want to add something in the list\n";
    cin>>choice;
    }
Node obj(0);
obj.traversal(head);
    return 0;
}