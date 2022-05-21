#include<bits/stdc++.h>
using namespace std;
int tree[1000000];
int arr[1000000];

int query(int n, int b, int e,int l , int r)
{
    if(l>e||r<b)
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

    int p = query(left,b,mid,l,r);
    int q = query(right,mid+1,e,l,r);
    return min(p,q);

}

void buildtree(int n, int b, int e)
{
    if(e==b)
    {
        tree[n]= arr[e];
        return;
    }
    int mid =(e+b)/2;
    int left = 2*n;
    int right = 2*n+1;
    buildtree(left,b,mid);
    buildtree(right,mid+1,e);
    tree[n] = min(tree[left],tree[right]);

}

void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{

    int i,j,m,n;
    cin>>n;
    for(i=1; i<=n ;i++)
    {
        cin>>arr[i];
    }
    buildtree(1,1,n);

    cout<<query(1,1,n,1,3)<<endl;


}
