#include <bits/stdc++.h>
#define endl '\n'
#define ii pair<int,int>
#define ff first
#define ss second

using namespace std;


vector< pair<int, int> > block[330];
int cnt[330][1000001] = {0};
int v[112345];
int p[112345];
int lazy[330] = {0};

int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	
	int sqr = sqrt(n)+5;
	
	for(int i=0; i<n; ++i){
		scanf("%d",v+i);
		p[i] = v[i];
		if(i) p[i]^=p[i-1];
		block[i/sqr].push_back(make_pair(p[i], i));
	}
	
	for(int i=0; i<sqr; ++i){
		sort(block[i].begin(), block[i].end());
		for(int j=0; j<block[i].size(); j++){
			cnt[i][block[i][j].ff]++;
		}
	}
	
	while(q--){
		int op, i, k;
		scanf("%d%d%d", &op, &i, &k);
		i--;
		if(op == 1){
			int curr = i/sqr;
			
			int att = v[i]^k;
			v[i] = k;
			for(int j=0; j<block[curr].size(); ++j){
				if(block[curr][j].ss >= i){
					cnt[curr][block[curr][j].first]--;
					block[curr][j].first ^= att;
					cnt[curr][block[curr][j].first]++;
				}
			}
			sort(block[curr].begin(), block[curr].end());
			for(int j = curr+1; j<sqr; ++j){
				lazy[j] ^= att;
			}
		}
		else {
			int ans = 0;
			int curr = i/sqr;
			int get = lazy[curr]^k;
			int l = lower_bound(block[curr].begin(), block[curr].end(), make_pair(get, -1)) - block[curr].begin();
			while(l < block[curr].size() && block[curr][l].ff == get && block[curr][l++].ss <= i) ans++;
			for(int j=curr-1; j>=0; --j){
				get = lazy[j]^k;
				ans += cnt[j][get];
			}
			printf("%d\n", ans);
		}
	}
}
		
	
	
	
