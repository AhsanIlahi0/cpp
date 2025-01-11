#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
};
class Binary_Tree
{
    public:
    Node*root;
    Binary_Tree()
    {
        root=NULL;
    }
    Node*creat_node(int val)
    {
        Node*p=new Node();
        p->data=val;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
};
int main()
{
    Binary_Tree obj;
    Node*A=obj.creat_node(5);
    Node*a1=obj.creat_node(4);
    Node*a2=obj.creat_node(3);

    A->left=a1;
    A->right=a2;

    a1->left=NULL;    
    a1->right=NULL;

    a2->left=NULL;
    a2->right=NULL;    
    
    return 0;
}