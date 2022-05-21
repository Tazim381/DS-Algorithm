#include<bits/stdc++.h>
using namespace std;
vector<int> generate_random(int n)
{

  vector<int>number;
  int a;

  for(int i=0; i<n  ; i++)
  {
      a = rand();
      number.push_back(a);

  }
  return number;
}

int randomizepartition(vector<int>&arr, int l , int r)
{
    int ran = l+rand()%(r-l+1);
    swap(arr[ran],arr[r]);

    int i = l-1;
    int piv = arr[r];

    for(int j=l; j<=r-1; j++)
    {
        if(arr[j]<piv)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[r]);
    return i+1;
}


void randomizequicksort(vector<int>&arr,int l, int r)
{
    if(l<r)
    {
        int p = randomizepartition(arr,l,r);
        randomizequicksort(arr,l,p-1);
        randomizequicksort(arr,p+1,r);
    }
}

int partition(vector<int>&ar, int l , int r)
{

    int i = l-1;
    int piv = ar[r];

    for(int j=l; j<=r-1; j++)
    {
        if(ar[j]<piv)
        {
            i++;
            swap(ar[i],ar[j]);
        }
    }

    swap(ar[i+1],ar[r]);
    return i+1;
}
void quicksort(vector<int>&ar,int l, int r)
{
    if(l<r)
    {
        int p = partition(ar,l,r);
        quicksort(ar,l,p-1);
        quicksort(ar,p+1,r);
    }
}



int main()
{
    int i,j,m,n,a,b;


    while(1)
    {

    clock_t t1 ,t2,t3,t4;
    cout<<"Enter number of elements "<<endl;
    cin>>n;
    vector<int>arr;
    vector<int>ar;

    arr= generate_random(n);
    ar = arr;
    cout<<"Before sorting "<<endl;
//    for(i=0; i<n; i++)
//    {
//
//        cout<<arr[i]<<" ";
//    }
    cout<<endl;

    t1 = clock();
    randomizequicksort(arr,0,n-1);
    t2  = clock();
    cout<<"time needs for randomizequickort = "<<double(t2-t1)/CLOCKS_PER_SEC<<endl;

    t3 = clock();
    quicksort(ar,0,n-1);
    t4 = clock();
    cout<<"time needs for quickort = "<<double(t4-t3)/CLOCKS_PER_SEC<<endl;

    cout<<endl;
    cout<<"Afer sorting "<<endl;
//    for(i=0; i<n; i++)
//    {
//
//        cout<<arr[i]<<" ";
//    }
    cout<<endl;

    }
}
