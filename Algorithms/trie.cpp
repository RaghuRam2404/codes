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

struct TrieNode{
	vector<TrieNode*> next;
	char a;
	node(){ a='\0'; }
};
typedef TrieNode node;

class Trie{
	node root;
public:
	Trie(){}
	void insertWord(String a){
		
	}
	bool searchWord(String a){

	}
	void deleteWord(String a){
		
	}
};

int main(){

	return 0;
}