#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int size);

int main()
{
    int size;
    cout<<"enter the size of the array:\t";
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
        cout<<endl;
    }
    insertion_sort(a,size);
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

void insertion_sort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        int index=-1;
        int temp=arr[i];
        for(int j=i-1;j>=0;j--)
        {
            if(temp<arr[j])   // if condition lgane ki zarurat hi nahi thi agar for loop ko aese likho toh: for(int j=i-1; j>=0 && a[j]>temp;j--) uske baad if block ke andar waala code likhdena tha andar.
            {
                arr[j+1]=arr[j];
                index=j;
            }
            else
            {
                goto x;
            }
        }
        cout<<"flow comes here only when array not sorted";
        arr[index]=temp;
        x:
        cout<<"skip "<<i;
    }
}

