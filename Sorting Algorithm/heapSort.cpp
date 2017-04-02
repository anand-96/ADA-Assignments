#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <ctime>
using namespace std;
int comp,swap;

void maxheapify(int a[],int i,int n){
    int j,temp=a[i];
    j=2*i;
    while(j<=n){
        if(j<n && a[j+1]>a[j])
            j = j+1;
        if (temp>a[j])
            break;
        else if(temp<=a[j]){
            a[j/2]=a[j];
            j = 2*j;
        }
    }
    a[j/2]=temp;
    return;
}

void heapsort(int a[], int n){
    int temp;
    for(int i=n;i>=2;i--){
        temp=a[i];
        a[i]=a[1];
        a[1]=temp;
        maxheapify(a,1,i-1);
    }
}

void heapbuild(int a[],int n){
    for(int i=n/2;i>=1;i--){
        maxheapify(a,i,n);
    }
}

int main()
{
    int n,x;
    cin>>n;
    int a[100000];
        for(int i=1;i<=n;i++){
            a[i]=rand()%1000;
        }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
     int start_s=clock();
    heapbuild(a,n);
    heapsort(a,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";        
      
 int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

   return 0;
}
