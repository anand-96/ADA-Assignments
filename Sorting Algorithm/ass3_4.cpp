#include <iostream>
using namespace std;

int ternary(int v[],int left, int right, int x)
{
    if(left<=right){
     
        int mid=left+(right-left)/2;
         if(v[mid]==x)
            return mid;
         if(v[mid]>x)
            return ternary(v,left,mid-1,x);
        return ternary(v,mid+1,right,x);
    }
    return -1;
}


int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
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
    int ans=binarySearch(arr,0,n-1,x);
    if(ans==-1){
        cout<<"Number does not exist in array."<<endl;
    }
    else{
        cout<<"Number found at index is:"<<ans<<endl;
    }
    return 0;
}