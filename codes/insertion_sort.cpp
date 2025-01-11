#include<iostream>
using namespace std;
void insertion_srt(int arr[],int n)
{
    int key;
    int p=1;
    int loop_count=0;
    for (int i=1;i<n;i++)
    {
        key =arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key)
        {
            loop_count++;
            arr[j+1]=arr[j];
            j=j-1;
    }
        arr[j+1]=key;
         }
         cout <<loop_count<<endl;
}
void display(int arr[],int n)
{
    int i=0;
    cout <<"sorted array\n";
    while(i<n)
    {
        cout <<arr[i]<<endl;
        i++;
    }
}
int main()
{
    int size;
    cout <<"enter the siz of te array\n";
    cin>>size;
    int *arr=new int(size);
    cout <<"enter the data in array\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
insertion_srt(arr,size);
display(arr,size);
    return 0;
}