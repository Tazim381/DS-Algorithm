
#include<bits/stdc++.h>
using namespace std;
int tree[1000];

int query(int idx, int idx1)
{
    idx= idx+1;
    idx1 = idx1+1;
    int sum =0;
    int sum1=0;
    while(idx>0)
    {
        sum+= tree[idx];
        idx-=(idx)&(-idx);
    }
    while(idx1>0)
    {
        sum1+=tree[idx1];
        idx1-=(idx1)&(-idx1);
    }
    return (sum1-sum);
}
void update(int index, int val, int n)
{
    index = index+1;
    while(index<=n)
    {
      tree[index]+= val;
      index+= (index)&(-index);
    }

}

int main()
{
    int i,j,m,n,a,b,x;
    cin>>n;
    for(i=0 ;i<n ; i++)
    {
        tree[i]= 0;
    }

    for(i=0; i<n; i++)
    {
       cin>>x;
       update(i,x,n);
    }
    cout<<"Enter range "<<endl;
    cin>>a>>b;
    cout<<query(a-1,b)<<endl;;
}

