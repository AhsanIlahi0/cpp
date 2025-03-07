#include <iostream>
using namespace std;

int main()
{
    int range, val;
    int length;
    cout <<"enter the range of your array: ";
    cin>>range;
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
            cout <<"plz enter the value in the given range "<<range<<endl;
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
    for (int i=0;i<=range;i++){
        for(int j=0;j<rng[i];j++){
            cout <<i <<" ";
        }
    }
    return 0;
}