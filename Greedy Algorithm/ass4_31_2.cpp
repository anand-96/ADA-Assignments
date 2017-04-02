

/* Que :- Connect n ropes with minimum cost

There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.
*/


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#define ll long long int
using namespace std;
 
 
//using priority_queue

priority_queue<ll,vector<ll>,greater<ll> > minHeap;

int main()
{
    ll n,x,ans=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>x;
        minHeap.push(x);
    }
    while(minHeap.size()>1){
    	x=0;
    	x+=minHeap.top();
    	minHeap.pop();
    	x+=minHeap.top();
    	minHeap.pop();
    	minHeap.push(x);
    	ans+=x;
  //  	cout<<x<<endl;
    }
    cout<<ans<<endl;
    return 0;
}  

//using set

/*

set<ll>s;

int main()
{
    ll n,x,ans=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }
    set<ll>::iterator it=s.begin();
    ll i=0;
    while(i!=n-1){
    	x=0;
    	x+=*it;
    	it++;
    	x+=*it;
    	s.insert(x);
    	ans+=x;
    	it++;
    	i++;
    }
    cout<<ans<<endl;
    return 0;
}  

*/