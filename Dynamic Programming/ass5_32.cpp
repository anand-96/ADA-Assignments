#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#define ll long int
using namespace std;
 
ll LCS(string X,string Y,string Z,ll m,ll n,ll o,unordered_map<string,ll> mp)
{
    if (m==0 || n==0 || o==0)
        return 0; 
    string key=to_string(m)+"|"+to_string(n)+"|"+to_string(o);
    if (mp.find(key)==mp.end())
    {
        if (X[m-1]==Y[n-1] && Y[n-1]==Z[o-1]){
        	//cout<<key<<"--"<<mp[key]<<endl; 
            mp[key]=LCS(X,Y,Z,m-1,n-1,o-1,mp)+1;
        }
        else
            mp[key]=max(LCS(X,Y,Z,m-1,n,o,mp),max(LCS(X,Y,Z,m,n-1,o,mp),LCS(X,Y,Z,m,n,o-1,mp)));

    }
    return mp[key];
}
 
int main()
{
    string X,Y,Z;
    cin>>X;
    cin>>Y;
    cin>>Z;
    unordered_map<string,ll> mp; 
    cout<<"The length of LCS is "<<LCS(X,Y,Z,X.size(),Y.size(),Z.size(),mp)<<endl;
    return 0;
}