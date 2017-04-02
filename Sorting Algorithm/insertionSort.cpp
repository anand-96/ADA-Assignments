#include <iostream>
#include <vector>
#include <stdlib.h>
#include <map>
#include <ctime>
using namespace std;


	
int main(){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
                arr[i]=rand()%10000;
        }

        for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
int start_s=clock();


        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                int temp=arr[i];
                for(int j=i-1;j>=0;j--){
                        if(arr[j]>temp){
                                arr[j+1]=arr[j];
                                arr[j]=temp;
                                temp=arr[j];
                        }
                }
            }
//        for(int i=0;i<n;i++)
  //              cout<<arr[i]<<" ";
    //     cout<<endl;       
        }
        
        for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
 int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
           return 0;
}
