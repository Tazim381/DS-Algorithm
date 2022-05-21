#include<bits/stdc++.h>
using namespace std;
int lps[100000];


int kmpsearch(string str, string ptr)
{
    int n = str.size();
    int m = ptr.size();
    int i=0;
    int j=0;
    int count=0;
    while(i<n)
    {
        if(str[i]==ptr[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            count++;
            j= lps[j-1];
        }
        else if(str[i]!= ptr[j])
        {
            if(j!=0)
            {
                j= lps[j-1];
            }
            else i++;
        }
    }
}
void computearray(int ptr)
{
    int n = ptr.size();
    lps[0]=0;
    int i=1;
    int len=0;
    while(i<n)
    {
        if(ptr[i]==ptr[len])
        {
            len++;
            lps[i]= len;
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
int main()
{
    int i,j,m,n;
    string str,ptr;
    cin>>str>>ptr;

    computearray(ptr);
    cout<<kmpsearch(str,ptr);

}
