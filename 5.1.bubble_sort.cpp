#include <iostream>
using namespace std;
int main()
{int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    // non adaptable bubble sort 
    // for(int i=0;i<n-1;i++)
    // {
    //     for(int j=0;j<n-i-1;j++){
    //         if(arr[j]>arr[j+1]){
    //             int temp=arr[j];
    //             arr[j]=arr[j+1];
    //             arr[j+1]=temp;
    //         }
    //     }
    // }
    // adaptable bubble sort-if the array is  sorted at any pass then do not do more passes
    
       for(int i=0;i<n-1;i++)
    {
        
        cout<<"current passs is:" <<i+1<<endl;
        int is_sorted=0;  //then stops at the pass when the sorting is completed
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                is_sorted=1;
            }
        }
         if(is_sorted==0){
            break;
        }
    }
        for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
} 