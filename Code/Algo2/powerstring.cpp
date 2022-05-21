#include<iostream>
#include<vector>
#include<string.h>
#include<cstdio>
using namespace std;
int lps[2000020];
vector<int>v;


int computearray(string ptr)
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

    return lps[M-1];


}

int main()
{

    int i,j,m,n,M,z;
    string str;
    char ptr[2000020];
    int t=0;
   while(1)

{

    scanf("%s",ptr);
    if(ptr[0]=='.') break;
    int k=1;
    int r =computearray(ptr);
    int c = strlen(ptr)- r;
    m = strlen(ptr);

    if(m%c==0)
    {
        printf("%d\n",m/c);
    }
    else
    {
        printf("%d\n",k);

    }

}



}
