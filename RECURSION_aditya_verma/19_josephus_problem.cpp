//solved
#include<bits/stdc++.h>
using namespace std;

void josephus(vector<int> n,int index,int k, int &ans)
{
    if(n.size()==1)
        {
            ans=n[0];
            return;
        }
    
    int killed=(index+k)%(n.size());
    n.erase(n.begin()+killed);
    josephus(n,killed,k,ans);
    return;
}


int main()
{
    cout<<"enter the number of people: ";
    int n;
    cin>>n;
    vector<int> people;
    for(int i=1;i<=n;i++)
        people.push_back(i);
    cout<<endl<<"enter the kth number: ";
    int k;
    cin>>k;
    int index=0;

    int left;
    josephus(people,index,k-1,left);
    cout<<endl<<"the remaining person is: "<<left;
    return 0;
}

