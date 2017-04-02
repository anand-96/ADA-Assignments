#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

int l1,r1,c=0;

void positiveSum(int a[],int s1[],int s2[],int l,int r,int n){
	s1[l]=0;
	s2[r]=0;
	l++;r--;
	l1=0,r1=0;
   for(int i=l;i<=r;i++){
    	s1[i]=s1[i-1]+a[i];
    	if(s1[i]>=0)
    		l=i;
    	else
    		l1++;
  
    	s2[r-i+l]=s2[r-i+l+1]+a[i];
    	if(s2[i]>=0)
    		r=i;
    	else
    		r1++;
	}

	if(l1==(r-l+1) || r1==(r-l+1)){
		for(int i=l;i<=r;i++){
			if(a[i]>=0)
				c++;
		}
		return;
	}

   	if(l>r){
   		if(l>(n-r)){
   			l=l+1;
   			r=n;
   		}else{
   			l=1;
   			r=r-1;
   		}
   		c++;
   	}else{
   		c+=2;
   	}
   	positiveSum(a,s1,s2,l,r,n);
}

int main(){
	int n,l,r;
    cin>>n;
 	int arr[n+1],s1[n+1],s2[n+1];
 	arr[0]=0,s1[0]=0,s2[n+1]=0;
    for(int i=1;i<=n;i++){
    	cin>>arr[i];
    	s1[i]=s1[i-1]+arr[i];
    	if(s1[i]>=0)
    		l=i;
    	else
    		l1++;
    }
    for(int i=n;i>=1;i--){
    	s2[i]=s2[i+1]+arr[i];
    	if(s2[i]>=0)
    		r=i;
    	else
    		r1++;
	}

	if(l1==(r-l+1) || r1==(r-l+1)){
		for(int i=1;i<=n;i++){
			if(arr[i]>=0)
				c++;
		}
		cout<<c<<endl;
		return 0;
	}

   	if(l>r){
   		if(l>(n-r+1)){
   			l=l+1;
   			r=n;
   		}else{
   			l=1;
   			r=r-1;
   		}
   		c++;
   	}else{
   		c+=2;
   	}

   	positiveSum(arr,s1,s2,l,r,n);
   	cout<<"c="<<c<<endl;
}
