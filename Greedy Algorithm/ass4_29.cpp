#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main(){
	int n,sum1=0,sum2=0;
    cin>>n;
 	int speed[n+1],c[n+1];
 	for(int i=1;i<=n;i++){
    	cin>>speed[i];
    }
    sort(speed+1,speed+n+1);
 	//for(int i=1;i<=n;i++){
   // 	cout<<speed[i]<<" ";
   // }
   // cout<<endl;
    for(int i=3;i<=n;i++){
    	sum1+=speed[i];
 	}
// 	cout<<sum1<<endl;
 	int k=n/2-1,ans=1e9;
 	for(int i=0;i<=k;i++){
 		sum2=0;
 		for(int j=1;j<=i;j++)
 			sum2+=speed[n+1-2*j];

 		c[i]=(n-2-i)*speed[1]+(2*i+1)*speed[2]+sum1-sum2;
 		ans=min(c[i],ans);
 	}

// 	for(int i=0;i<=k;i++)
 //		cout<<c[i]<<endl;
   	cout<<"fastest way to get a group of people across the bridge is "<<ans<<endl;
}
