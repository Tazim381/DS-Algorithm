#include<bits/stdc++.h>
using namespace std;

int tree[60000];
vector<int>inputs;
vector<pair<int,pair<int,int> > > queries;

vector<int> getRandomNumbers(int n,int lft=0,int rgt=INT_MAX)
{
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int num=lft+rand()%(rgt-lft+1);
        v.push_back(num);
    }
    return v;
}

void printVector(vector<int> &v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

vector<pair<int,pair<int,int> > > getQueries(int n)
{
    vector<pair<int,pair<int,int> > >v;
    int type;
    int l,r;
    for(int i=0; i<n; i++)
    {
        type=rand()%3;
        if(type==1)
        {
            l=rand()%n;
            r=l+(rand()*(rand()%n));
            r%=n;
            if(l>r)swap(l,r);
            assert(l>=0&&l<n);
            assert(r>=0&&r<n);
            v.push_back(make_pair(type,make_pair(l,r)));
        }
        else
        {
            l=rand()%n;
            v.push_back(make_pair(type,make_pair(l,rand())));
        }
    }
}


void buildSegmentTree(int n, int b, int e)
{

    if(e==b)
    {
        tree[n]= inputs[e];
        return;
    }
    int mid =(e+b)/2;
    int left = 2*n;
    int right = 2*n+1;
    buildSegmentTree(left,b,mid);
    buildSegmentTree(right,mid+1,e);
    tree[n] = min(tree[left],tree[right]);
}


void updateSegmentTree(int node, int b, int e, int i, int newvalue)
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
    updateSegmentTree(Left, b, mid, i, newvalue);
    updateSegmentTree(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}


int querySegmentTree(int n, int b, int e,int l , int r)
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

    int p = querySegmentTree(left,b,mid,l,r);
    int q = querySegmentTree(right,mid+1,e,l,r);
    return min(p,q);

}


void simulateSegmentTree()
{
    int node=1;
    int b=1;
    int e=inputs.size();
    buildSegmentTree(node,b,e);

    int root=1;
    for(int i=0; i<queries.size(); i++)
    {
        if(queries[i].first==0)
        {
            updateSegmentTree(node,b,e,queries[i].second.first,queries[i].second.second);
        }
        else
        {
            querySegmentTree(node,b,e,queries[i].second.first,queries[i].second.second);
        }
    }
}


void updateBIT(int idx,int a)
{
    while(idx<1000)
    {
        tree[idx]+=a;
        idx+= (idx)&(-idx);
    }

}

void buildBIT()
{
   for(int i=0; i<inputs.size(); i++)
   {
       updateBIT(i+1,inputs[i]);
   }
}


int queryBIT(int idx, int idx1)
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


void simulateBIT()
{
    buildBIT();

    int root=1;
    for(int i=0; i<queries.size(); i++)
    {
        if(queries[i].first==0)
        {
            updateBIT(queries[i].second.first,queries[i].second.second);
        }
        else
        {
            cout<<queryBIT(queries[i].second.first,queries[i].second.second);
        }
    }
}


void buildSQRTDecomposition()
{
    int n = inputs.size();
    int segSiz =sqrt(n);
    int segment = -1;
    for(int i=0; i<n ;i++)
    {
        if(i%segSiz==0)
        {
            segment++;
        }
        tree[segment]+=inputs[i];
    }

}

void updateSQRTDecomposition(int i, int val)
 {
    int n = inputs.size();
    int segment_size=sqrt(n);
    int segment_no = i / segment_size;

    tree[segment_no] -= inputs[i];
    tree[segment_no] += val;
    inputs[i] = val;
}


int querySQRTDecomposition(vector<int>input, int l, int r)
{
    int n = input.size();
    int sum=0;
    int segmentsize = sqrt(n);
    while(l<=r&&l%segmentsize!=0)
    {
        sum+= inputs[l];
        l++;
    }

     while(l<=r)
     {
         sum+= tree[l/segmentsize];
         l+= segmentsize;
     }
     while(l<=r)
     {
         sum+= inputs[l];
         l++;
     }

     return sum;

}



void simulateSQRTDecomposition()
{
    buildSQRTDecomposition();

    int root=1;
    for(int i=0; i<queries.size(); i++)
    {
        if(queries[i].first==0)
        {
            updateSQRTDecomposition(queries[i].second.first,queries[i].second.second);
        }
        else
        {
            cout<<querySQRTDecomposition(inputs,queries[i].second.first,queries[i].second.second);
        }
    }
}

void runSimulation()
{
    /**
        if the first value of the query is 0 then update your data structure by the first value of second pair by the second value.
        if the first value of the query is 1 then print the summation between the indexes of first and second value of second pair.
    */
    ///write your code here.

    clock_t time;
    time=clock();
    simulateSegmentTree();
    time=clock()-time;
    cout<<"Time consumed for SegmentTree ---: "<<(float)time/CLOCKS_PER_SEC<<"\n";



}

int main()
{
    int CASE=10;
    int limits[]= {10,100,5000,10000,50000,100000,200000,300000,500000,600000};
    for(int ks=0; ks<CASE; ks++)
    {
        inputs=getRandomNumbers(limits[ks]);

        queries=getQueries(limits[ks]);
        runSimulation();
        inputs.clear();
        queries.clear();
        memset(tree,0,sizeof(tree));
    }

}

