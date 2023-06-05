#include<bits/stdc++.h>
using namespace std;

void m_bubble(int a[],int s);

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
    m_bubble(a,size);
    for(int i=0;i<size;i++)
    {
        cout<<a[i];
        cout<<endl;
    }
    getchar();
    return 0;
}

void m_bubble(int arr[], int s)
{
    int temp;
    int flag;
    for(int i=0;i<s-1;i++) //imp: agar loop s tak chalaya then ek faltu iteration, where j<0 chalega anf flag will always be 0 there because andar waala loop chalega hi nahi, so already sorted will get printed everytime. To solve this problem we have iterated i from 0 to s-1.
    {
        flag=0;
        for(int j=0;j<s-1-i;j++)
        {
            int l_value=j;
            int r_value=j+1;
            if(arr[l_value]>arr[r_value])
            {
                temp=arr[l_value];
                arr[l_value]=arr[r_value];
                arr[r_value]=temp;
                flag++;
            }
            
        }
        if(flag==0)
            {
                cout<<"already sorted"<<endl;
                break;
            }
    }
}