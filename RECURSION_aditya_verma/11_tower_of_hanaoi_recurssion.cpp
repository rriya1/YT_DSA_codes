//how to print steps, cant print em right ;-;
#include<bits/stdc++.h>
using namespace std;

void hanoi_tower(int,string,string,string,int);
void print_string(string);

int main()
{
    int n;
    string s,h,d;
    s="source";
    d="destination";
    h="helper";
    cout<<"Enter the number of disks: ";
    cin>>n;
    int count =0;
    hanoi_tower(n,s,h,d,count);
    return 0;
}

void print_string(string s)
{
    if(s.length()==0)
    {
        return;
    }
    char val=s[s.length()-1];
    s.pop_back();
    print_string(s);
    cout<<val;
    return;
}


void hanoi_tower(int n,string s,string h,string d,int count)
{
    if(n==1)
    {
        cout<<"Step "<<count<<": Moving disk "<<n<<" from ";
        print_string(s);
        cout<<" to ";
        print_string(d);
        cout<<endl;
        count++;
        return;
    }
    hanoi_tower(n-1,s,d,h,count);
    cout<<"Step "<<count<<": Moving disk "<<n<<" from ";
    print_string(s);
    cout<<" to ";
    print_string(d);
    cout<<endl;
    hanoi_tower(n-1,h,s,d,count);
    return;
}