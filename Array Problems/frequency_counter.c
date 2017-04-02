#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#define MAX_SIZE 1000000
using namespace std;



typedef struct array{
	int index;
	int val;
	int count;
}arr;

int sortbyval(arr *a,a *b){
	return (a->val<b->val)?1:0;
}

int sortbyfreq(element *a,element *b){
	if(a->freq!=b->freq)
		return (a->freq<b->freq)?1:0;
	else
		return (a->index<b->index)?1:0;
}

void main(){
	int n;
	cin>>n;
	int str[n];
	array*arr[n];
	for(int i=0;i<n;i++){
		cin>>x;
		arr[i]->val=x;
		arr[i]->count=0;
		arr[i]->index=i;
	}
	sort(array,array+n,sortbyfreq);
	sort(array,array+n,sortbyval);
	for(int i=0;i<n;i++){
		cout<<arr[n-i-1]->val<<endl;
	}
}
