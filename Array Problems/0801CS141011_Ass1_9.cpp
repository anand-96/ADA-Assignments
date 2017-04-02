#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#define MAX_SIZE 50
using namespace std;

int determinant(int a[MAX_SIZE][MAX_SIZE],int n) {
int det=0,i,j,k,x,y,temp[MAX_SIZE][MAX_SIZE];
  if(n==2){
    det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    return det;
  }
  else{
    for(i=0;i<n;i++){
        x=0;
      for(j=1;j<n;j++){
        y=0;
          for(k=0;k<n;k++){
            if(k==i){
                continue;
              }
  //      cout<<a[i][j]<<" ";
          temp[x][y]=a[j][k];
          y++;
 //         cout<<y<<endl;

          }
          x++;
        }
//      cout<<det<<endl;
      det=det+a[0][i]*pow(-1 ,i)*determinant(temp,n-1);
    }
    return det;
  }
}

int main(){
  int n;
  cout<<"Enter N"<<endl;
  cin>>n;
  int arr[MAX_SIZE][MAX_SIZE];
  cout<<"Enter N*N matrix"<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
    //  cout<<arr[i][j]<<" ";
    }
    //cout<<endl;
    }
  int ans=determinant(arr,n);
  cout<<"Determinant of given Matrix is : "<<ans<<endl;
  return 0;
}
