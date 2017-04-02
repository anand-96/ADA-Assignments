#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <algorithm>
using namespace std;

 
int main()
{
    int n,l,temp,min;
    cin>>n;
    vector<double>v,B[20000];
        for(int i=0;i<n;i++){
          int d=rand();
         double x;
                if (d%100==0)
                     x=1.0/(d%9);
                else
                     x=1.0/(d%10);
            v.push_back(x);
        }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    cout<<endl; 
    int start_s=clock();
    for(int i=0;i<n;i++){
        B[(int)(n*v[i])].push_back(v[i]);
    }

    for(int i=0;i<n;i++){
        sort(B[i].begin(),B[i].end());
    }
    for(int i=0;i<n;i++){
        l=B[i].size();
        for(int j=0;j<l;j++)
            cout<<B[i][j]<<" ";
    }
     int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    return 0;
}