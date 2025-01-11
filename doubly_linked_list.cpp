#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int val)
    {
        data=val;
        next=nullptr;
        prev=nullptr;
    }
    void traversal(Node* head)
{
    Node* ptr = head;
    int i = 1;
    while (ptr != nullptr)
    {
        cout << i << ": Element " << ptr->data << " ";
         if (ptr == head)
        {
            cout << "Head";
        }
        if (ptr->prev != nullptr)
        {
            cout << "Prev: " << ptr->prev->data << " ";
        }
       
        cout << endl;
        ptr = ptr->next;
        i++;
    }
}
};
int main()
{
    system("cls");
    int value;
    bool ch=true;
    Node*linkedlist;
    Node*head;
    int i=1;
    while(ch)
    {
        system("cls");
        cout <<"enter the value to add in linked list\n";
        cin>>value;
        Node*newnode=new Node(value);
        if(i==1)
        {
            
            head=newnode;
            head->prev=nullptr;
            head->next=nullptr;
            linkedlist=head;
        }
        else{
            
        linkedlist->next=newnode;
        newnode->prev=linkedlist;
        linkedlist=linkedlist->next;
        }
        
        i++;
        system("cls");
        cout <<"Want to add more nodes\n";
        cin>>ch;
    }
    Node obj(0);
    obj.traversal(head);
    // Node* temp = head;
    // while (temp != nullptr) {
    //     Node* nextNode = temp->next;
    //     delete temp;
    //     temp = nextNode;
    // }
    return 0;
}