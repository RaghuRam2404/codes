#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <climits>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
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
	map<int,int> m;
	int duplicate;
	int maxx;
	void merge(node l, node r){
		if(l.duplicate) {
			//cout<<-1<<" and "<<r.maxx<<endl;
			map<int,int>::iterator it = r.m.begin();
			for(;it!=r.m.end();it++){
				m[(*it).first] = (*it).second;
			}
			maxx = r.maxx;
		} 
		else if(r.duplicate) {
			//cout<<l.maxx<<" and "<<-1<<endl;
			map<int,int>::iterator it = l.m.begin();
			for(;it!=l.m.end();it++){
				m[(*it).first] = (*it).second;
			}
			maxx = l.maxx;
		}
		else{
			//cout<<l.maxx<<" and "<<r.maxx<<endl;
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
			maxx = max(l.maxx, r.maxx);
		}
	}
	void create(int val){
		if(val != -1)
			m[val] = 1;
		maxx = val;
	}
};

class SegmentCount{
	int n, max;
	node *A;
	int *input;
	public:
		SegmentCount(int no, int *in){ 
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
			if (querye < querys || querys > to || querye < from){ node id; id.duplicate=1; id.create(-1); return id;}	// out of range
			if (querys>=from && querye<=to) return A[currNode];
 
			// search in the range
			node max1 = query(currNode*2, querys, (querys+querye)/2, from, to);
			node max2 = query(currNode*2+1, (querys+querye)/2+1, querye, from, to);
			node c;
			c.merge(max1,max2);
			/*cout<<"MMMMMMM";
			for(map<int,int>::iterator it = c.m.end(); it!=c.m.end(); it++){
				cout<<(it->first)<<" "<<(it->second)<<endl;
			}
			cout<<"EEEEEEEE";*/
			return c;
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
	
	SegmentCount sm(n,a);
	node temp = sm.query(1,0,n-1,0,1);
	cout<<temp.maxx<<endl;
	int op,x,y;
	int m;
	s(m);
	while(m--){
		s(x), s(y), s(X);
		node na = sm.query(1,0,n-1,x-1,y-1);
		int minx;
		for(i=x-1; i<y; i++){
			if(i==x-1)
				minx = a[i];
			else if((a[i] xor X) < (minx xor X))
				minx = a[i];
		}
		/*map<int,int>::iterator it = na.m.begin();
		for(;it!=na.m.end(); it++){
			cout<<(it->first)<<"->"<<(it->second)<<endl;
		}*/
		cout<<na.maxx<<" ";
		if(na.m[na.maxx]==0) cout<<1<<endl;
		else p(na.m[na.maxx]);
	}
	
	return 0;
}