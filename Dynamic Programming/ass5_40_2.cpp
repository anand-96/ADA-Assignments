/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) 
from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of
all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from
a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs
are positive integers.

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
 

int main()
{
    ll m,n;
    cin>>m>>n;
    ll cost[m][n];
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++)
            cin>>cost[i][j];
    }

    for(ll i=m-1;i>=0;i--){
        for(ll j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1)
                    continue;
                else if(i==m-1)
                    cost[i][j]+=cost[i][j+1];
                else if(j==n-1)
                    cost[i][j]+=cost[i+1][j];
                else
                    cost[i][j]+=min(cost[i][j+1],min(cost[i+1][j],cost[i+1][j+1]));
            }
        }

/*    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++)
            cout<<cost[i][j]<<" ";
        cout<<endl;
    }
*/
    cout<<cost[0][0]<<endl;
    return 0;
}  

/*

Test case:-
3
1 2 3
4 8 2
1 5 3

*/

