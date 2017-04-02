#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

int main(){
	int n,num,weight;
	multiset< pair<int, int> >a;
	cout<<"Enter n"<<endl;
	cin>>n;
	cout<<"Enter n elements along with its weight"<<endl;
	
	for(int i=0;i<n;i++){
		cin>>num>>weight;
		a.insert(pair<int,int>(weight,num));
	}

	multiset<pair<int,int>>::reverse_iterator it;
	cout<<"Number\tWeights"<<endl;
	for(it=a.rbegin();it!=a.rend();it++){
		cout<<it->second<<"\t"<<it->first<<endl;
	}
}
// Multisets are implemented as binary search tree.
// linear in time if the elements are already sorted.
// For unsorted elements,running time is O(n*logn).