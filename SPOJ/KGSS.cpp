#include <iostream>
#include <stdio.h>
#include <climits>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <deque>
using namespace std;

/*******/
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n",a)
#define sll(a) scanf("%lld", &a)
#define pll(a) printf("%lld\n", a)
#define ss(a) scanf("%ull", &a)
#define pp(a) printf("%ull\n", a)
#define sstring(a) scanf("%s", a)
/*******/

#define max(a,b) (((a)>(b))?(a):(b))

struct node{
	long long sum;
	int m[2];
	int numleaves;
	node(){ sum=0, numleaves = 1;}
	void split(node &l, node &r, int left, int right){

	}
	void merge(node &l, node &r){
		int maxa[4];
		if(l.numleaves==1) maxa[0] = INT_MIN, maxa[1] = l.sum;
		else maxa[0] = l.m[0], maxa[1] = l.m[1];	
		if(r.numleaves==1) maxa[2] = INT_MIN, maxa[3] = r.sum;
		else maxa[2] = r.m[0], maxa[3] = r.m[1];

		m[0] = max(maxa[0], max(maxa[1], max(maxa[2],maxa[3])));
		m[1] = INT_MIN;
		if(m[0] == maxa[0]) m[1] = max(maxa[1], max(maxa[2],maxa[3]));
		if(m[0] == maxa[1]) m[1] = max(maxa[0], max(maxa[2],maxa[3]));
		if(m[0] == maxa[2]) m[1] = max(maxa[0], max(maxa[1],maxa[3]));
		if(m[0] == maxa[3]) m[1] = max(maxa[0], max(maxa[1],maxa[2]));

		numleaves = l.numleaves + r.numleaves;
	}
	void create(int val){
		m[0] = INT_MIN;
		m[1] = val;
		sum = val;
	}
};

class SegmentTree{
	int n, max;
	node *A;
	int *input;
	int lastIndex;
	public:
		SegmentTree(int no){ 
			n= no; 
			lastIndex = 0;
			input = new int[n];
			memset(input, 0, sizeof(input));
			int maxHt = (int)(ceil(log2(n))) + 1;
			max = 2*pow(2,maxHt);
			A = new node[max];
			
			createSegmentTree(1,0,n-1);
		}
		
		node newnode(int num){
			node x;
			x.create(num);
			return x;
		}
		
		void createSegmentTree(int current, int start, int end){
			if (start > end) return;		// out of bound
			if (start == end){ lastIndex=max(lastIndex,current); s(input[start]); A[current] = newnode(input[start]); return; }	// leaf node
			createSegmentTree(current*2, start, (start+end)/2);
			createSegmentTree(current*2+1, (start+end)/2+1, end);
			A[current].merge(A[2*current], A[2*current + 1]);
		}
		
		void update_single(node &a, long long val){
			a.sum = val;
		}
		
		void range_update(int current, int querys, int querye, int u, int v, long long val){
			
			int mid = (querys+querye)/2;
			int left = current<<1, right = left|1;
			
			if(querys>=u && querye<=v){
				input[querys] = val;
				update_single(A[current], val);
				return;
			}
			if(v<querys || u>querye) return ;
			range_update(left, querys, mid, u, v, val);
			range_update(right, mid+1, querye, u, v, val);
			A[current].merge(A[left],  A[right]);
		}
		
		node query(int currNode, int querys, int querye, int from, int to){
 			int mid = (querys+querye)/2;
			int left = currNode<<1, right = left|1;
			
			if (querye < querys || querys > to || querye < from){ node id; id.create(0); return id;}	// out of range
			if (querys>=from && querye<=to){ 
				return A[currNode];	
			}
			node a,b,c;
			a=query(left, querys, mid, from, to);
			b=query(right, mid+1, querye, from, to);
			c.merge(a,b);
			return c;
		}
 		
 		void print(){
 			for(int i=1; i<=lastIndex; i++) cout<<"("<<A[i].sum<<") ";
 			cout<<endl;
 		}

 		int get(int index){
 			return input[index];
 		}
 		
};


int main() {
	//freopen("input.in", "r", stdin);
	int N, T, i, C;
	int t,from,to,val;

	s(N);
	SegmentTree st(N);
	s(C);
	while(C--){
		char op;
		op = getchar();
		while(op!='Q' && op!='U') op = getchar();
		s(from), s(to);

		if(op == 'Q'){
			if(from == to)
				cout<<st.get(from-1)<<endl;
			else{
				node aa = st.query(1,0,N-1,from-1, to-1);
				cout<<aa.m[0]+aa.m[1]<<endl;
			}
		}else{
				//cout<<"BEFORE UPDATE : ";st.print();
				st.range_update(1,0,N-1, from-1, from-1, to);	
				//cout<<"AFTER UDPATE : ";st.print();
		}
	}
	return 0;
}