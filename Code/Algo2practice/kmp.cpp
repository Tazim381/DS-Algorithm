
#include<bits/stdc++.h>
using namespace std;
int lps[10000];

void computearray(string ptr)
{
    int i,j,m,n;
    n= ptr.size();
    int len=0;
    i=1;

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
                len = lps[i-1];
            }
            lps[i]=0;
            i++;
        }

    }


}
int  kmpsearch(string  str, string ptr)
{
   int n = str.size();
   int m = ptr.size();
   int count=0;
   int i=0, j=0;

   while(i<n)
   {
       if(str[i]= ptr[j])
       {
           i++;
           j++;
       }
       if( j==m)
       {
           count++;
           j = lps[j-1];
       }
       else if(str[i]!= ptr[j])
       {
           if(j!=0)
           {
               j =  lps[j-1];
           }

          i++;
       }

       /* else if (i < N && ptr[j] !=str[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }*/
   }
   return count;
}

int main()
{
    int i,j,m,n;
    string str,ptr;
    cin>>str>>ptr;
    computearray(ptr);
    cout<<kmpsearch(str,ptr);


}
