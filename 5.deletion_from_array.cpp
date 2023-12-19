#include <iostream>
using namespace std;
void display(int arr[], int size);
void set(int arr[], int size);
int delete_ele(int arr[], int pos,int size);
int main()
{
    int size;
    cout << "enter the size of the array:";
    cin >> size;
    int arr[size];
    set(arr, size);
    display(arr, size);
    int pos;
    cout << "enter pos of element to be deleted:";
    cin >> pos;
    size=delete_ele(arr, pos,size);
    cout<<"final array is ";
    display(arr,size);
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void set(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}
int delete_ele(int arr[],int pos,int size){
    for (int i = pos-1; i < size; i++)
    {
    arr[i]=arr[i+1];
    }
    cout<<"deletion done"<<endl;
    return --size;
}