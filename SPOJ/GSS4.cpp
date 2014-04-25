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
#define ll long long
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
	bool flag;
	int numleaves;
	long long add;
	node(){ flag=false; sum=0, numleaves = 1, add=0;}
	void split(node &l, node &r, int left, int right){

	}
	void merge(node &l, node &r){
		sum = l.sum + r.sum;
		numleaves = l.numleaves + r.numleaves;
		add = 0;
		flag = false;
	}
	void create(ll val){
		sum = val;
		add = 0;
		numleaves = 1;
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
			for(int i=0; i<n; i++)
				ss(input[i]);
			int maxHt = (int)(ceil(log2(n))) + 1;
			max = 2*pow(2,maxHt);
			A = new node[max];
			
			createSegmentTree(1,0,n-1);
		}
		
		node newnode(ll val){
			node x;
			x.create(val);
			return x;
		}
		
		void createSegmentTree(int current, int start, int end){
			if (start > end) return;
			if (start == end){ lastIndex=max(lastIndex,current); A[current] = newnode(input[start]); return; }
			createSegmentTree(current*2, start, (start+end)/2);
			createSegmentTree(current*2+1, (start+end)/2+1, end);
			A[current].merge(A[2*current], A[2*current + 1]);
		}
		
		void update_single(node &a){
			a.sum = (ll)(sqrt(a.sum+0.0));
			//a.sum ++;
		}
		
		void range_update(int current, int querys, int querye, int u, int v){
			int mid = (querys+querye)/2;
			int left = current<<1, right = left|1;
			if(querye-querys+1==A[current].sum) return;  
			if(querys>=u && querye<=v){
				if(querys == querye){
				//	cout<<"-> "<<querys<<endl;
					update_single(A[current]);
				//	A[current].split(A[left], A[right], left, right);
					return;
				}
			}
			//if(A[current].flag) A[current].split(A[left], A[right], left, right);
			if(v<querys || u>querye) return;
			range_update(left, querys, mid, u, v);
			range_update(right, mid+1, querye, u, v);
			A[current].merge(A[left],  A[right]);
		}
		
		node query(int currNode, int querys, int querye, int from, int to){
 			int mid = (querys+querye)/2;
			int left = currNode<<1, right = left|1;
			
			if (querye < querys || querys > to || querye < from){ node id; id.create(0); return id;}	// out of range
			if (querys>=from && querye<=to){
				//if(A[currNode].flag)	A[currNode].split(A[left], A[right], left, right); 
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
 		
};


int main(){
	freopen("input.in", "r", stdin);
	int N, i, C, cnt=1;
	int t,from,to,val;
	while(1){
		int *in;
		if(s(N) == EOF) return 0; 
		cout<<"Case #"<<(cnt++)<<":"<<endl;
		SegmentTree st(N);
		s(C);
		while(C--){
			s(t);
			if(t){
				s(from), s(to);
				node aa = st.query(1,0,N-1,from-1, to-1);
				pll(aa.sum);
			}else{
				s(from), s(to);
				//cout<<"BEFORE UPDATE : ";st.print();
				st.range_update(1,0,N-1, from-1, to-1);
				//cout<<"AFTER UDPATE : ";st.print();
				//cout<<endl;
			}
		}
		cout<<endl;
	}
	
	return 0;
}