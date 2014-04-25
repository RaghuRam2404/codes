#include <bits/stdc++.h>
using namespace std;

int main(){
	int i, j, k, l;
	int count = 0;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			for(k=0; k<3; k++){
				for(l=0; l<3; l++){
					if(i==k || j==l);
					else{
						cout<<"("<<i<<","<<j<<") & ("<<k<<","<<l<<")"<<endl;
						count++;
					}
				}
			}
		}
	}
	cout<<count<<endl;
	return 0;
}