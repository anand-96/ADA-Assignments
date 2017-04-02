#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#define ll long int
using namespace std;
 

void printOrder(ll i,ll j,ll n,ll*seq,char &ch)
{
    if (i==j){
        cout<<ch++;
        return;
    }
    cout<<"(";
    printOrder(i,seq[i*n+j],n,seq,ch);
    printOrder(seq[i*n+j]+1,j,n,seq,ch);
    cout<<")";
}


ll solve(ll M[],ll n)
{
        ll Dp[n][n]={0},seq[n][n];        
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++)
                cout<<Dp[i][j]<<" ";
            cout<<endl;
        }        
        ll q=0;
        for(ll len=2;len<n;len++){
            for(ll i=1;i<n-len+1;i++){
                ll j=i+len-1;
                Dp[i][j]=1e9;
                for(ll k=i;k<j;k++){
                    q=Dp[i][k]+Dp[k+1][j]+M[i-1]*M[k]*M[j];
                    if(q<Dp[i][j]){
                        Dp[i][j]=q;
                        seq[i][j]=k;
                    }
                }
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++)
                cout<<Dp[i][j]<<" ";
            cout<<endl;
        }
        char ch='1';
        cout<<"Order of Multiplication is:-"<<endl;
        printOrder(1,n-1,n,(ll*)seq,ch);
        cout<<endl;
    return Dp[1][n-1];
}

int main()
{
    ll n,m,t,x,y,a,b,ans=0;
    cin>>t;
    ll M[t];
    for(ll i=0;i<t;i++){
        cin>>M[i];
    }
    cout<<"Minimum cost of Multiplication is :- "<<solve(M,t)<<endl;
    return 0;
}  

