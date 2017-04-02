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
return a.r < b.r;
}

set< pair<ll,ll> > ans;

void solve(intervals arr[],ll k,ll n)
{
    ll m=k+1;
    while(m<=n && arr[m].l<arr[k].r)
        m++;
    if(m<=n){
      ans.insert(make_pair(arr[m].l,arr[m].r));
      solve(arr,m,n);
    }
    else
        return;
}

int main()
{
    ll n,l,r,x,y,a,b;
    intervals X[10004];
    cin>>n;
    X[0].l=0,X[0].r=0;
    for(ll i=1;i<=n;i++){
        cin>>l>>r;
        X[i].l=l;
        X[i].r=r;
    }
    sort(X,X+n,comp);
    solve(X,0,n);
    cout<<"[ ";
    for(set< pair<ll,ll> >::iterator it=ans.begin();it!=ans.end();it++)
        cout<<"("<<it->first<<","<<it->second<<") ";
    cout<<"]";
    cout<<"\nCardinality of subset is : "<<ans.size()<<endl;
    return 0;
}  
