#include<iostream>
using namespace std;
void bubble_sort(int arr[],int size)
{int loop_count=0;
    for(int i=0;i<size;i++)
    {
        bool Swap=false;
        for (int j=0;j<size;j++)
        {
            if(arr[j]>arr[j+1])
            {
                Swap=true;
                swap(arr[j],arr[j+1]);
            }
            loop_count++;
            
        }
        if(Swap==false)
            {
                break;
            }
    }
    cout <<loop_count<<endl;
}
void display(int arr[],int size)
{
    for (int i=0;i<size;i++)
    {
        cout <<"arr "<<i+1<<": "<<arr[i]<<endl;
    }
}
int main()
{
    int size;
    cout <<"ente rthe size of the array\n";
    cin>>size;
    int *arr=new int(size);
    cout <<"enter the elemnts of the array\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    bubble_sort(arr,size);
    display(arr,size);

    return 0;
}