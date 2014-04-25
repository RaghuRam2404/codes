#include <bits/stdc++.h>
using namespace std;

int main(){
	cout<<"SELECTION SORT\n";
	string link = "http://en.wikipedia.org/wiki/Selection_sort";
	cout<<"Reference : "<<link<<endl;
	int a[10] = {12, 11, 10, 4, 6, 5, 1, 2, 7, 9};

	int i, j, min, n = sizeof(a)/sizeof(a[0]);
	for(i=0; i<n; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(a[min]>a[j])
				min = j;
		}
		if(min != i)
			swap(a[min], a[i]);
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}