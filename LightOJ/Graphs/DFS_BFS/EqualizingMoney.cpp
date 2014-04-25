 #include <bits/stdc++.h>
 using namespace std;
 
 typedef long long ll;
 typedef unsigned long long ull;
 #define s(a) scanf("%d",&a)
 #define p(a) prllf("%d\n",a)
 #define sll(a) scanf("%lld", &a)
 #define pll(a) prllf("%lld\n", a)
 #define ss(a) scanf("%llu", &a)
 #define pp(a) prllf("%llu\n", a)
 #define sstring(a) scanf("%s", a)
 ll readll () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
ll amt[1005];
vector<ll> vec[1005];

inline void addEdge(ll u, ll v){
	u--;
	v--;
	vec[u].push_back(v);
	vec[v].push_back(u);
}

ll allVisited(bool *analysed, ll size){
	ll i=0;
	for(i=0; i<size; i++){
		if(analysed[i] == false)	
			return i;
	}
	return -1;
}

int main(){
	//freopen("input.in", "r", stdin);
	ll T, n, m, i, j, u, v, total;
	ss(T);
	//T = readll();
	for(ll test=1; test<=T; test++){
		total = 0;
		ss(n); ss(m);
		//n = readll();
		//m = readll();
		for(i=0; i<n; i++) ss(amt[i]), total += amt[i];
		for(i=0; i<n; i++) vec[i].clear();

		for(i=0; i<m; i++){
			ss(u), ss(v);
			addEdge(u,v);
		}
		if(total%n != 0){
			cout<<"Case "<<test<<": No\n";
			continue;
		}
		ll avg = total/n;
		int st=-1, tst;
		bool *visited = new bool[n];
		memset(visited, false, sizeof(visited));
		bool flag = true;
		for(i=0; i<n && flag; i++){
			ll sum = 0, cnt=0;
			if(visited[i] == false){
				queue<int> q;
				q.push(i);
				cnt=1;
				sum=amt[i];
				while(!q.empty()){
					int node = q.front();
					q.pop();
					for(j=0; j<vec[node].size(); j++){
						if(!visited[vec[node][j]]){
							cnt++;
							sum += amt[vec[node][j]];
							visited[vec[node][j]] = true;
							q.push(vec[node][j]);
						}
					}
				}
				if(sum%cnt != 0) flag = false;
				else{
					tst = sum/cnt;
					if(st==-1) st=tst;
					else{
						if(tst!=st) flag = false;
	 				}
	 			}
			}
		}
		if(flag) cout<<"Case "<<test<<": Yes\n";
		else cout<<"Case "<<test<<": No\n";
	}
	return 0;
}