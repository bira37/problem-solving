#include <bits/stdc++.h>

using namespace std;

bool min(char c){
	if('a' <= c && c <= 'z') return true;
	else return false;
}

int main(){
	string x;
	while(cin >> x){
		string alt1, alt2;
		for(int i=0; i<x.size(); i++){
			if(!(i % 2)){
				if(!min(x[i])) alt1+= (x[i]+32);
				else alt1 += x[i];
				if(min(x[i])) alt2+= (x[i]-32);
				else alt2+=x[i];
			}
			else{
				if(min(x[i])) alt1+= (x[i]-32);
				else alt1+=x[i];
				if(!min(x[i])) alt2+= (x[i]+32);
				else alt2 += x[i];
			}
		}
		//cout << x << " " << alt1 << " " << alt2 << endl;
		int ed1=0,ed2=0;
		for(int i=0; i<x.size(); i++){
			if(x[i] != alt1[i]) ed1++;
			if(x[i] != alt2[i]) ed2++;
		}
		cout << min(ed1,ed2) << endl;
	}	 
}
		 
		

