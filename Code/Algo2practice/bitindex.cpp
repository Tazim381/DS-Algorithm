#include<bits/stdc++.h>
using namespace std;
int tree[100000];

int query(int idx, int idx1)
{
    int sum=0;
    int sum1=0;
    while(idx>0)
    {
        sum+= tree[idx];
        idx-= (idx)&(-idx);
    }
    while(idx1>0)
    {
        sum1 += tree[idx1];
        idx1 -= (idx1)&(-idx1);
    }
    return (sum1 - sum);

}

void update(int index, int val, int n)
{
  while(index<=n)
  {
      tree[index]+= val;
      index += (index)&(-index);
  }

}

int main()
{
    int i,j,m,n,x;
    cin>>n;
    for(i=0; i<= n; i++)
    {
        tree[i]==0;
    }
    for(i=1; i<=n; i++)
    {
        cin>>x;
        update(i,x,n);
    }
    cout<<"YES"<<endl;
    cout<<query(2-1,4)<<endl;

}
