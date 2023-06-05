#include<bits/stdc++.h>
using namespace std;

void recursive_quick(int arr[],int start, int end);
void swap(int arr[],int high, int low);
int quick_partition(int arr[],int low,int high);

int main()
{
    int size;
    cout<<"Enter the size of the array:\t";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int start=0;
    int end=size-1;
    recursive_quick(arr,start,end);
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

void swap(int arr[],int low,int high) 
{   //swap wokring alright
    // cout<<"swap a[high]"<<arr[high]<<endl;
    // cout<<"swap a[low]"<<arr[low]<<endl;
    int temp;
    temp=arr[high];
    arr[high]=arr[low];
    arr[low]=temp;
}

int quick_partition(int a[],int low,int high)
{
    cout<<"inside partition"<<endl;
    cout<<low<<" "<<high<<endl;
    int pivot = a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a,j,i);
        }
    }
    swap(a,i+1,high);
    return i+1;


}

void recursive_quick(int a[], int low, int high)
{
    cout<<"inside quick"<<endl;
    cout<<low<<" "<<high<<endl;
    if(low<high)
    {
        cout<<"low<high"<<endl;
        int partition = quick_partition(a,low,high);
        recursive_quick(a,low,partition-1);
        recursive_quick(a,partition+1,high);
    }
    
}


// Quick sort in C++

// #include <iostream>
// using namespace std;

// void swap(int *a, int *b) {
//   int t = *a;
//   *a = *b;
//   *b = t;
// }

// void printArray(int array[], int size) {
//   int i;
//   for (i = 0; i < size; i++)
//     cout << array[i] << " ";
//   cout << endl;
// }

// int partition(int array[], int low, int high) {

//   int pivot = array[high];
//   int i = (low - 1);

//   for (int j = low; j < high; j++) {
//     if (array[j] <= pivot) {
  
//       i++;
//       swap(&array[i], &array[j]);
//     }
//   }

//   swap(&array[i + 1], &array[high]);

//   return (i + 1);
// }

// void quickSort(int array[], int low, int high) {
//   if (low < high) {
//     int pi = partition(array, low, high);


//     quickSort(array, low, pi - 1);

//     quickSort(array, pi + 1, high);
//   }
// }


// int main() {
//   int data[] = {2,7,6,1,0};
//   int n = sizeof(data) / sizeof(data[0]);
  
//   cout << "Unsorted Array: \n";
//   printArray(data, n);
  

//   quickSort(data, 0, n - 1);
  
//   cout << "Sorted array in ascending order: \n";
//   printArray(data, n);
// }

