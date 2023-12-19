#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {                     // n-1 passes also keeping track on the element just after the sorted part or the element to be inserted
        int j;            // since we need it outside loop so declared here
        int ele = arr[i]; // insertion sort is not about swaping its about shifting so kept the i the element as key or ele
        for (j = i - 1; j >= 0; j--)
        {
            if (ele < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break; // come out of the loop taking that j
            }
        }
        arr[j + 1] = ele; // done here because lets take i=1 so j=0 will shift but not place the key there since loop condition fills
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int size = 9;
    int arr[size] = {7, 5, 9, 2, 10, 23, 12, 34, 29};
    display(arr, size);
    insertionSort(arr, size);
    display(arr, size);
}
