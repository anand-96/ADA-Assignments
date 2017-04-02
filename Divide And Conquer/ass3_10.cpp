//Question:--  Find the missing number in Arithmetic Progression


#include <bits/stdc++.h>
using namespace std;
 
int missingElement(int arr[], int low, int high,int diff)
{
    if (low >= high)
        return -1;
    int mid=low+(high-low)/2;
    if((arr[mid+1]-arr[mid])!=diff)
        return arr[mid]+diff;
    if(mid>0 && (arr[mid]-arr[mid-1])!=diff)
        return arr[mid-1]+diff;

    if(arr[mid]==(arr[0]+mid*diff))
        return missingElement(arr,mid+1,high,diff);

        return missingElement(arr,low,mid-1,diff);
}
 
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int diff=(arr[n-1]-arr[0])/n;
    int ans=missingElement(arr,0,n-1,diff);
    if(ans!=-1)
        cout<<ans<<endl;
    return 0;
}
