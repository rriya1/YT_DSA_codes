#include<bits/stdc++.h>
using namespace std;

void recursive_quick(int arr[],int start, int end);
void swap(int arr[],int high, int low);

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

void recursive_quick(int a[], int low, int high)
{
    cout<<"high "<<high<<endl<<"low "<<low<<endl;
    if(high-low>0)
    {
        cout<<"recursive loop"<<endl;
        int i=low;
        int j=high-1;
        cout<<i<<endl<<j<<endl;
    //int k= high;
    while(j>i)   
    {
        cout<<"while loop 1"<<endl;
        while(a[i]<a[high] && i<high)
        {
            cout<<"while loop 2"<<endl;
            i++;
            cout<<i<<endl;
        }
        cout<<"a[i]: "<<a[i]<<endl;
        while(a[j]>a[high] && j>=0)
        {
            cout<<"while loop3"<<endl;
            j--;
            cout<<j<<endl;
        }
        cout<<"a[j]: "<<a[j]<<endl;
        if(i<j)
        {
            swap(a,i,j);
        }  
    cout<<a[i]<<" "<<a[j]<<endl;
    cout<<"a[high] "<<a[high]<<" a[i] "<<a[i]<<endl;
    }
    if(i!=j)
    {
        swap(a,i,high);
        cout<<"a[high] "<<a[high]<<" a[i] "<<a[i]<<endl;
        recursive_quick(a,low,j);
        recursive_quick(a,i,high);
    }
    else{
        if(a[i]>a[high] && high-low==1)
        {
            cout<<"annoying a[i] "<<a[i]<<endl<<"a[high] "<<a[high]<<endl;
            swap(a,i,high);
            cout<<"after swap<<endl";
            cout<<"annoying a[i] "<<a[i]<<endl<<"a[high] "<<a[high]<<endl;
        }
    }
    }
}
    

// void recursive_quick(int arr[],int size, int start, int end)
// {
//    int low, high, pivot, flag;
//    //pivot=arr[end];
//    low= start;
//    high=end-1;
//    while(low<high)
//    {
//     while(arr[low]<arr[end])
//     {
//         low++;
//     }
//     while(arr[high]>arr[end])
//     {
//         high--;
//     }
//     while(low<high)//for when array got totally sorted
//     {
//         swap(arr,low,high);
//     }
//       //swap pivot with low
//       if(size%2==0)
//       {
//         swap(arr,end,low);
//       }
//       else{swap(arr,end,low-1);}
//     //recursive call now
//     recursive_quick(arr,low-start+1,start,low);
//     recursive_quick(arr,end-low,low-1,end);
//    }
// }
//    while(low=<high)
//    {
//     flag=0;
//     if(arr[low]<arr[end])
//     {
//         flag=1;
//         low++;
//     }
//     if(arr[high]>arr[end])
//     {
//         flag=2;
//         high--;
//     }
//     if(flag!=0)
//     {
//         goto x;
//     }
//     else
//     {
//         if(size%2==0)
//         {
//             swap(arr,low,high);
//         }
//         if(size%2==0)
//         {
//             swap(arr,low-1,high);
//         }
//         low++;
//         high--;
//     }
//     x:
//     // if(flag==1)
//     // {
//     //     high--;
//     // }
//     // if(flag==2)
//     // {
//     //     low++;
//     // }
//     cout<<" ";
//    }
//    if(end-low>1)
//    {
//         recursive_quick(arr,low-start+1,start,low);
//         recursive_quick(arr,end-low,low+1,end);
//    }
   

