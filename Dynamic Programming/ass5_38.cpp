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
    ll n,t;
    cin>>n;
    ll arr[n+1][n+1];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=i;j++)
            cin>>arr[i][j];
    }
    
    for(ll i=n-1;i>0;i--){
        for(ll j=i;j>0;j--){
            arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
        }
    }

    cout<<"Highest Sum is :- "<<arr[1][1]<<endl;

    return 0;
}  

