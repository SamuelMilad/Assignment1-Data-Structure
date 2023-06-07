#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std::chrono;
using namespace std;

void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int BinarySearch(int arr[], int l, int r, int x)
{
    if (r <= l)
        return (x > arr[l]) ? (l + 1) : l;

    int mid = (l + r) / 2;

    if (x == arr[mid])
        return mid + 1;

    if (x > arr[mid])
        return BinarySearch(arr, mid + 1, r, x);

    return BinarySearch(arr, l, mid - 1, x);
}

void BianryInsertionSort(int arr[], int n)
{
     for (int i = 1; i < n; i++) {
          
           int key = arr[i];
           int j = i - 1;

        int place = BinarySearch(arr, 0, j, key);

        while (j >= place) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void printArray(int arr[], int n)
{
     for (int i = 0; i < n; i++)
        cout << arr[i] << " " ;
     cout << endl;
}


int main()
{

    

    int* ptr;
    int n;
    
    auto f = []() -> int { return rand() % 1000; };
    cin >> n;
    
    ptr = new int[n];
    
    generate(ptr, ptr + n, f);
    
    auto start = high_resolution_clock::now();
    
    insertionSort(ptr, n);
    //printArray(ptr, n);
    
    auto stop = high_resolution_clock::now();
   
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << " microseconds";
    return 0;
}
 