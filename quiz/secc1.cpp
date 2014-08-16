#include <bits/stdc++.h>
using namespace std;

int** generate(int n){
	int i;
	int ** val;
	val = new int*[n];
	for(i=0; i<n; i++)
		val[i]=new int[n];

	int size = 1;
	for(i=0; i<n; i++){
		if(i<(n/2) || i>(n/2))	from = (n/2)-size+1, to = (n/2)+size-1;
		else if(i==n/2) from = 0, to = n-1,size = n;

		for(j=0; j<n; j++){
			if(j>=from && j<=to)
				val[i][j] = 1;
			else val[i][j] = 0;

			if(i<(n/2)) size+=2;
			else size-=2;
		}
	}

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

	int ** newmat = generate(n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			cout<<val[i][j]<<"___";
		cout<<endl;
	}

}