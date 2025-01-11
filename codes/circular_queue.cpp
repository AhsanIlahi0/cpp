#include<iostream>
using namespace std;
class queue
{
    int front=0;
    int rear=0;
    int *arr;
    int s;
    public:
    queue(int size)
    {
        s=size+1;
        arr=new int[size+1];
    }
    bool isEmpty()
    {
        if(rear==front)
        {
            rear=front=0;
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if((rear+1)%s==front)
        {
            return true;
        }
        return false;
    }
    int enqueue(int val)
    {
        if(isFull())
        {
            cout<<"over flow\n";
            system("pause");
            return 0;
        }
        else
        {
            rear=(rear+1)%s;
            arr[rear]=val;
        }
    }
    int dequeue()
    {
        int x=0;
        if(isEmpty())
        {
            cout <<"under flow\n";
            system("pause");
            return x;
        }
        else
        {
            x=arr[front];
            front=(front+1)%s;
        }
        return x;
    }
    void display()
    {
        int count=0;
        cout<<"Queue contains \n";
        int i=front+1;
        while(i!=rear+1)
        {
             cout <<"element: "<<++count<<": "<<arr[i]<<endl;
             i=(i+1)%s;
        }
        system("pause");
    }
};
int main()
{
    int size;
    cout <<"enter the size of the queue\n";
    cin>>size;
    queue q1(size);
    int value;
    int choice;
     while (choice!=-1)
    {
        system("cls");
        cout <<"press 1 for enqueue element\npress 2 for dequeue element\npress 3 for display current list\npress -1 to EXIT\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
            cout <<"enter element to enqueue\n";
            cin>>value;
            q1.enqueue(value);
            break;
            case 2:
            q1.dequeue();
            break;
            case 3:
            q1.display();
            break;
        } 
    }
    return 0;
}