#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lookup[10000][10000];
vector<ll>v;


vector<ll> GenerateRandom(ll n)
{

    vector<ll>num;
    num.clear();
    ll i,a;
    for(i=0; i<n ;i++)
    {
        a = rand();
        num.push_back(a);
    }
    return num;
}






int query(int L, int R)
{
    // Find highest power of 2 that is smaller
    // than or equal to count of elements in given
    // range. For [2, 10], j = 3
    int j = (int)log2(R - L + 1);

    // Compute minimum of last 2^j elements with first
    // 2^j elements in range.
    // For [2, 10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];

    else
        return lookup[R - (1 << j) + 1][j];
}


void buildSparseTable(vector<ll>&v)
{
    ll n = v.size();
    ll i,j;

    for(i=0; i<n; i++)
    {
        lookup[i][0]=v[i];
    }
    for(j=1; j<=log2(n); j++)
    {
        for(i=0; (i+(1<<j)-1)<n; i++)
        {

            lookup[i][j] = min(lookup[i][j-1], lookup[i+(1<<(j-1))][j-1]);
        }
    }

}

ll RMQ(vector<ll>&v,ll l , ll r)
{

    ll i,j;
    ll min = INT_MAX;
    for(i=l; i<=r; i++)
    {
       if(v[i]<min)
       {
           min= v[i];
       }
    }

    return min;

}

int main()
{

    while(1)
    {
    v.clear();

    ll i,j,m,n,a,b;
    clock_t time_req;

    cout<<"How many numbers "<<endl;
    cin>>n;

    v = GenerateRandom(n);

    //for(i=0; i<n ; i++) {cout<<v[i]<<" ";}
    //cout<<endl;

    time_req = clock();
    buildSparseTable(v);

    cout<<query(50,100)<<endl;
    time_req = clock() - time_req;
	cout << "Sparse RMQ function  tooks " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;

    time_req = clock();
    cout<<RMQ(v,50,100)<<endl;
    time_req = clock() - time_req;
	cout << "Normal RMQ function tooks " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;


    }

}

