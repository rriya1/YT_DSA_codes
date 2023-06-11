//solved
#include<bits/stdc++.h>
using namespace std;

void print_string(string,int);
void print_subsets(string,string,int&);


int main()
{
    string s;
    int size;
    cout<<"enter the size of the string: ";
    cin>>size;
    cout<<"Enter the string: ";
    for(int i=0;i<size;i++)
    {
        char c;
        cin>>c;
        s.push_back(c);
    }
    int count=0;
    cout<<"The string is: ";
    print_string(s,size);
    cout<<endl;
    string op="";
    cout<<"The subsets of the string are: "<<endl;
    print_subsets(s,op,count);
}

void print_string(string s,int size)
{
    if(s.length()==0)
    {
        return;
    }
    char val=s[size-1];
    s.pop_back(); //deletes from the last of the string
    //s,erase(s.begin()+0) //to dlete from the start of the string
    print_string(s,s.length());
    cout<<val;
    return;
}

void print_subsets(string ip,string op,int &count)
{
    //cout<<"inside"<<endl;
    
    if(ip.length()==0)
    {
        count++;
        cout<<count;
        print_string(op,op.length());
        cout<<endl;
        return;
    }
    string op1,op2;
    op1=op;
    op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    print_subsets(ip,op1,count);
    print_subsets(ip,op2,count);
    return;
}