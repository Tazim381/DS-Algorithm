#include<bits/stdc++.h>
using namespace std;
int tree[100000];

int query(int arr[], int n, int l, int r)
{
    int sum=0;
    int segmentsize = sqrt(n);
    while(l<=r&&l%segmentsize!=0)
    {
        sum+= arr[l];
        l++;
    }

     while(l<=r)
     {
         sum+= tree[l/segmentsize];
         l+= segmentsize;
     }
     while(l<=r)
     {
         sum+= arr[l];
         l++;
     }

     return sum;


}
void buildtree(int arr[], int n)
{
    int segSiz =sqrt(n);
    int segment = -1;
    for(int i=0; i<n ;i++)
    {
        if(i%segSiz==0)
        {
            segment++;
        }
        tree[segment]+=arr[i];
    }

}
int main()
{
    int i,j,m,n,a,b;
    cin>>n;
    int arr[n+10];
    for(i=0; i<n ;i++)
    {
        cin>>arr[i];
    }
    buildtree(arr,n);

    cout<<query(arr,n,2,4);
}
