#include<bits/stdc++.h>
using namespace std;
int tree[100000];

int query(int idx, int n)
{
    int sum = 0;
    while(idx>0)
    {
        sum+= tree[idx];
        idx-= (idx)&(-idx);
    }
    return sum;
}
void buildtree(int idx, int val, int n)
{
    while(idx<=n)
    {
        tree[idx]+= val;
        idx+= (idx)&(-idx);

    }
}
int main()
{
    int i,j,m,n,a,b;

    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        buildtree(i,a,n);

    }
    cout<<query(3,n)<<endl;

}
