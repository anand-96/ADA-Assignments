#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define ll long int
using namespace std;
 

void subsetSum(ll arr[],ll n,ll t)
{
    vector<ll> ans;
    bool T[n+2][t+2];
    for(ll i=0;i<=t;i++){
        T[0][i]=false;
        T[1][i+1]=false;
    }
    for(ll i=0;i<=n;i++){
        T[i][0]=true;
    }

    T[1][arr[1]]=true;

    for(ll i=2;i<=n;i++){
        for(ll j=1;j<=t;j++){
            if(j<arr[i])
                T[i][j]=T[i-1][j];
            else
                T[i][j]=(T[i-1][j] || T[i-1][j-arr[i]]);
        }
    }
/*    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=t;j++){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
  */  ll i=n,j=t;
    while(i>=0 && j>0){
            if(T[i-1][j]){
                i--;
                continue;
            }else{
                ans.push_back(arr[i]);
    //            cout<<arr[i]<<" ";
            j=j-arr[i];
            i--;
        }
//            ans.push_back(arr[i]);
    }
    cout<<"Subset is [ ";
    for(ll i=0;i<ans.size();i++)
        cout<<ans[i]<<",";
    cout<<"]"<<endl;
}

int main()
{
    ll n,t;
    cin>>n;
    ll arr[n+2];
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    cin>>t;
    subsetSum(arr,n,t);
    return 0;
}  

