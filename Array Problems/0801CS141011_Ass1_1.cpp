#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;


int A=5,C=3,rand_MAX = 8;

double randm()
{
    static int prev = 1;
    prev = A * prev + (C % rand_MAX);
    return prev;
}


int main()
{

//Approach 1: Using time function
    int n;
    time_t sec;
    sec=time(NULL);
 //   cout<<sec<<endl;
    cout<<"Enter N"<<endl;
    cin>>n;
int start_s=clock();
    cout<<"N Random Numbers are:-"<<endl;
    for(int i=0;i<n;i++)
        {
            sec=sec%3600;
            printf("%ld\n",sec+5*i);
            sec=time(NULL);
        }

//Approach 2 :Using Linear congruential generator
        cout<<"N Random Numbers are:-"<<endl;
         for(int i=0; i<n; i++)
            cout <<randm()<< endl;
int stop_s=clock();      
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}


