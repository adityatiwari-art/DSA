#include <iostream>
using namespace std;
// bubble sort in fingertips--->not adaptale by default but stable ,O(n^2) in all cases ,can be made adaptable as shown here with complexity of O(n)--->only n comparisions
void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
// not stable not adaptable since require comparisons o(n^2)
void selection(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int pos=i; //the variable pos should be initialized inside the first loop and must be initialised with i otherwise wrong answer if pos is not set
        int min = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                pos = j;
            }
        }
        swap(arr[pos], arr[i]);
    }
}
// only your logic no need for no of passes and comparisions--->stable,adaptable in O(n)
void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (key < arr[j])
            { // inplace of key if you will write arr[i] then it will be wrong since it is modified
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = key;
    }
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
int main()
{
    int size = 9;
    int arr[] = {2, 1, 34, 7, 87, 23, 12, 23, 89};
    printArr(arr, size);
    // bubble(arr,size);
    // insertion(arr,size);
    selection(arr, size);
    printArr(arr, size);
}
// aak ki seekh
// never keep a variable uninitialised (here pos)