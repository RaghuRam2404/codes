#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) (S & (-S)) 
typedef long long ll;

ll B1[50000000], B2[50000000];
 
// Array size
int N;
 
// Point query
// Returns value at position b in the array for ft = B1
// Returns value to be subtracted from query(B1, b) * b for ft = B2
ll query(ll* ft, int b){
        ll sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
}
 
// Range query: Returns the sum of all elements in [1...b]
ll query(int b){
    return query(B1, b) * b - query(B2, b);
}
 
// Range query: Returns the sum of all elements in [i...j]
ll range_query(int i, int j){
    return query(j) - query(i - 1);
}
 
// Point update: Adds v to the value at position k in the array
// ft is the fenwick tree which represents that array
void update(ll* ft, int k, ll v){
        for (; k <= N; k += LSOne(k)) ft[k] += v;
}
 
// Range update: Adds v to each element in [i...j]
void range_update(int i, int j, ll v){
        update(B1, i, v);
        update(B1, j + 1, -v);
        update(B2, i, v * (i - 1));
        update(B2, j + 1, -v * j);
}

void display(){
    for(int i=1; i<=N; i++)
        cout<<B1[i]<<" ";
    cout<<endl;
    for(int i=1; i<=N; i++)
        cout<<B2[i]<<" ";
    cout<<endl;
}

int main(){
	int size = 50000000;
	N = 10;
    range_update(2,9,2);
    range_update(1,1,1);
    range_update(10,10,3);
    cout<<(double)range_query(1,10)/10<<endl;
    cout<<range_query(3,10)<<endl;
	return 0;
}