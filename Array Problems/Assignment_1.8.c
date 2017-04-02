#include<stdio.h>
int main()
{

	int n,i,j,c=0,p,k,b;
	int arr[100]={0};
	int q[200]={0};
	int t=-1;
	printf("Size of array");
	scanf("%d",&n);
	n=n*2;

	printf("Enter the elements");
	for(i=0;i<n;i+=2)
	{
    	b=0;
    	scanf("%d",&p);
    	for(j=0;j<=i;j+=2)
    	{
    	    if(arr[j]==p)
    	    {
    	        arr[j+1]++;
    	        b=1;
    	    }       
    	}
    	if(b==0)
    	{
    	    c++;
    	    arr[c*2-2]=p;
    	    arr[c*2-1]++;
    	}
	}	
	printf("Array with its frequencies\n-");
	for(i=0;i<c*2;i++)
    	printf("%d ",arr[i]);
		for(k=1;k<n/2;k++) 
		{
    		for(j=c*2-1;j>0;j-=2)
    		{
        		if(arr[j]==k)
            	q[++t]=j;       
    		}
		}

	printf("\nArray according to frequencies\n");
	for(t;t>-1;t--)
	{       
    	for(j=arr[q[t]];j>0;j--)
   	    printf("%d ",arr[q[t]-1]);
	}

}
