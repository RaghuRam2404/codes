#include <bits/stdc++.h>
using  namespace std;

int main(){
	int n;
	//freopen("input.in", "r", stdin);
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		int l1=0, l2 = s.length(), i=0;
		if(s.find("www.") == 0)
			i = 4;
		if(s.find(".com") != std::string::npos)
			l1++;
		for(; i<s.length(); i++){
			if(s[i] == 'a' || s[i]=='e' || s[i]=='i' || s[i] == 'o' || s[i]=='u' || s[i] == 'A' || s[i]=='E' || s[i]=='I' || s[i] == 'O' || s[i]=='U' );
			else l1 ++;
		}
		cout<<l1<<"/"<<l2<<endl;
	}
	return 0;
}