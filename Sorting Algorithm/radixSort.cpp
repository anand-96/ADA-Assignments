#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <ctime>
using namespace std;
int comp,swap;

int countSort(int arr[],int mod,int n){
  int freq[10]={0},ans[n];
    for(int i=0;i<n;i++){
        freq[(arr[i]/mod)%10]++;
    }
    for(int i=1;i<=9;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=n-1;i>=0;i--){
        int x=(arr[i]/mod)%10;
        ans[freq[x]]=arr[i];
        freq[x]--;
    }
    for(int i=1;i<=n;i++){
        arr[i-1]=ans[i];
     //   cout<<ans[i]<<" ";
    }
    //cout<<endl;

}

int main()
{
    int n,x;
    cin>>n;
    int arr[n+1],ans[n+1],ma=0;
    for(int i=0;i<n;i++){
            arr[i]=rand()%10000;
            ma=max(ma,arr[i]);
        }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }     
    cout<<endl;
     int start_s=clock();

    for(int i=1;ma/i>0;i*=10){
        countSort(arr,i,n);
//    	cout<<ans[i]<<" ";
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }     
    
 int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}