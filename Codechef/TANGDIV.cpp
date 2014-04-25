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
#define LSOne(S) (S & (-S)) 

ll B1[50000005], B2[50000005];
int N, k, p;

struct fromTo{
    int from, to;
};
typedef fromTo ft;
vector<ft> kft, pft;

ll query(ll* ft, int b){
        ll sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
}

ll query(int b){
    return query(B1, b) * b - query(B2, b);
}

ll range_query(int i, int j){
    return query(j) - query(i - 1);
}

void update(ll* ft, int k, ll v){
        for (; k <= N; k += LSOne(k)) ft[k] += v;
}

void range_update(int i, int j, ll v){
        update(B1, i, v);
        update(B1, j + 1, -v);
        update(B2, i, v * (i - 1));
        update(B2, j + 1, -v * j);
}

bool ok(){
    int i, from, to;
    for(i=1; i<=k; i++){
        ft temp = kft[i-1];
        from = temp.from, to = temp.to;
        ull start = range_query(from, from), end = range_query(to, to);
        cout<<from<<" "<<to<<" is the details and "<<start<<" "<<end<<endl;
        if(start == end && start != 0){
            ull ans = 0;
            int count = 0;
            if(from <= to)
                ans = range_query(from, to), count = to-from+1;
            else
                ans = range_query(from, N), ans+=range_query(1,to), count = N-from+1+to;
            cout<<"Answer : "<<ans<<" and count is "<<count 1<<endl;
            if(ans%count != 0)
                return false;
        }else return false;
    }
    return true;
}

int main(){
    freopen("input.in", "r", stdin);
    int t, from, to, i;
    s(t);
    while(t--){
        s(N), s(k), s(p);
        memset(B1, 0, sizeof(B1));
        memset(B2, 0, sizeof(B2));
        kft.clear();
        pft.clear();
        for(i=0; i<k; i++){
            ft temp;
            s(temp.from), s(temp.to);
            kft.push_back(temp);
        } 
        for(i=0; i<p; i++){
            ft temp;
            s(temp.from), s(temp.to);
            pft.push_back(temp);
            if(temp.from <= temp.to)
                range_update(temp.from, temp.to, i+1);
            else{
                range_update(temp.to, N, i+1);
                range_update(1, temp.from, i+1);
            }
        } 

        if(ok())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}