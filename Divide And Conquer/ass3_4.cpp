#include <iostream>
using namespace std;

int ternary(int v[],int left, int right, int x)
{
    if(left>=right)
        return -1;
    if(v[left]==x)
        return left;
    if(v[right]==x)
        return right;

    int mid=left+(right-left)/3;
    if(v[mid]==x)
        return mid;
    else if(v[mid]>x)
        return ternary(v,left,mid-1,x);
    else if(v[mid]<x)
        return ternary(v,mid+1,right,x);
    return -1;
}


int main()
{
	int n,x;
	cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter number to be search:"<<endl;
    cin>>x;
    int ans=ternary(arr,0,n-1,x);
    if(ans==-1){
        cout<<"Number does not exist in array."<<endl;
    }
    else{
        cout<<"Number found at index is:"<<ans<<endl;
    }
    return 0;
}