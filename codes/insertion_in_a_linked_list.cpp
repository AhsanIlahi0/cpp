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
	Node *insertatbegin( Node *head, int val)
	{
		Node*ptr = new Node(0);
		ptr->next = head;
		ptr->data = val;
		
		return ptr;
	}
	//case 2
	Node*insertatindex(Node*head, int val, int index)
	{
		Node*ptr = new Node(0);
		int i = 0;
		Node*p = head;
		while (i !=index-1)
		{
			p= p->next;
			i++;
		}
		ptr->data = val;
		ptr->next = p->next;
		p->next = ptr;

		return head;
	}
	//case 3
	Node* insertatlast(Node*head, int val)
	{
		Node*ptr = new Node(0);
		ptr->data = val;
		Node*p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		
		p->next = ptr;
		ptr->next = NULL;
		return head;
	}
	//case 4
	Node*insertafterNode(Node*head, Node*prevNode, int val)
	{
		Node*ptr = new Node(0);
		ptr->data = val;
		ptr->next=prevNode->next;
		prevNode->next = ptr;

		return head;
	}
	//To print all nodes currently avaialable in linked list
	void traversal(Node*ptr)
	{
		int i = 1;
		while (ptr != NULL)
		{
			cout <<i<< ": element " << ptr->data ;
            if(i==1)
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
	Node*head = new Node(20);
	Node*second = new Node(19);;
	Node*third = new Node(18);;


	head->next = second;
	second->next = third;
	third->next = NULL;
	Node obj(0);
	cout << "original linked list\n";
	obj.traversal(head);
	head = obj.insertatbegin(head, 78);
	cout << "after insert 78 at beginning\n";
	obj.traversal(head);
	cout << "after insert 16 at 2nd index\n";
	head = obj.insertatindex(head, 16,1);
	obj.traversal(head);
	cout << "after insert 11 at last \n";
	head = obj.insertatlast(head, 11);
	obj.traversal(head);
	cout << "after insert 30 after second node\n";
	head = obj.insertafterNode(head, second, 30);
	obj.traversal(head);

	return 0;
}