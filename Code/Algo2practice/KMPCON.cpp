#include<bits/stdc++.h>
using namespace std;
int lps[10000000];
vector<int>v;

void kmpsearch(string str, string ptr)
{
    int N = str.size();
    int M = ptr.size();
    int i=0;
    int j= 0;
    while(i<N)
    {
        if(str[i]==ptr[j])
        {
            i++;
            j++;
        }
        if(j==M)
        {
            v.push_back((i-j)+1);
            j = lps[j-1];
        }
        else if (i < N && ptr[j] !=str[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

}
void computearray(string ptr)
{
    int M = ptr.size();
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<M)
    {
        if(ptr[i]==ptr[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
void init()
{
    v.clear();
}
int main()
{
    int i,j,m,n,M;
    string str;
    string ptr;
    int t=0;
    int r;
    cin>>r;
    while(r--)
    {
     init();
     if(t>0) cout<<endl;

    cin>>str>>ptr;
    computearray(ptr);
    kmpsearch(str,ptr);
    if(v.size())
    {
       cout<<v.size()<<endl;
    for(i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    }
    else
    {
        cout<<"Not Found"<<endl;
    }
    t++;

    }

}
