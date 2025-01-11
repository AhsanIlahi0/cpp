#include<iostream>
using namespace std;
class queue
{
    
    int front=-1;
    int rear=-1;
    int *arr;
    int s;
    public:
    queue(int size)
    {
        s=size;
        arr=new int[size];
    }
    
    bool isEmpty()
    {
        if(rear==front)
        {
            rear=front=-1;
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if(rear==s-1)
        {
            return true;
        }
        return false;
    }
    int enqueue(int val)
    {
        if(isFull())
        {
            cout <<"over Flow\n";
            system("pause");
            return 0;
        }
        else
        {
            rear++;
        }
        arr[rear]=val;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow\n";
            system("pause");
            return -1;
        }
        else {
            front++;
            return arr[front];
        }
    }
    void display()
    {
        int count=0;
        cout<<"Queue contains "<<rear-front<<" elements\n";
        for (int i=front+1;i<=rear;i++)
        {
            cout <<"element: "<<++count<<": "<<arr[i]<<endl;
        }
        system("pause");
    }
        
};
int main()
{   int size;
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