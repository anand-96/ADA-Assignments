#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <ctime>
using namespace std;
int comp,swap;

int partition(int arr[],int l,int r){
    int p=arr[r],i=l-1,j=l;
    //cout<<p<<endl;
    for(;j<r;j++){
        if(arr[j]<=p){
            i++;
            int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
        }
//        cout<<arr[j]<<" ";
    }
  //  cout<<endl;
    int temp=arr[i+1];
        arr[i+1]=arr[r];
        arr[r]=temp;
    return i+1;
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int mid=partition(arr,l,r);
    //    cout<<mid<<endl;
        quickSort(arr,l,mid-1);
        quickSort(arr,mid+1,r);
    }
}

int main()
{
    int n,x;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++){
            arr[i]=rand()%10000;
        }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }     
    cout<<endl;
     int start_s=clock();

        quickSort(arr,0,n-1);
//      cout<<ans[i]<<" ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }     
    
 int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}