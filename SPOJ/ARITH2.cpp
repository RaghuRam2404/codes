#include <stdio.h>

int main() {
  char o;
  long long n, a, res;

  scanf( "%lld", &n );
  while ( n-- ) {
    o = 0;
    scanf( "%lld", &res );
    while ( 1 ) {
      scanf( "%s", &o );
      if ( o == '=' ) {
        break;
      }

      scanf( "%lld", &a );
      switch ( o ) {
        case '+':
          res += a;
          break;
        case '-':
          res -= a;
          break;
        case '*':
          res *= a;
          break;
        case '/':
          res /= a;
          break;
      }
    }
    printf( "%lld\n", res );
  }

  return 0;
}