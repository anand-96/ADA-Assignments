#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#define ll long int
using namespace std;
 

ll LPS(string s,ll n)
{
    vector<char> ans;
    ll T[n][n];
    memset(T,0,sizeof(T[0][0])*n*n);

    for(ll i=0;i<n;i++){
        T[i][i]=1;
    }

    for(ll len=2;len<=n;len++){
        for(ll i=0;i<n-len+1;i++){
            ll j=i+len-1;
                if(s[i]==s[j])
                    T[i][j]=T[i+1][j-1]+2;
                else
                    T[i][j]=max(T[i+1][j],T[i][j-1]);
            }
        }
/*    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    return T[0][n-1];
}

int main()
{
    string str;
    cin>>str;
    cout<<"Length of Longest Pallindromic Subsequence is :- "<<LPS(str,str.size())<<endl;
    return 0;
}  

