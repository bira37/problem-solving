#include <bits/stdc++.h>
 
using namespace std;
 
struct lalala{
	int time, number, duration;
};
 
int main(){
	int n,q;
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	int server[n+1];
	int deadline[n+1];
	lalala task[q];
	for(int i=0; i<q; i++){
		cin >> task[i].time >> task[i].number >> task[i].duration;
	}
	for(int i=1; i<=n; i++){
		server[i] = -1;
		deadline[i] = -1;
	}
	int tempo=1;
	int iterator = 0;
	int flag;
	int sum = 0;
	while(iterator < q){
		for(int i=1; i<=n; i++){
			if(deadline[i] == tempo){
				server[i] = -1;
				deadline[i] = -1;
			}
		}
		flag = false;
		if(task[iterator].time == tempo){
			flag = true;
			int aux = 0;
			sum = 0;
			for(int i=1; i<=n; i++){
				if(aux >= task[iterator].number) break;
				if(server[i] == -1){
					aux++;
				}
			}
			if(aux == task[iterator].number){
				aux = 0;
				for(int i=1; i<=n; i++){
					if(aux >= task[iterator].number) break;
					if(server[i] == -1){
						sum += i;
						aux++;
						server[i] = iterator;
						deadline[i] = tempo+ task[iterator].duration;
					}
				}
			}
			else flag = false;
			iterator++;
			if(flag) cout << sum << endl;
			else cout << -1 << endl;
		}
		tempo++;
	}
}
