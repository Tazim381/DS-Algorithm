#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int tree[100000];

void buildtree(int n, int b, int e)
{
    if(b==e)
    {
        tree[n]= arr[e];
        return;

    }
    int mid = (b+e)/2;
    int left = 2*n;
    int right = 2*n+1;

    buildtree(left,b,mid);
    buildtree(right,mid+1,e);
    tree[n]= min(tree[left], tree[right]);

}

int query(int n, int b, int e, int l, int r)
{
    if(l>e || r<b)
    {
        return INT_MAX;
    }
    if(l<=b && r>= e)
    {
        return tree[n];
    }

    int mid = (b+e)/2;
    int left = 2*n;
    int right = 2*n +1;
    int q = query(left,b, mid, l, r);
    int p = query(right,mid+1,e, l ,r);
    return min(p,q);
}
void buildtree(int n, int b, int e, int i, int newval)
{
    if(l>e || r<b)
    {
        return;
    }
    if(b==e && e==i)
    {
        tree[n]+= newval;
        return;

    }
    int mid = (b+e)/2;
    int left = 2*n;
    int right = 2*n+1;

    buildtree(left,b,mid);
    buildtree(right,mid+1,e);
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
