#include<iostream>
using namespace std;
int partition(int arr[],int l, int h)
{
    int pivot=arr[h];
    int i=l-1;
    int j=h;
    for (int j = l; j < h; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;

}
void quicksort(int arr[], int l, int h)
{
    int partitionindex;
    if(l<h)
    {
        int partitionindex=partition(arr,l,h);
        quicksort(arr,l,partitionindex-1);
        quicksort(arr, partitionindex+1,h);
    }
}
void print(int arr[],int n)
{
    for (int i=0;i<n;i++)
    cout<<arr[i]<<"\n";
}
int main()
{
    int arr[]={5,3,2,1,3};
    print(arr,5);
    cout <<"after apply quick sort\n";
    quicksort(arr,0,5-1);
    print (arr,5);

    return 0;
}