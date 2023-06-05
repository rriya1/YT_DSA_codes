#include<bits/stdc++.h>
using namespace std;

void perm_change_case(string,string,vector<string>&);

int main()
{
    string in;
    cout<<"Enter the string: ";
    cin>>in;
    string out="";
    vector<string> s;
    int i=1;
    cout<<"All the permutations of case change are: "<<endl;
    perm_change_case(in,out,s);
    for( auto value : s)
    {
        cout<<i<<". "<<value<<endl;
        i++;
    }
    return 0;
}

void perm_change_case(string in, string out, vector<string> &s)
{
    if(in.length()==0)
    {
        s.push_back(out);
        return;
    }
    string out1,out2;
    out1=out;
    out2=out;
    out1.push_back(toupper(in[0]));
    out2.push_back(in[0]);
    in.erase(in.begin()+0);
    perm_change_case(in,out1,s);
    perm_change_case(in,out2,s);
    return;

}