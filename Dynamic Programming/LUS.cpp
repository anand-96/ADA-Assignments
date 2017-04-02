/*


Length of the longest substring without repeating characters

Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without 
repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. For “BBBB” the longest substring is “B”, with 
length 1. For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7. 
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
 
ll LUS(string s,ll n){
    ll DP[256];
    ll cur=1,ma=1,prevIndex;
    memset(DP,-1,sizeof(DP));

    DP[s[0]]=0;
    for(ll i=1;i<n;i++){
        prevIndex=DP[s[i]];
        if(prevIndex==-1 || i-cur>prevIndex)
            cur++;
        else{
            ma=max(ma,cur);
            cur=i-prevIndex;
        }
        DP[s[i]]=i;
    }
    ma=max(cur,ma);
    return ma;
}

int main()
{
    string s;
    cin>>s;
    cout<<LUS(s,s.size())<<endl;
    return 0;
}  

