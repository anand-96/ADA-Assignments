#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
	int d,x,n;
	unordered_map <int,int> ump(100);
	cout<<"Enter n"<<endl;
	cin>>n;
	int arr[n];
	unordered_map<int ,int>::iterator it;
	cout<<"Enter n elements"<<endl;
	for(int i=0;i<n;i++){
		cin>>x;
		arr[i]=x;
		ump[x]++;
		it=ump.find(x);
		if(it->second==2)
			d=x;
	}
	cout<<"Index of element "<<d<<"is :"<<endl;
	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" "<<d<<endl;
		if(arr[i]==d)
			cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}


//unordered map has insertion time and searching time O(1) because it's implementation is hash table.
// complexity of this approach is O(n)
