#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define ll long int
using namespace std;
 

int main()
{
    ll n,x;
    cin>>n;
    vector<ll> station;
    for(ll i=1;i<=n;i++){
        cin>>x;
        station.push_back(x);
    }
    ll C,F,r,ans=0;
    cin>>C>>F>>r;
    for(ll i=0;i<n-1;i++){
    	x=(station[i+1]-station[i])*F;
    	ans+=x/r;
    }
    cout<<ans<<endl;
    return 0;
}  

