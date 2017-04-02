/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

    Insert
    Remove
    Replace

All of the above operations are of equal cost.

*/



#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#define ll long int
using namespace std;
 
ll editDis(string s1,ll m,string s2,ll n){
    ll DP[m+1][n+1];
    for(ll i=0;i<=m;i++)
        DP[i][0]=i;

    for(ll i=0;i<=n;i++)
        DP[0][i]=i;

    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])
                DP[i][j]=DP[i-1][j-1];
            else{
                DP[i][j]=1+min(DP[i-1][j],min(DP[i][j-1],DP[i-1][j-1]));
            }
        }
    }
    return DP[m][n];
}

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<editDis(s1,s1.size(),s2,s2.size())<<endl;
    return 0;
}  

/*
Test cases:-

sunday saturday
cat cat


*/