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

class FFTMultiply{
    typedef complex<double> base;

public: 
    vector<int> a, b, c;
    void getInput(std::vector<int> &v){
        v.clear();
        //string input;
        int i=0;
        //cin>>input;
        char input[10005];
        sstring(input);
        int len = strlen(input);
        for(i=len-1; i>=0; i--){
            v.push_back(int(input[i]-'0'));
        }
    }

    void fft (vector<base> & a, bool invert) {
        int n = (int) a.size();
     
        for (int i=1, j=0; i<n; ++i) {
            int bit = n >> 1;
            for (; j>=bit; bit>>=1)
                j -= bit;
            j += bit;
            if (i < j)
                swap (a[i], a[j]);
        }
     
        for (int len=2; len<=n; len<<=1) {
            double ang = 2*M_PI/len * (invert ? -1 : 1);
            base wlen (cos(ang), sin(ang));
            for (int i=0; i<n; i+=len) {
                base w (1);
                for (int j=0; j<len/2; ++j) {
                    base u = a[i+j],  v = a[i+j+len/2] * w;
                    a[i+j] = u + v;
                    a[i+j+len/2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert)
            for (int i=0; i<n; ++i)
                a[i] /= n;
    }
/*
    void fft (vector<base> & a, bool invert) {
        int n = (int) a.size();
        if (n == 1)  return;
     
        vector<base> a0 (n/2),  a1 (n/2);
        for (int i=0, j=0; i<n; i+=2, ++j) {
            a0[j] = a[i];
            a1[j] = a[i+1];
        }
        fft (a0, invert);
        fft (a1, invert);
     
        double ang = 2*M_PI/n * (invert ? -1 : 1);
        base w (1),  wn (cos(ang), sin(ang));
        for (int i=0; i<n/2; ++i) {
            a[i] = a0[i] + w * a1[i];
            a[i+n/2] = a0[i] - w * a1[i];
            if (invert)
                a[i] /= 2,  a[i+n/2] /= 2;
            w *= wn;
        }
    }
*/
    void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
        vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
        size_t n = 1;
        while (n < max (a.size(), b.size()))  n <<= 1;
        n <<= 1;
        fa.resize (n),  fb.resize (n);
     
        fft (fa, false),  fft (fb, false);
        for (size_t i=0; i<n; ++i)
            fa[i] *= fb[i];
        fft (fa, true);
     
        res.resize (n);
        for (size_t i=0; i<n; ++i){
            res[i] = int (fa[i].real() + 0.5);
        }
        int limit = -1;
        // trim the extra zeros
        for(int i=n-1; i>=0; i--){
            if(res[i] != 0){ limit = i; break; }
        }
        
        int carry = 0;
        if(limit == -1){
            res.clear();
            res.push_back(0);
        }else{
            for (size_t i=0; i<=limit; ++i) {
                res[i] += carry;
                carry = res[i] / 10;
                res[i] %= 10;
                //cout<<res[i]<<" ";
            }//cout<<endl;
            res.erase(res.begin()+limit+1, res.end());
        }
    }
    void printNum(const vector<int> v){
        for(int i=v.size()-1; i>=0; i--)
            cout<<v[i];
    }
};

int main() {
    //freopen("input.in", "r", stdin);
    int t;
    s(t);
    while(t--){
        FFTMultiply f;
        f.getInput(f.a);
        f.getInput(f.b);
        vector<int> c;
        f.multiply(f.a, f.b, c);
        f.printNum(c);
        cout<<endl;
    }
}


