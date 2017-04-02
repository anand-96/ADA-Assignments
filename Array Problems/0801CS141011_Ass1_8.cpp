#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#define MAX_SIZE 100000
using namespace std;

int arr[MAX_SIZE];
int fq[MAX_SIZE];

int main()
{

	int n,i,j,c=0,x,k,b;
	int t=-1;
	cout<<"Enter n"<<endl;
	cin>>n;
	n=n*2;

	cout<<"Enter n elements"<<endl;

	for(i=0;i<n;i+=2)
	{
    	b=0;
    	cin>>x;
    	for(j=0;j<=i;j+=2)
    	{
    	    if(arr[j]==x)
    	    {
    	        arr[j+1]++;
    	        b=1;
    	    }       
    	}
    	if(b==0)
    	{
    	    c++;
    	    arr[c*2-2]=x;
    	    arr[c*2-1]++;
    	}
	}	
		for(k=1;k<n/2;k++) 
		{
    		for(j=c*2-1;j>0;j-=2)
    		{
        		if(arr[j]==k)
            	fq[++t]=j;       
    		}
		}

	cout<<"Elements with its frequency"<<endl;
	for(t;t>-1;t--)
	{       
    	for(j=arr[fq[t]];j>0;j--)
   	    	cout<<arr[fq[t]-1]<<" ";
	}
	cout<<endl;
	return 0;
}
