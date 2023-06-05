#include<bits/stdc++.h>
using namespace std;

void merge_sort(int arr[],int lo_b, int up_b);
void merge(int arr[],int lb, int mid, int ub);

int main()
{
    int size;
    cout<<"Enter the size of the array:\t";
    cin>>size;
    int a[size];
    cout<<"\nenter the elements: ";
    int i=0;
   for(int i=0;i<size;i++)
   {
    cin>>a[i];
   }
   //okay till here
    int ub=size-1;
    int lb=0;
    merge_sort(a,lb,ub);
    cout<<"\nsorted array is: \n";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

void merge_sort(int a[],int lo_b, int up_b)
{
    //cout<<"reached inside merge sort";
    int mid;
    mid=(up_b+lo_b)/2;
    if(lo_b<up_b)
    {
        
        //cout<<"                in while              ";
        merge_sort(a,lo_b,mid);
        merge_sort(a,mid+1,up_b);
        merge(a,lo_b,mid,up_b);
    }
}

void merge(int a[], int low,int mid, int up)
{
   // cout<<"merge"<<endl;
    int b[up+1];
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=up)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
           // cout<<"b[k]\t"<<b[k]<<endl;
        }
        else
        {
            b[k]=a[j];
            j++;
            //cout<<"bk2: "<<b[k]<<endl;
        }
        k++;
    }

    if(i>mid){
        while(j<=up)
        {
            b[k]=a[j];
             //cout<<"bk3: "<<b[k]<<endl;
            j++;k++;
        }
    }
    else{
        while(i<=mid)
        {
            b[k]=a[i];
            //cout<<"bk4: "<<b[k]<<endl;
            i++;k++;
            
        }
    }

    for(int l=low;l<up+1;l++)
    {
        a[l]=b[l];
    }
    //  for(int l=0;l<up+1-low;l++)
    // {
    //     cout<<"bL"<<b[l]<<endl;
    // }


    //     int temp=low;
    //     cout<<"low: "<<low<<endl;
    // for(int l=0;l<up+1-temp;l++)
    // {
    //     a[low]=b[l];
    //     low++;
    //     cout<<"l2 "<<low<<endl;
    // }
    // for(int i=temp;i<=up;i++)
    // {
    //     cout<<a[i];
    // }
    //cout<<endl;
}