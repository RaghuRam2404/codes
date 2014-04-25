#include <bits/stdc++.h>
using namespace std;

void combine(int *a, int *b, int from, int mid, int to){
	// 2 intervals
	// [from, mid] and [mid+1, to]
	int fromCount = from, toCount = mid+1;
	for(int i=from; i<=to; i++){
		if(fromCount <= mid && (a[fromCount] <= a[toCount] || toCount > to)){
			b[i] = a[fromCount];
			fromCount++;
		}else{
			b[i] = a[toCount];
			toCount++;
		}
	}
	copy(a, b, from, mid, to);
}

void copy(int *a, int *b, int from, int mid, int to){
	for(int i=from; i<=to; i++)	a[i] = b[i];
}

void mergeSort(int *a, int *b, int from, int to){
	if(from == to) return;
	int mid = (to+from)/2;
	mergeSort(a, b, from, mid);
	mergeSort(a, b, mid+1, to);
	combine(a, b, from, mid, to);
}

int main(){
	cout<<"MERGE SORT \n";
	string link = "http://en.wikipedia.org/wiki/Merge_sort";
	cout<<"Reference : "<<link<<endl;
	int a[10] = {12, 11, 10, 4, 6, 5, 1, 2, 7, 9};
	int b[10], n=10;
	mergeSort(a, b, 0, n-1);
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}