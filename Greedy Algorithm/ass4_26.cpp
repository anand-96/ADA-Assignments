#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define ll long int
using namespace std;
 
struct intervals
{
    ll l, r;
};
     
bool comp(intervals a, intervals b)
{
return a.l < b.l;
}

set< pair<ll,ll> > ans[1000];

int solve(intervals arr[],int k,int n,int d)
{
    int m=k+1;
    while((k>0 && arr[k].r<0) || (m<=n && k>0 && arr[m].l<arr[k].r))
        k--;
    if(m<=n && k==0){
      ans[m-1].insert(make_pair(arr[m].l,arr[m].r));
      d=max(m-1,d);
      solve(arr,m,n,d);
    }
    else if(m<=n && arr[k].r>0 && arr[m].l>=arr[k].r){
        ans[k-1].insert(make_pair(arr[m].l,arr[m].r));
        arr[k].r=arr[m].r;
        arr[m].r=-1;
        d=max(k,d);
        solve(arr,m,n,d);
    }
    else
        return d;
}

int main()
{
    ll l,r,x,y,a,b;
    int n;
    intervals X[10004];
    cin>>n;
    X[0].l=0,X[0].r=-1;
    for(int i=1;i<=n;i++){
        cin>>l>>r;
        X[i].l=l;
        X[i].r=r;
    }
    sort(X,X+n,comp);
    for(int i=0;i<n;i++){
        cout<<X[i].l<<"--"<<X[i].r<<endl;
    }

    int d=solve(X,0,n,0);
    ll c=0;
    for(int i=0;i<d;i++){
        if(ans[i].size()){
            c++;
            cout<<"\nRoom number "<<c<<":- ";
        }

        for(set< pair<ll,ll> >::iterator it=ans[i].begin();it!=ans[i].end();it++)
            cout<<"("<<it->first<<","<<it->second<<") ";
    }
    cout<<"\nMinimum number of rooms required are "<<c<<endl;
    return 0;
}  


/*

Test case:- 
10
0 6
5 7
8 11
5 9
6 10
3 5
1 4
8 12
12 16
3 9

*/op