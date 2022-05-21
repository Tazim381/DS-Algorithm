#include<bits/stdc++.h>
using namespace std;
int tree[10000];
int arr[100000];

void buildtree(int n, int l, int r)
{
    if(l==r)
    {
        tree[n]=arr[l];
        return;
    }
    int mid = (l+r)/2;
    int left = 2*n;
    int right = 2*n+1;
    buildtree(left,l,mid);
    buildtree(right,mid+1, r);
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
int main()
{
    int i,j,m,n;
    cin>>n;
    for(i=1; i<=n ; i++)
    {
        cin>>arr[i];
    }
    buildtree(1,1,n);
    for(i=0; i<2*n; i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    cout<<query(1,1,n,1,3);

}
