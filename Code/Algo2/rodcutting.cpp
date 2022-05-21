#include<bits/stdc++.h>
using namespace std;

int rodcutting(int price[], int l)
{
    int profit[100000];
     profit[0]=0;
     int maxprofit;
    for(int i=1; i<=l; i++)
    {
         maxprofit = INT_MIN;
        for(int j=0;j<i; j++)
        {
            maxprofit = max(maxprofit,price[j]+profit[i-j-1]);
            profit[i]=maxprofit;
        }
    }
    return maxprofit;
}
int main()
{
    int i,j,m,n,a,b;
    int price[]= {1,5,8,9,10,17,17,20};
    int rodlength = 8;
    cout<<rodcutting(price,rodlength);
}
