#include <bits/stdc++.h>
using namespace std;

int** generate(int n){
	int i,from,to,j;
	int ** v;
	v = new int*[n];
	for(i=0; i<n; i++)
		v[i]=new int[n];

	int size = 1;
	from = n/2, to = n/2;
	for(i=0; i<n; i++){
		
		if(i==0);
		else if(i<(n/2))	from--, to++;
		else if(i>(n/2)) from++, to--;
		else from = 0, to = n-1;

		for(j=0; j<n; j++){
			v[i][j] = (j>=from && j<=to);
		}
	}
	return v;
}

int compare(int **first, int **second, int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(first[i][j] != second[i][j]) return 0;
		}
	}
	return 1;
}

int main(){
	freopen("input.in", "r", stdin);
	int i, j;
	int n;
	cin>>n;
	int ** val;
	val = new int*[n];
	for(i=0; i<n; i++)
		val[i]=new int[n];
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			cin>>val[i][j];

	/*for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			cout<<val[i][j]<<" ";
		cout<<endl;
	}*/

	int** newmat = generate(n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			cout<<newmat[i][j]<<" ";
		cout<<endl;
	}
	cout<<compare(val, newmat, n)<<endl;
}