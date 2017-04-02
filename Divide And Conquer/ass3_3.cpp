#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int ternary(int v[],int left, int right, int x)
{
    if(left>right){
        return -1;
    }
    if(x==v[left]){
        return left;
    }
    if(x==v[right]){
        return right;
    }

    int mid1=left+(right-left)/3;
    int mid2=mid1+(right-mid1)/2;
    if(v[mid1]==x)
        return mid1;
    if(v[mid2]==x)
        return mid2;
    if(x<v[mid1]){
        return ternary(v,left,mid1-1,x);
    }
    if(x>v[mid1] && x<v[mid2]){
        return ternary(v,mid1+1,mid2-1,x);
    }
    if(x>v[mid2]){
        return ternary(v,mid2+1,right,x);
    }
}


int main()
{
	int n,x;
	cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000;
    }
    cout<<"Enter number to be search:"<<endl;
    cin>>x;
    int start_s=clock();
    int ans=ternary(arr,0,n-1,x);
    if(ans==-1){
        cout<<"Number does not exist in array."<<endl;
    }
    else{
        cout<<"Number found at index is:"<<ans<<endl;
    }
    int stop_s=clock();
            cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}