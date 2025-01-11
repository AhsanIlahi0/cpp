#include <iostream>
using namespace std;
int main()
{
    system("cls");
    int range, val;
    int length;
    input_range:
    cout <<"enter the range of your array: ";
    cin>>range;
    if(range <0){
        cout <<"enter the valid range\n";
        system("pause");
        system("cls");
        goto input_range;
    }
    cout <<"now enter the length: ";
    cin>> length;
    int arr[length];
    int rng[range+1];
    for(int i=0;i<length;i++){
        arr[i]=0;
    }
    for(int i=0;i<=range;i++){
        rng[i]=0;
    }
    for (int i=0;i<length;i++){
        input:
        cout <<"element "<<i+1<<": ";
        cin>>val;
        if(val>range||val<=0){
            cout <<"plz enter the value in the given range "<<range<<"\n";
            goto input;
        }
        else{
            arr[i]=val;
        }
    }
    for (int i=0;i<=range;i++){
        int count=0;
        for (int j=0;j<length;j++){
            if(arr[j]==i){
                count++;
            }
        }
        rng[i]=count;  
    }
    cout <<"array after applying counting sort\n";
    for (int i=0;i<=range;i++){
        int element_in_array=1;
        for(int j=0;j<rng[i];j++){
            cout <<"element "<<element_in_array<<": " <<i <<"\n";
            element_in_array++;
        }
    }
    return 0;
}