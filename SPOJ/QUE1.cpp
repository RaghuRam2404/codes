#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n",a)
#define sll(a) scanf("%lld", &a)
#define pll(a) printf("%lld\n", a)
#define ss(a) scanf("%llu", &a)
#define pp(a) printf("%llu\n", a)
#define sstring(a) scanf("%s", a)

int main(){
	freopen("input.in", "r", stdin);
	int T, N, i;
	int ht[1003];
	s(T);
	while(T--){
		vector<pair<int,int> > v;
		s(N);
		for(i=0; i<N; i++)
			s(ht[i]);
		for(i=0; i<N; i++){
			int temp = 0;
			s(temp);
			pair<int, int> p;
			p.first = temp;
			p.second = ht[i];
			v.push_back(p);
		}
		sort(v.begin(), v.end());

		list<int> l;
		list<int>::iterator it = l.begin(), it2;
		for(i=0; i<v.size(); i++){
			pair<int, int> p;
			p = v[i];
			//cout<<p.first<<","<<p.second<<" ";

			int bigCount = 0;	
			bool bigCrossed = false, inserted = false;;
			if(p.first == 0){
				l.push_back(p.second);
				continue;
			}
			if(l.size() == 0) l.push_back(p.second);
			it = l.begin();
			for(; it!=l.end(); it++){
				if(*it > p.second) bigCount++;
				if(bigCount == p.first) bigCrossed = true;
				if(bigCrossed && bigCount>p.first){
					l.insert(it, p.second);
					inserted = true;
					break;
				}
			}
			if(!inserted) l.push_back(p.second);
		}//cout<<endl;
		for(it=l.begin(); it!=l.end(); it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	return 0;
}