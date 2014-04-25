#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int i,j,k,flag;
	char s[201],c,res[201];
	while(1)
	{
		if(scanf("%s",s)==-1) break;;
		for(i=0;i<201;i++)
			res[i]='\0'; 
		if(strchr(s,'_')){	// try to convert to java
			flag=0;
			for(i=0;s[i]!='\0';i++)
			if(s[i]>='A'&&s[i]<='Z'){
				flag=1;
				break;
			}
			if(flag==1||s[0]=='_'||s[strlen(s)-1]=='_'||s[0]>'A'&&s[0]<='Z'||strstr(s,"__")) 
				printf("Error!\n");
			else{
				j=0;
				for(i=0;s[i]!='\0';){
					if(s[i]=='_'){
						res[j++]=s[i+1]-32;
						i=i+2;
					}
					else{
						res[j++]=s[i];
						i=i+1;
					}
				}
				res[j]='\0';
				printf("%s\n",res); 
			}
		}
		else{
			if(s[0]>='A'&&s[0]<='Z')
				printf("Error!\n");
			else{
				j=0;
				for(i=0;s[i]!='\0';){
					if(s[i]>='A'&&s[i]<='Z'){
						res[j++]='_';
						res[j++]=s[i]+32;
						i++;
					}
					else{
						res[j++]=s[i];
						i++;
					}
				}
				printf("%s\n",res);
			}
		}
	}
	return 0;
}