#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

int main(){
  int n,m;
  int a,b;
	cin>>n>>m;
	vector< ii > p[n];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		int y=n-b;
		int x=a-1;
		p[y].push_back(ii(x,i+1));
	}
	priority_queue< ii ,vector< ii >, greater< ii > > pq;
	vector<int> ans;
	for(int i=0;i<n;i++){
	  
		for(int j=0;j<p[i].size();j++){
			pq.push(ii(p[i][j].first,p[i][j].second));
		}
		
		if(!pq.empty()){
			while(!pq.empty() && pq.top().first < i){
				pq.pop();
			}
		}
		
		if(!pq.empty()){
			ans.push_back(pq.top().second);
			pq.pop();
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
	  if(i) cout <<  " ";
	  cout << ans[i];
	}
	cout << endl;
}