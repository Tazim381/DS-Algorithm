#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int tree[100000];

int query(int n, int b, int e, int l , int r)
{
    if(l>e || r<b)
    {
        return INT_MAX;
    }
    if(b>=l && e<=r)
    {
        return tree[n];
    }

    int mid = (b+e)/2;
    int left = 2*n;
    int right = 2*n+1;
   int p = query(left, b, mid, l ,r);
    int q = query(right, mid+1, e, l ,r);

    return min(p,q);

}
void buildtree(int n, int b, int e)
{
    if(b==e)
    {
        tree[n]= arr[b];
        return;
    }
    int left = 2*n;
    int right = 2*n+1;
    int mid = (b+e)/2;
    buildtree(left,b,mid);
    buildtree(right,mid+1,e);

    tree[n]= min(tree[left], tree[right]);

}

void update(int n, int b, int e, int i, int val)
{
    if(i>e || i< b)
    {
        return;
    }
    if(b==e==i)
    {
        tree[n]= val;
    }
    int mid = (b+e)/2;
    int left = 2*n;
    int right = 2*n+1;
    update(left, b, mid, i, val);
    update(right,mid+1,e, i, val);
    tree[n]= min(tree[left], tree[right]);


}
int main()
{
    int i,j,m,n;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    buildtree(1,1,n);

    cout<<query(1,1,n,1,3);

}
