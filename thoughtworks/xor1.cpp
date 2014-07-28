#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <climits>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <deque>
using namespace std;

/*******/
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n",a)
#define ss(a) scanf("%ull", &a)
#define pp(a) printf("%ull\n", a)
#define sstring(a) scanf("%s", a)
/*******/

#define max(a,b) (((a)>(b))?(a):(b))

struct node{
	int val;
	int duplicate;
	map<int, int> m;
	void merge(node l, node r){
		if(l.duplicate) {
			val = r.val;
			map<int,int>::iterator it = r.m.begin();
			for(;it!=r.m.end();it++){
				m[(*it).first] = (*it).second;
			}
		} 
		else if(r.duplicate) {
			val = l.val;
			map<int,int>::iterator it = l.m.begin();
			for(;it!=l.m.end();it++){
				m[(*it).first] = (*it).second;
			}
		}
		else{
			map<int,int> lmap = l.m, rmap = r.m;
			map<int,int>::iterator it = lmap.begin();
			for(;it!=lmap.end();it++){
				m[(*it).first] = (*it).second;
			}
			for(it=rmap.begin();it!=rmap.end();it++){
				m[(*it).first] += (*it).second;
			}
			/*cout<<"---------MERGING"<<endl;
			for(it=m.begin();it!=m.end();it++){
				cout<<(it->first)<<"->"<<(it->second)<<endl;
			}
			cout<<"-------END"<<endl;*/
			val = max(r.val, l.val);
		}
	}
	void create(int v){
		val = v;
	}
};

class SegmentMax{
	int n, max;
	node *A;
	int *input;
	public:
		SegmentMax(int no, int *in){ 
			n= no; 
			input = in;
			int maxHt = (int)(ceil(log2(n))) + 1;
			max = 2*pow(2,maxHt);
			A = new node[max];
			createSegmentTree(1,0,n-1);
		}
		
		node newnode(int val){
			node x;
			x.duplicate = 0;
			x.create(val);
			return x;
		}
		
		void createSegmentTree(int current, int start, int end){
			if (start > end) return;		// out of bound
			if (start == end){ A[current] = newnode(input[start]); return; }	// leaf node
			createSegmentTree(current*2, start, (start+end)/2);
			createSegmentTree(current*2+1, (start+end)/2+1, end);
 
			// update intermediate node
			A[current].merge(A[2*current], A[2*current + 1]);
 
		}
		
		node query(int currNode, int querys, int querye, int from, int to){
			if (querye < querys || querys > to || querye < from){ node id; id.duplicate=1; id.create(0); return id;}	// out of range
			if (querys>=from && querye<=to) return A[currNode];
 
			// search in the range
			node max1 = query(currNode*2, querys, (querys+querye)/2, from, to);
			node max2 = query(currNode*2+1, (querys+querye)/2+1, querye, from, to);
			node c;
			c.merge(max1,max2);
			return c;
		}
 		
		// increment values from [from, to] by value
		void update(int currNode, int querys, int querye, int from, int to, int value){
			if(querys>querye || querys>to || querye<from) return;	// out of range
			if(querys == querye){ node x; x.duplicate = 0; x.create(value); A[currNode] = x; return;}
 
			update(currNode*2, querys, (querys+querye)/2, from, to, value);
			update(currNode*2+1, (querys+querye)/2+1, querye, from, to, value);
 
			// update intermediate nodes
			A[currNode].merge(A[currNode*2], A[currNode*2+1]);
		} 
		void printInput(){
			int i;
			for(i=0; i<n; i++)
				cout<<input[i]<<" ";
			cout<<endl;
		}	
};

int main() {
	freopen("input.in", "r", stdin);
	int n,X;
	scanf("%d", &n);
	int i;
	int *a = new int[n];
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	
	SegmentMax sm(n,a);
	int op,x,y;
	int m;
	s(m);
	while(m--){
		s(x), s(y), s(X);
		node na = sm.query(1,0,n-1,x-1,y-1);
		/*map<int,int>::iterator it = na.m.begin();
		for(;it!=na.m.end(); it++){
			cout<<(it->first)<<"->"<<(it->second)<<endl;
		}*/
		cout<<na.val<<" ";
		if(na.m[na.val]==0) cout<<1<<endl;
		else p(na.m[na.val]);
	}
	
	return 0;
}