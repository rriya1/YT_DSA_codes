#include<bits/stdc++.h>
using namespace std;

int min(int arr[], int size, int k);
void selection_sort(int arr[], int size);

int main()
{
    int size;
    cout<<"Enter the size of the array\t";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
        cout<<endl;
    }
    selection_sort(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;;
    }
    return 0;
}

int min(int a[],int size, int k)
{
    int min=k;
    for(int i=k+1;i<size;i++)
    {
        if(a[min]>a[i])
        {
            min=i;
        }
    }
    return min;
}

void selection_sort(int a[],int size)
{
    int m,temp;
    for(int i=0;i<size;i++)
    {
        m=min(a,size,i);
        temp=a[m];
        a[m]=a[i];
        a[i]=temp;
    }
}