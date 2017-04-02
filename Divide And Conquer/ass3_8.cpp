#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
#define ll long long 

ll fibonacci(ll n)
{
    ll fib[2][2]= {{1,1},{1,0}},ans[2][2]= {{1,0},{0,1}},temp[2][2]= {{0,0},{0,0}};
    while(n)
    {
        if(n&1)
        {
            memset(temp,0,sizeof(temp));
            for(int i=0; i<2; i++){ 
                for(int j=0; j<2; j++){
                    for(int k=0; k<2; k++){
                        temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j]);
                    }
                }
            }

            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    ans[i][j]=temp[i][j];
                }
            }
        }
        memset(temp,0,sizeof(temp));
        for(int i=0; i<2; i++){ 
            for(int j=0; j<2; j++){
                for(int k=0; k<2; k++){
                    temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j]);
                }
            }
        }

        for(int i=0;i<2;i++){ 
            for(int j=0; j<2; j++){ 
                fib[i][j]=temp[i][j];
            }
        }

        n/=2;
    }
    return ans[0][1];
}


int main(){
    ll n;
    cin>>n;
    int start_s=clock();
    cout<<fibonacci(n)<<endl;
int stop_s=clock();
   	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

}