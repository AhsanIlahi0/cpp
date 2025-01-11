#include<iostream>
using namespace std;
void binary_search(int arr[],int n,int val)
{
    
int    first=0;
int last =n-1;
bool found=false;
while(first<=last)
{
   int mid=(first+last)/2;
    if(arr[mid]==val)
    {found =true;
        break;
    }
    else if(arr[mid]<val)
    {
        first=mid+1;
    }
    else{
        last=mid-1;
        
    }
    
}
if(found ==true)
    {
        cout <<val<<" found in array\n";
    }
    else{
        cout<<"value not found\n";
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
binary_search(arr,size,7);

    return 0;
}