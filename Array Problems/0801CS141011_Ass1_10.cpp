#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#define MAX_SIZE 100
using namespace std;

	int n,c=0,nsquare;
	int arr[MAX_SIZE][MAX_SIZE];


	void PrintOneRound(int arr[MAX_SIZE][MAX_SIZE],int x,int y)
	{
		for(int j=y;j<n-x;j++)
		{	
			if(c>=nsquare)
				break;
			cout<<arr[x][j]<<"  ";
			c++;

		}
		for(int j=x+1;j<n-y;j++)
		{	
			if(c>=nsquare)
				break;
			cout<<arr[j][n-x-1]<<"  ";
			c++;
		}
		for(int j=n-y-2;j>=x;j--)
		{	
			if(c>=nsquare)
				break;
			cout<<arr[n-x-1][j]<<"  ";
			c++;
		}
		for(int j=n-x-2;j>y;j--)
		{	
			if(c>=nsquare)
				return;
			cout<<arr[j][x]<<"  ";
			c++;
		}
		
	}


void Spiral(int i){
	if(c<nsquare)
		PrintOneRound(arr,i,i);
	else
		return;
	Spiral(i+1);
}

int main(){
	cout<<"Enter N"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	nsquare=n*n;
	cout<<"\nElements in Spiral order are :"<<endl;
	Spiral(0);
	return 0;
}
