#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n,q;
    scanf("%lld%lld", &n, &q);
    int sqr = sqrt(n)+5;
    vector< pair<int,int> > b[330];
    int v[n];
    for(int i=0; i<n; i++){
        scanf("%lld", &v[i]);
        b[i/sqr].push_back(make_pair(v[i], i));
    }
    for(int i=0; i<330; i++) sort(b[i].begin(), b[i].end(), greater< pair<int,int> >());
    while(q--){
        int op;
        scanf("%lld", &op);
        if(op == 1){
            int id, val;
            scanf("%lld%lld", &id, &val);
	        id--;  
            int curr = id/sqr;
            int i = 0;
            while(b[curr][i].second != id) i++;
            b[curr][i].first = val;
            while(i > 0 && b[curr][i-1].first < b[curr][i].first) swap(b[curr][i-1], b[curr][i]), i--;
            while(i < b[curr].size()-1 && b[curr][i].first < b[curr][i+1].first) swap(b[curr][i], b[curr][i+1]), i++;
        }
        else {
            int l,r;
            scanf("%lld%lld", &l, &r);
            l--, r--;
            vector<int> scan(50), new_scan(50);
            int st = l/sqr;
            int ed = r/sqr;
            
            //run on l;
            
            vector<int> side;
            for(int j = 0; j<b[st].size() && side.size() < 50; j++) if(l <= b[st][j].second && b[st][j].second <= r) side.push_back(b[st][j].first);
            int i=0,j=0;
            for(int k=0; k<50; k++){
                if(i < scan.size() && j < side.size()){
                    if(side[j] > scan[i]) new_scan[k] = side[j++];
                    else new_scan[k] = scan[i++];
                }
                else if(i < scan.size()) new_scan[k] = scan[i++];
                else if(j < side.size()) new_scan[k] = side[j++];
            }
            for(int k=0; k<50; k++) scan[k] = new_scan[k];
            
            //run on r
            if(st != ed){
                side.clear();
                for(int j = 0; j<b[ed].size() && side.size() < 50; j++) if(l <= b[ed][j].second && b[ed][j].second <= r) side.push_back(b[ed][j].first);
                i=0,j=0;
                for(int k=0; k<50; k++){
                    if(i < scan.size() && j < side.size()){
                        if(side[j] > scan[i]) new_scan[k] = side[j++];
                        else new_scan[k] = scan[i++];
                    }
                    else if(i < scan.size()) new_scan[k] = scan[i++];
                    else if(j < side.size()) new_scan[k] = side[j++];
                }
                for(int k=0; k<50; k++) scan[k] = new_scan[k];
            }
            
            //run on all
            for(int w=st+1; w<ed; w++){
                i = 0, j = 0;
                for(int k=0; k<50; k++){
                    if(i < scan.size() && j < b[w].size()){
                        if(b[w][i].first > scan[j]) new_scan[k] = b[w][i++].first;
                        else new_scan[k] = scan[j++];
                    }
                    else if(i < scan.size()) new_scan[k] = scan[j++];
                    else if(j < b[w].size()) new_scan[k] = b[w][i++].first;
                }
                for(int k=0; k<50; k++) scan[k] = new_scan[k];
            }
            
            int ans = 0;
            for(int k=0; k<scan.size()-2; k++){
                if(scan[k] < scan[k+1] + scan[k+2] && scan[k] != 0 && scan[k+1] != 0 && scan[k+2] != 0){
                    ans = scan[k] + scan[k+1] + scan[k+2];
                    break;
                }
            }
            
            printf("%lld\n", ans);
        }
    }
}
