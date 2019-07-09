#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,k,target;
	cin >> n >> k;
	char board[n];
	int goal;
	for(int i=0; i<n; i++){
		cin >> board[i];
		if(board[i] == 'G'){
			goal = i;
			board[i] = '.';
		}
		else if(board[i] == 'T') target = i;
	}
	
	int dist = abs(goal - target);
	if(dist % k) cout << "NO" << endl;
	else {
		int flag = 1;
		if(target > goal){
			while(goal < target){
				goal += k;
				if(goal >= n || board[goal] == '#'){
					flag = 0;
					break;
				}
				else if(goal == target) break;
			}
		}
		else if(target < goal){
			while(target < goal){
				goal -= k;
				if(goal < 0 || board[goal] == '#'){
					flag = 0;
					break;
				}
				else if(goal == target) break;
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
} 
