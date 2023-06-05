#include<bits/stdc++.h>
using namespace std;

void unique_subset(string,string,set<string>&);

int main()
{
    string in;
    cout<<"Enter the string:\t";
    cin>>in;
    cout<<"\nThe unique subsets of the string are:\t";
    set<string> sub;
    string out="";
    unique_subset(in,out,sub);
    int i=1;
    for(auto value : sub)
    {
        cout<<i<<". "<<value<<endl;
        i++;
    }
    return 0;
}

void unique_subset(string in,string out,set<string> &sub)
{
    if(in=="")
    {
        sub.insert("");
        return;
    }
    string out1,out2;
    char i=in[0];
    in.erase(in.begin()+0);
    out1=out;
    out2=out;
    out2.push_back(i);
    sub.insert(out1);
    sub.insert(out2);
    unique_subset(in,out1,sub);
    unique_subset(in,out2,sub);
    return;
}