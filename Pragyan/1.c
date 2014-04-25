#include <stdio.h>
#include <string.h>
#include <ctype.h>

int a[1024]; // first multiplicand
int b[1024]; // second multiplicand
int r[6 * 1024]; // result goes here
int d_a; // length of a
int d_b; // length of b
int d; // 15imum length
int i; // counter

void gradeSchool(int *a, int *b, int *ret, int d) {
    int i, j;
    for(i = 0; i < 2 * d; i++) ret[i] = 0;
    for(i = 0; i < d; i++) {
        for(j = 0; j < d; j++) ret[i + j] += a[i] * b[j];
    }
}

void doCarry(int *aa, int dd) {
    int c;
    int i;

    c = 0;
    for(i = 0; i < dd; i++) {
        a[i] += c;
        if(a[i] < 0) {
            c = -(-(aa[i] + 1) / 10 + 1);
        } else {
            c = aa[i] / 10;
        }
        aa[i] -= c * 10;
    }
    if(c != 0) fprintf(stderr, "Overflow %d\n", c);
}

void getNum(int *aa, int *d_a) {
    int c,len;
    int i, j;
    int cnt = 0;
    *d_a = 0;
    char input[1024];
    scanf("%s", input);
    printf("--%s--\n", input);

    len = strlen(input);
    //cout<<"IN-->"<<input<<" "<<strlen(input)<<endl;
    for(j=0; j<len; j++){
        c = input[j];
        //if(c == '\n' || c==' ' || c == EOF) break;
        if(*d_a >= 1024) {
            fprintf(stderr, "using only first %d digits\n", 1024);
            while(c != '\n' && c != EOF) c = getchar();
        }
        aa[*d_a] = c - '0';
        ++(*d_a);   
    }
    // reverse the number so that the 1's digit is first
    for(i = 0; i * 2 < *d_a - 1; i++) {
        c = aa[i], aa[i] = aa[*d_a - i - 1], aa[*d_a - i - 1] = c;
    }
}
void get(){
    getNum(a, &d_a);
    getNum(b, &d_b);
    if(d_a < 0 || d_b < 0) {
        printf("INVALID NUMBER\n");
        return;
    }
    //printNum(a, d_a); cout<<endl;
    //printNum(b, d_b); cout<<endl;
    // let d be the smallest power of 2 greater than d_a and d_b,
    // and zero out the rest of a and b.
    i = (d_a > d_b) ? d_a : d_b;
    for(d = 1; d < i; d *= 2);
    for(i = d_a; i < d; i++) a[i] = 0;
    for(i = d_b; i < d; i++) b[i] = 0;
}

void karatsubaMUL(int *aa, int *bb, int *ret, int dd) {
    int i;
    int *ar = &aa[0]; // low-order half of a
    int *al = &aa[dd/2]; // high-order half of a
    int *br = &bb[0]; // low-order half of b
    int *bl = &bb[dd/2]; // high-order half of b
    int *asum = &ret[dd * 5]; // sum of a's halves
    int *bsum = &ret[dd * 5 + dd/2]; // sum of b's halves
    int *x1 = &ret[dd * 0]; // ar*br's location
    int *x2 = &ret[dd * 1]; // al*bl's location
    int *x3 = &ret[dd * 2]; // asum*bsum's location

    if(dd <= 2) {
        gradeSchool(aa, bb, ret, dd);
        return;
    }

    // compute asum and bsum
    for(i = 0; i < dd / 2; i++) {
        asum[i] = al[i] + ar[i];
        bsum[i] = bl[i] + br[i];
    }

    // do recursive calls (I have to be careful about the order,
    // since the scratch space for the recursion on x1 includes
    // the space used for x2 and x3)
    karatsubaMUL(ar, br, x1, dd/2);
    karatsubaMUL(al, bl, x2, dd/2);
    karatsubaMUL(asum, bsum, x3, dd/2);

    // combine recursive steps
    for(i = 0; i < dd; i++) x3[i] = x3[i] - x1[i] - x2[i];
    for(i = 0; i < dd; i++) ret[i + dd/2] += x3[i];
}


void printNum(int *aa, int dd) {
    int i;
    for(i = dd - 1; i > 0; i--) if(aa[i] != 0) break;
    for(; i >= 0; i--) printf("%d", aa[i]);
}

inline int inp(){
	int noRead=0;
	char p=getchar_unlocked();
	for(;p<33;){p=getchar_unlocked();};
	while(p>32){
		noRead = (noRead << 3) + (noRead << 1) + (p - '0');
		p=getchar_unlocked();
	}
	return noRead;
}
char * multiply(){
    static char mul[15];
    char c[15], a[15], b[15];
    scanf("%s", a);
    scanf("%s", b);
    char temp[15];
    int la,lb;
    int i,j,k=0,x=0,y;
    long int r=0;
    long sum = 0;
    la=strlen(a)-1;
    lb=strlen(b)-1;

    for(i=0;i<=la;i++){
            a[i] = a[i] - 48;
    }

    for(i=0;i<=lb;i++){
            b[i] = b[i] - 48;
    }

    for(i=lb;i>=0;i--){
         r=0;
         for(j=la;j>=0;j--){
             temp[k++] = (b[i]*a[j] + r)%10;
             r = (b[i]*a[j]+r)/10;
         }
         temp[k++] = r;
         x++;
         for(y = 0;y<x;y++){
             temp[k++] = 0;
         }
    }
   
    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++){
         sum =0;
         y=0;
         for(j=1;j<=lb+1;j++){
             if(i <= la+j){
                 sum = sum + temp[y+i];
             }
             y += j + la + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--){
         mul[j++]=c[i] + 48;
    }
    mul[j]='\0';
    return mul;
}
int mod(int aa, int bb){
	int rem = aa;
	while(rem>=bb){
		rem = rem-bb;
	}
	return rem;
}

int checkPrime(int aa){
	if(aa==1) return 0;
	for(i=2; i*i<=aa; i++)
		if(mod(aa,i) == 0) return 0;
	return 1;
}
int add(int a,int b){

int c=0; //answer
int mask=0,carry=0,sum=0,i;
int a_bit=0,b_bit=0;
for(i=0;i<(32a-1);i++){//pos-1 to leave the MSB as its a sign bit
mask=1<<i;
a_bit=a&mask?1:0;
b_bit=b&mask?1:0;
sum=a_bit+b_bit+carry;
switch(sum){
case 0: carry=0;//this bit in c is already 0
break;
case 1: //make this bit in c 1
c|=mask;
carry=0;
break;
case 2: //make this bit zero and carry=1
//this bit is already zero
carry=1;
break;
case 3: //make this bit 1 and carry =1
c|=mask;
carry=1;
break;
default: printf("this must not have happened \n");
return -1;
}
}
return c;
}

int main(){
	int L, R, g, p, ans=0, count, j;
	L = inp();
	R = inp();
    for(p=0; p+=(L&1)*R, L!=1; L>>=1,R<<=1 );
    /*
	for(i=L; i<=R; i++){
		count = 0;
		for(j=1; j<=i; j++){
			if(mod(i,j) == 0) count ++;
		}
		if(checkPrime(count)) ans++;
	}
	printf("%d\n", ans);
	get();
    karatsubaMUL(a, b, r, d);
    doCarry(r, 2*d);
    printNum(r, 2*d);*/
    printf("%d %d\n", p, add(L, R));
}