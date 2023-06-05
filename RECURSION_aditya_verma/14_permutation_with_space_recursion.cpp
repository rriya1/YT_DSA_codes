#include<bits/stdc++.h>
using namespace std;

void perm_space(string,string,vector<string>&);

int main()
{
    string in;
    cout<<"Enter the string:\t";
    cin>>in;
    cout<<"\nThe permuation of the string with spaces  are:\n";
    vector<string> p;
    string out;
    out.push_back(in[0]);
    in.erase(in.begin()+0);
    perm_space(in,out,p);
    int i=1;
    for(auto value : p)
    {
        cout<<i<<". "<<value<<endl;
        i++;
    }
    return 0;
}

void perm_space(string in,string out,vector<string> &sub)
{
    if(in.length()==0)
    {
        sub.push_back(out);
        return;
    }
    string out1,out2;
    out1=out;
    out2=out;
    //char space =' ';
    out1.push_back(' ');
    out1.push_back(in[0]);
    out2.push_back(in[0]);
    in.erase(in.begin()+0);
    perm_space(in,out1,sub);
    perm_space(in,out2,sub);
    return;
} 