// Reference : http://en.wikipedia.org/wiki/Insertion_sort
#include <bits/stdc++.h>
using namespace std;

int main(){
	cout<<"INSERTION SORT \n";
	string link = "http://en.wikipedia.org/wiki/Insertion_sort";
	cout<<"REFERENCE : "<<link<<endl;
	int a[10] = {12, 11, 10, 4, 6, 5, 1, 2, 7, 9};
	int n = sizeof(a)/sizeof(a[0]);
	for(int i=1; i<n; i++){
		int j = i;
		while(j>0 && a[j-1]>=a[j]){
			swap(a[j-1], a[j]);
			j--;
		}
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}