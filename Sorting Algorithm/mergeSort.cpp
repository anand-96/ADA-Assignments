#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <ctime>
using namespace std;
int comp,swap;

int combine(vector<int>a,int l,int h,int m){
    int i=l,j=m+1,k=l,c[100000];
    while(i<=m && j<=h){
        if(a[i]<a[j]){
            c[k]=a[i];
            k++,i++;
        }
        else{
            c[k]=a[j];
            k++,j++;
        }
    }
    while(i<=m){
        c[k]=a[i];
        k++,i++;
    }
    while(j<=h){
        c[k]=a[j];
        k++,j++;
    }
    for(i=l;i<k;i++){
        a[i]=c[i];
    }
}

void partition(vector<int> v,int low,int high){
        if(low>=high)
              return;
        int mid=(low+high)/2;
        partition(v,low,mid);
        partition(v,mid+1,high);
        combine(v,low,high,mid);
}       


int main(){
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
                v.push_back(rand()%100000);
        }

        for(int i=0;i<n;i++){
                cout<<v[i]<<" ";
        }
        cout<<endl;
 int start_s=clock();
 
        partition(v,0,n-1);
        for(int i=0;i<n;i++)
        	cout<<v[i]<<" ";        

 int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

	
       return 0;
}
