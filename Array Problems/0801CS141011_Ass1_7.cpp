#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#define MAX_SIZE 1000000
using namespace std;
 
int main(){
	int n,ans=0,c=0;
	cout<<"Enter number of elements"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter n elements"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		if((arr[i+1]-arr[i])==1)
			c++;
		else{
			ans=max(ans,c);
			c=0;
		}
	}
	ans++;
	cout<<"Maximum K is : "<<ans<<endl;
}
