#include<bits/stdc++.h>
using namespace std;

void solve(int,int,string,vector<string>&);

int main()
{
    cout<<"Enter a number which is equal to the number of opening and closing parenthesis: ";
    int n;
    cin>>n;
    int open, close;
    open=n;
    close=n;
    string out =" ";
    vector<string> s;
    solve(open,close,out,s);
    cout<<"\nAll balaced permutation of the parenthesis are: "<<endl;
    int i=1;
    for(auto value : s)
    {
        cout<<i<<". "<<value<<endl;
        i++;
    }
    return 0;
}

 void solve(int open,int close,string out,vector<string>&s)
{
    if(open==0 && close==0)
    {
        s.push_back(out);
        return;
    }
    //when adding opening brackets
    if(open!=0)
    {
        string out1=out;
        out1.push_back('(');
        //open--;
        solve(open-1,close,out1,s);
    }
    //when adding closing brackets
    if(open<close)
    {
        string out2=out;
        out2.push_back(')');
        //close--;
        //open--;
        solve(open,close-1,out2,s);
    }
    return;
}
