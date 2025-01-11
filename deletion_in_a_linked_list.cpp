#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node*next;
	Node(int val)
	{
		data = val;
		next = NULL;
	}
    //case 1
	Node*delhead(Node*head)
    {
        Node*ptr=head;
        head=head->next;
        free(ptr);
        return head;
    }
    //case 2
	Node*delafterNode(Node*head,Node*index)
    {
        Node*p=head;
        int i=1;
        while(p!=index)
        {
            p=p->next;
            i=i+1;
        }
        Node*q=p->next;
        p->next=q->next;
        free(q);
        return head;
    }
    Node*del_last_node(Node*head)
    {
        Node*p=head;
        Node*q=p->next;
        
        while(q->next!=NULL)
        {
           p=p->next;
           q=p->next;
        }
        
        p->next=q->next;
        free(q);
        return head;
    }
    Node*del_a_node_with_given_value(Node*head,int val)
    {
        bool run=false;
        Node*p=head;
        Node*q=head->next;
        while(q!=NULL)
        {
            
            if(q->data==val)
            {
                run =true;
               p->next=q->next;
            }
            if(run)
            {}
            else
            {
            p=p->next;
            
            }
            run=false;
            q=q->next;
        }
        free(q);
        if(head->data==val)
        { 
            //Node*temp=head;
            head=head->next;
           //free(temp);
        }
        return head;
    }
    void traversal(Node*ptr)
	{
		int i = 0;
		while (ptr != NULL)
		{
			cout <<i<< ": element " << ptr->data ;
            if(i==0)
            {
                cout <<"  head";
            }
            cout <<endl;
			ptr = ptr->next;
			i++;
		}
	}
};
int main() {
system("cls");
	Node*head = new Node(19);
	Node*second = new Node(2);
	Node*third = new Node(12);
	Node*fourth = new Node(15);
	Node*last = new Node(2);

	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = last;
    last->next = NULL;

	Node obj(0);
	cout << "original linked list\n";
	obj.traversal(head);
    cout<<"after deletion of head node\n";
	head=obj.delhead(head);
    obj.traversal(head);
    cout<<"after deletion of node after node\n";
	head=obj.delafterNode(head,second);
    obj.traversal(head);
    cout<<"after deletion of last node\n";
	head=obj.del_last_node(head);
    obj.traversal(head);
    int value=2;
    cout <<"after deletion of nodes having value "<<value<<"\n";
    head=obj.del_a_node_with_given_value(head,2);
    obj.traversal(head);

	return 0;
}