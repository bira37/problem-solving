#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
loop:	while(cin >> s){
	
		int a = 0, b = 0;
		//normal match
		int arem = 5, brem = 5;
		for(int i=0; i<10; i++){
			if(i%2) brem--;
			else arem--;
			if(i%2 && s[i] == '1'){
				b++;
			}
			else if(i%2 == 0 && s[i] == '1') a++;
			//cout << a << " " << b << endl;
			if(a > b){
				int need = a-b;
				if(brem < need){
					cout << "TEAM-A " << i+1 << endl;
					goto loop;
				}
			}
			else if(b > a){
				int need = b-a;
				if(arem < need){
					cout << "TEAM-B " << i+1 << endl;
					goto loop;
				}
			}
		} 
		if(a > b){
			cout << "TEAM-A " << 10 << endl;
			goto loop;
		}
		else if(b > a){
			cout << "TEAM-B " << 10 << endl;
			goto loop;
		}
	
		for(int i=10; i<20; i+=2){
			if(s[i] == '1' && s[i+1] == '0'){
				cout << "TEAM-A " << i+2 << endl;
				goto loop;
			}
			else if(s[i] == '0' && s[i+1] == '1'){
				cout << "TEAM-B " << i+2 << endl;
				goto loop;
			}
		}
	
		cout << "TIE" << endl;
	}
}
	
