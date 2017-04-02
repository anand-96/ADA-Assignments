#include <iostream>
#include <stdlib.h>
using namespace std;

int majorityElement(int arr[],int n){

	if(n==1)
		return arr[0];

	int mid=n/2;
	int majorLeft=majorityElement(arr,mid);
	int majorRight=majorityElement(arr+mid,n-mid);


	if(majorLeft==majorRight)
		return majorLeft;
	int c=0;
	for(int i=0;i<n;i++){
		if(arr[i]==majorLeft)
			c++;
	}

	if(c>n/2)
		return majorLeft;
	c=0;

	for(int i=0;i<n;i++){
		if(arr[i]==majorRight)
			c++;
	}

	if(c>n/2)
		return majorRight;

	return -1;

}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=rand()%10;
    int start_s=clock();
  	int ans=majorityElement(arr,n);
	if(ans==-1)
		cout<<"Not Found"<<endl;
	else
		cout<<"Majority Element found and is equal to :"<<ans<<endl;
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}