#include <iostream>
using namespace std;
// void display(int size,int arr[]);
// void set_array(int size,int arr[]);
// void insertion(int size,int arr[]);
// int main()
// {
//     int size, capacity;
//     std::cout << "enter size and capacity:";
//     std::cin >> size;
//     std::cin >> capacity;
//     int arr[size];

//     //  arr[] is a shorthand for *arr and array is always passed by reference
//     set_array(size,arr);
//     std::cout << "array before insertion" << std::endl;
//     display(size,arr);
//     insertion(size,arr);
//     size++;
//     std::cout << "array after insertion" << std::endl;
//     display(size,arr);
//     std::cout<<"size is "<<size<<std::endl;
// }
// void display(int size,int arr[]){
//     for (int i = 0; i < size; i++)
//     {
//         std::cout << arr[i] << "\t";
//     }
// }
// void set_array(int size,int arr[]){

//     for (int i = 0; i < size; i++)
//     {
//         std::cin >> arr[i];
//     }
// }
// void insertion(int size,int arr[]){
//     int pos,ele;
//     std::cout << "\nenter position for insertion and element to be inserted :";
//     std::cin >> pos >> ele;
//     for (int i = size - 1; i >= pos - 1; i--)
//     {
//         arr[i + 1] = arr[i];
//     }
//     arr[pos - 1] = ele;
// }

// insertion in sorted array
int insertion_check(int arr[], int ele);
void insertion(int arr[], int pos, int ele);
void display(int size, int arr[]);
int main()
{
    int arr[100] = {1, 12, 34, 56, 72,567,3456,11234,323435,65657786};
    display(10, arr);
    int ele, pos;
    cout << "enter element to be inserted : ";
    cin >> ele;
    pos = insertion_check(arr, ele);
    insertion(arr, pos, ele);
    display(11, arr);
}

int insertion_check(int arr[], int ele)
{
    int ub, lb, mid, pos;
    ub = 9;
    lb = 0;
    while (ub >= lb)
    {
        mid = (lb + ub) / 2;
        if (ele == arr[mid])
        {
            return mid + 1;
        }
        if (ele > arr[mid])
        {
            lb = mid + 1;
            pos = lb; // Update the position here
        }
        else if (ele < arr[mid])
        {
            ub = mid - 1;
            pos = mid; // Update the position here
        }
    }
    return pos; // Return the position
}
void insertion(int arr[], int pos, int ele)
{
    for (int i = 9; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[pos] = ele;
}
void display(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << "\t";
    }
}