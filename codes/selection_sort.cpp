#include<iostream>
using namespace std;
void selection_sort(int arr[],int size)
{
    int loop_coutn=0;
    for (int i=0;i<size;i++)
    {
        int min_index=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
loop_coutn++;
        }   
        swap(arr[i],arr[min_index]);
    }
    cout <<loop_coutn<<endl;
}
void show(int arr[],int size)
{
    for (int i=0;i<size;i++)
    {
        cout<<i+1<<": element "<<arr[i]<<endl;    
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
    selection_sort(arr,size);
    show(arr,size);
    return 0;
}