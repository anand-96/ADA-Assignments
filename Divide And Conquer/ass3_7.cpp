#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=1,j=2,l=0,r=1,ma=arr[1]-arr[0];
        while(i<n && j<n){
        	if((arr[j]-arr[i])>ma){
                ma=arr[j]-arr[i];
                r=j;
        	}
            else if(arr[j]<arr[i-1]){
                     l=i;
                i=j;
            }
            j++;
        }
    cout<<(arr[r]-arr[l])<<"("<<l<<","<<r<<")"<<endl;
    return 0;
}
