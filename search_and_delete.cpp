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
    void Delete(int val) {
    if (head == NULL) {
        cout << "The linked list is empty\n";
        return;
    }
    Node* temp = head;
    if (temp->data == val) 
    {
        head = temp->next;
        if (head != NULL) 
        {
            head->prev = NULL;
        }
        delete temp;
        return;
    }
    while (temp->next != NULL) 
    {
        if (temp->next->data == val) 
        {
            Node* ptr = temp->next;
            temp->next = ptr->next;
            if (ptr->next != NULL) 
            {
                ptr->next->prev = temp;
            }
            delete ptr;
            return;
        }
        temp = temp->next;
    }
    cout << "Value " << val << " not found in the list\n";
}
    void display()
    {
        Node*temp=head;
        if(temp==NULL)
        {
            cout<<"the linked list is empty\n";
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
    cout <<"After Deleting 55 \n";
    l1.Delete(55);
    l1.display();
    return 0;
}