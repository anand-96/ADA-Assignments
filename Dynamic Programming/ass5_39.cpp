#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long int
using namespace std;
  
int main()
{
    ll X,Y;
    ll n;
    cin>>X>>Y;
    cin>>n;
    ll L[n+1],W[n+1],P[n+1];
    for(ll i=1;i<=n;i++){
        cin>>L[i]>>W[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>P[i];
    }

    ll T[X+1][Y+1];

    for(ll i=0;i<=X;i++){
        for(ll j=0;j<=Y;j++){
            T[i][j]=0;
        }
    }

    for(ll k=1;k<=n;k++){
        for(ll i=0;i<=X;i++){
            for(ll j=0;j<=Y;j++){
                if(L[k]<=i && W[k]<=j && P[k]>T[i][j])
                    T[i][j]=P[k];
            }
        }
/*
        for(ll t=0;t<=X;t++){
            for(ll f=0;f<=Y;f++){
                cout<<T[t][f]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
*/
    }


    ll sum=0;

    for(ll i=0;i<=X;i++){
        for(ll j=0;j<=Y;j++){
            for(ll k=0;k<=(i/2);k++){
                sum=T[k][j]+T[i-k][j];
                if(sum>T[i][j])
                    T[i][j]=sum;
            }
        
            for(ll k=0;k<=(j/2);k++){
                sum=T[i][k]+T[i][j-k];
                if(sum>T[i][j])
                    T[i][j]=sum;
            }
        }

    /*      for(ll i=0;i<=X;i++){
            for(ll j=0;j<=Y;j++){
                cout<<T[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
  */  }

/*      for(ll i=0;i<=X;i++){
            for(ll j=0;j<=Y;j++){
                cout<<T[i][j]<<" ";
            }
            cout<<endl;
        }

*/
    cout<<sum<<endl;
    return 0;
}


/*
Test case:-
7 7
5
1 2
3 1
3 3
2 2
2 3
1 2 8 3 5



*/