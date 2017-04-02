#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <ctime>
using namespace std;
int comp,swap;

int main(){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
             v.push_back(rand()%10000);
        }
        int start_s=clock();
        for(int i=n-1;i>=1;i--){
             for(int j=0;j<i;j++){
                        if(v[j]>v[j+1]){
                                int temp=v[j];
                                v[j]=v[j+1];
                                v[j+1]=temp;
                        }
                }
            }
        for(int i=0;i<n;i++){
                cout<<v[i]<<" ";
        }
int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

        return 0;
}
