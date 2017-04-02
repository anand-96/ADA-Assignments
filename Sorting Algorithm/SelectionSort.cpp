#include <iostream>
#include <stdlib.h> 
#include <vector>
using namespace std;
int comp,swap;

 
int main()
{
    int n,l,temp,min;
    cin>>n;
    vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(rand()%100000);
        }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    int start_s=clock();
        
    for(int i=0;i<n-1;i++){
        min=v[i];
        l=i;
        for(int j=i+1;j<n;j++){
            if(min>v[j]){
                min=v[j];
                l=j;
            }
        }
        temp=v[i];
        v[i]=v[l];
        v[l]=temp;
    }

    cout<<endl; 
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

     int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    return 0;
}