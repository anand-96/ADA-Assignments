#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <ctime>
using namespace std;
int comp,swap;

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

    int freq[ma+1]={0};
    for(int i=0;i<n;i++){
    	freq[arr[i]]++;
    }
    for(int i=1;i<=ma+1;i++){
    	freq[i]+=freq[i-1];
    }
    for(int i=0;i<n;i++){
    	int x=arr[i];
    	ans[freq[x]]=x;
    	freq[x]--;
    }
    for(int i=1;i<n+1;i++){
    	cout<<ans[i]<<" ";
    }
 int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}