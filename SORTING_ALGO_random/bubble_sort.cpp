#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int size);

int main()
{
    int arr_size;
    cout<<"enter the size of the array"<<endl;
    cin>>arr_size;
    int arr[arr_size];
    for(int i=0;i<arr_size;i++)
    {
        cin>>arr[i];
    }
    bubble_sort(arr,arr_size);
    for(int i=0;i<arr_size;i++)
    {
        cout<<arr[i]<<" ";
    }
    getchar();
    return 0;
}

void bubble_sort(int a[], int s)
{
    int temp;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s-1-i;j++)
        {
            int l_value=j;
            int r_value=j+1;
            if(a[l_value]>a[r_value])
            {
                temp=a[r_value];
                a[r_value]=a[l_value];
                a[l_value]=temp;
            }
        }
    }
}
