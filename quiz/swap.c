#include <stdio.h>

int main(){
	int n, *a, i, larg[3], small[2], elt; 
	scanf("%d", &n);
	a = malloc(sizeof(int)*n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	if(n>2){
		for(i=0; i<n; i++){
			if(i==0){
				larg[0] = small[0] = i;
				larg[1] = larg[2] = small[1] = -1;
			}else{
				elt = a[i];
				if(elt > a[larg[0]]){
					larg[2] = larg[1];
					larg[1] = larg[0];
					larg[0] = i;
				}else if(elt > a[larg[1]] || larg[1] == -1 ){
					larg[2] = larg[1];
					larg[1] = i;
				}else if(elt > a[larg[2]] || larg[2] == -1 ){
					larg[2] = i;
				}

				if(elt < a[small[0]]){
					small[1] = small[0];
					small[0] = i;
				}else if(elt < a[small[1]] || small[1] == -1){
					small[1] = i;
				}
			}
		}
		// swap larg[2] and small[1]
		elt = a[larg[2]];
		a[larg[2]] = a[small[1]];
		a[small[1]] = elt;
		for(i=0; i<n; i++){
			printf("%d ", a[i]);
		}printf("\n");
	}
	return 0;
}