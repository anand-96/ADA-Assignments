#include <iostream>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#define MAX_SIZE 1000
using namespace std;

        map<int,int> mp;
        int arr[MAX_SIZE];
        vector<int>s[MAX_SIZE];
        int ma;

int main(){
        int n,x,k=0,j,flag=0;
        cin>>n;
int start_s=clock();
        for(int i=0;i<n;i++){
                cin>>x;
                for(j=0;j<n;j++){
                       if(arr[j]==x)
                             break;
                }
                if(j==n)
                   arr[k++]=x;
                mp[x]++;
        }
        
        map<int,int>::iterator it;
        for(int i=0;i<k;i++){
   //             cout<<arr[i]<<" ";
                it=mp.find(arr[i]);
                s[it->second].push_back(it->first);
                //cout<<it->first<<" "<<it->second<<endl;
                ma=max(ma,it->second);
        }
//        cout<<endl;
        for(int j=ma;j>=0;j--){
              for(vector<int>::iterator i=s[j].begin();i!=s[j].end();i++)
              {
                        for(int k =0;k<j;k++)
                                cout<<*i<<" ";
              }
        }
 int stop_s=clock();      
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
       return 0;
}
