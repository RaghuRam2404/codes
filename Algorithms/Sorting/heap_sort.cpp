#include <bits/stdc++.h>
using namespace std;

int heapSize;

void max_heapify(int *a, int i){
	if(i>heapSize) return;
	int left = ((i*2) <= heapSize)?(i*2):(-1);
	int right = ((i*2+1) <= heapSize)?(i*2+1):(-1);
	if(left == -1 && right == -1) return;
	if(left == -1){
		if(a[i] < a[right]){
			swap(a[i], a[right]);
			max_heapify(a, right);
		}
	}else if(right == -1){
		if(a[i] < a[left]){
			swap(a[i], a[left]);
			max_heapify(a, left);
		}
	}else{
		int max = (a[right]>a[left])?right:left;
		if(!(a[i]>a[right] && a[i]>a[left])){
			swap(a[i], a[max]);
			max_heapify(a, max);
		}
	}
}

void build_max_heap(int *a, int n){
	for(int i=n/2; i>=1; i--)
		max_heapify(a, i);
}

void heap_sort(int *a, int n){
	heapSize = n;
	build_max_heap(a, n);
	for(; heapSize >=1; ){
		swap(a[1], a[heapSize]);
		heapSize--;
		max_heapify(a, 1);
	}
}

int main(){
	
	int a[11] = {-1, 12, 11, 10, 4, 6, 5, 1, 2, 7, 9};
	heap_sort(a, 10);
	for(int i=1; i<=10; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}