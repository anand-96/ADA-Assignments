#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#define MAX_SIZE 1000000
using namespace std;

long long int dp[MAX_SIZE];
int main(){
	int n;
	cout<<"Enter any number"<<endl;
	cin>>n;
	//Approach 1: Using Dynamic programming
	dp[1]=0;
	dp[2]=1;
	for(int i=3;i<MAX_SIZE;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout<<"Nth Fibonocci number is : "<<dp[n]<<endl;


	//Approach 2: Simple iterative

	long long int f1=0,f2=1,f3;
	for(int i=1;i<n-1;i++){
		f3=f1+f2;
		f1=f2;
		f2=f3;
	}
	cout<<"Nth Fibonocci number is : "<<f3<<endl;
}
