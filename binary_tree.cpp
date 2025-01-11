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
    void preorder(Node*root){
        if(root==NULL){
            return; 
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node*root){
        if(root==NULL){
            return; 
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};

int main()
{
    Binary_Tree obj;
    Node*A=obj.creat_node(5);
    Node*a1=obj.creat_node(4);
    Node*a2=obj.creat_node(3);
    Node*a3=obj.creat_node(10);

    A->left=a1;
    A->right=a2;

    a1->left=a3;    
    a1->right=NULL;

    a2->left=NULL;
    a2->right=NULL;    
    obj.preorder(A);
    return 0;
}