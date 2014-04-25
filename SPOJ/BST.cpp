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

int main(void)
{
  int N,i,root;
  long long int c = 0, val = 0;
  map<int,long long int> list;
  scanf("%d",&N);
  while(N--)
  {
    int right = 0, left = 0;
    scanf("%d",&i);
    list[i] = 0;
    if(list.size()==1)
    { 
      root = i;
      printf("%d\n",0);
      continue;
    }
    map<int,long long int>::iterator it = list.find(i);
    map<int,long long int>::iterator it_copy = it;
    if(i>root)
    {
      if(++it != list.end())
        right = it->second;
      left = (--it_copy)->second;
    }
    else
    {
      right = (++it)->second;
      if(it_copy != list.begin())
        left = (--it_copy)->second;
    }
    val = max(right,left);
    val += 1;
    list[i] = val;
    c = c+val;
    printf("%lld\n",c);
  }
} 