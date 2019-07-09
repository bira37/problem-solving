#include <bits/stdc++.h>
 
using namespace std;
 
vector< pair<int, char> > ans;
 
int monsters[500];
int newmonsters[500];
int flag = 1;
 
void simulation(pair<int, int> array, int monsterSize){
	if(array.first == array.second) return;
	int maxValue = 0;
	int max = 0;
	for(int i=array.first; i<= array.second; i++){
		if(maxValue <= monsters[i]){
			if(monsters[std::max(i-1, array.first)] < monsters[i] || monsters[i] > monsters[std::min(i+1,array.second)]){
				max = i;
				maxValue = monsters[i];
			}
		}
	}
	//cout << "maximo e maximovalor " << max << " " << maxValue << endl;
	int deslocdir = 0;	
	while(maxValue < monsterSize){
		//cout << "max inicio " << max+1 << endl;
		if(max -1 >= array.first && maxValue > monsters[max -1]){
			//cout << "comeu o da esquerda" << endl;
			maxValue += monsters[max -1];
			ans.push_back(make_pair(max+1, 'L'));
			max = max -1;
			deslocdir = deslocdir + 1;
		}
		else if(max+1 <= array.second && maxValue > monsters[max +1+deslocdir]){
			//cout << "comeu o da direita" << endl;
			maxValue += monsters[max +1+deslocdir];
			ans.push_back(make_pair(max+1, 'R'));
			deslocdir = deslocdir +1;
		}
		else {
			flag = 0;
			return;
		}
		//cout << "max final " << max+1 << endl;
	}
}
 
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++) cin >> monsters[i];
	int m;
	cin >> m;
	for(int i=0; i<m; i++) cin >> newmonsters[i];
	vector < pair<int, int> > subvector;
	int lastindex = 0;
	int index = 0;
	for(int i=0; i<m; i++){
		int sum = 0;
		while(index < n){
			sum += monsters[index];
			if(sum >= newmonsters[i]){
				if(sum > newmonsters[i]){
					cout << "NO" << endl;
					return 0;
				}
				subvector.push_back(make_pair(lastindex,index));
				index++;
				lastindex = index;
				break;
			}
			else index++;
		}
	}
	//cout << "aqui" << endl;
	if(index < n || (subvector.size() != m)){
		cout << "NO" << endl;
		return 0;
	}
 
	int desloc = 0;
	for(int i = subvector.size() -1; i>=0; i--){
		//cout << subvector[i].first << " " << subvector[i].second << endl;
		if(flag){
			simulation(subvector[i],newmonsters[i]);
			//desloc = subvector[i+1].first - i;
		}
		else break;
	}
	
	if(!flag){
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	for(int i=0; i<ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
