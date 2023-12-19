#include<iostream>
using namespace std;
// non adaptable bubble sort 
void bubbleSort(int arr[],int n){
    // int n= sizeof(arr)/sizeof(int);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
            else
                continue;
        }
    }
}
// adaptable bubble sort 
void adaptableBubbleSort(int arr[],int n){
    // int n= sizeof(arr)/sizeof(int);
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=1;
            }
            else
                continue;
        }
        cout<<"pass no is "<<i+1<<endl;;
        if(flag==0){
            break;
        }
    }
}

void displayArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
int arr[]={7,11,19,22,170,230,240};
int n=sizeof(arr)/sizeof(int);
cout<<"before sorting:  ";
displayArr(arr,n);
// bubbleSort(arr,n);
adaptableBubbleSort(arr,n);
cout<<"after sorting:  ";
displayArr(arr,n);
}