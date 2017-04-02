#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define ll long int
using namespace std;
 

ll kadane(ll arr[],ll n)
{
    ll ma=0,ans=0;
    for(ll i=0;i<n;i++){
         ma+=arr[i];
        if(ans<ma){
            ans=ma;
        }
        
        if(ma<0){
            ma=0;
        }
    }
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Maximum Contiguous Sum is "<<kadane(arr,n)<<endl;
    return 0;
}  

