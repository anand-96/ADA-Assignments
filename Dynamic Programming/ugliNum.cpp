/*

Ugly Numbers

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 
11 ugly numbers. By convention, 1 is included. 

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#define ll long int
using namespace std;
 
ll UgliNumber(ll n) {
    ll i2=0,i3=0,i5=0;
    ll nextugli=0,mulof2=2,mulof3=3,mulof5=5;
    ll ug[n];
    ug[0]=1;
    for(ll i=1;i<n;i++){
        nextugli=min(mulof2,min(mulof3,mulof5));
        ug[i]=nextugli;
        if(nextugli==mulof2){
            i2++; 
            mulof2=ug[i2]*2;
        }

        if(nextugli==mulof3){
            i3++; 
            mulof3=ug[i3]*3;
        }

        if(nextugli==mulof5){
            i5++; 
            mulof5=ug[i5]*5;
        }
    }

    return nextugli;
}

int main()
{
    ll n;
    cin>>n; 
    cout<<UgliNumber(n)<<endl;

    return 0;
}  

