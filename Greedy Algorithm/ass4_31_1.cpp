

// Que :- Find the union of all the Intervals given by the users.


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define ll long long int
using namespace std;
 
 
struct intervals
{
    ll l, r;
};

bool comp(intervals a, intervals b)
{
    return a.l > b.l;
}

void solve(intervals arr[],ll n)
{
    sort(arr,arr+n,comp);

    ll j=0;
    for(ll i=0;i<n;i++){
	   if(j!=0 && arr[j-1].l<=arr[i].r)
	   {
	       	while (j!=0 && arr[j-1].l<=arr[i].r)
		      {
		      	arr[j-1].r=max(arr[j-1].r,arr[i].r);
			     arr[j-1].l=min(arr[j-1].l,arr[i].l);
			     j--;
	          }
	   }
	   else 
		  arr[j]=arr[i];
	j++;
}

ll ans=0;

for (ll i=0;i<j;i++){
	cout << "[" << arr[i].l << ", " << arr[i].r << "] ";
    ans=max(ans,(arr[i].r-arr[i].l+1));
    }
cout<<ans;
}


int main()
{
    ll n,l,r,x,y,a,b,ans=0;
    intervals X[10004];
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>l>>r;
        X[i].l=l;
        X[i].r=r;
    }
        solve(X,n);
  //  cout<<(b-a+1);
    return 0;
}  

/*

11      
3 5
5 7
1 4
3 9
5 9
12 16
6 10
8 11
0 6
8 12
2 14

*/
