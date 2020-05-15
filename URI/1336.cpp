#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define PI acos(-1)
#define ff first
#define ss second

using namespace std;

struct point{
	int x,y,color,val;
	point() {}
	point(int x, int y, int c, int v) : x(x), y(y), color(c), val(v) {}
};


int cross(pair<int,int> a, pair<int,int> b){
	return a.ff*b.ss - a.ss*b.ff;
}

inline pair<int,int> make_vector(point a, point b){
	return pair<int,int>(b.x - a.x, b.y - a.y);
}

int magni(pair<int,int> a){
	return a.ff*a.ff + a.ss*a.ss;
}

point pivot;

bool cmp(const point & a, const point & b){
	if(a.y == pivot.y && b.y == pivot.y){
		if(b.x > pivot.x && a.x < pivot.x) return false;
		else if(b.x < pivot.x && a.x > pivot.x) return true;
		else return magni(make_vector(pivot, a)) < magni(make_vector(pivot, b));
	}
	else if(a.y == pivot.y){
		if(a.x > pivot.x) return true;
		else if(a.x < pivot.x && b.y > a.y) return false;
		else return true;
	}
	else if(b.y == pivot.y){
		if(b.x > pivot.x) return false;
		else if(b.x < pivot.x && a.y > b.y) return true;
		else return false;
	}
	else if(a.y < pivot.y && b.y < pivot.y || a.y > pivot.y && b.y > pivot.y){
		int c = cross(make_vector(pivot, a), make_vector(pivot, b));
		return c > 0 || (c == 0 && magni(make_vector(pivot, a)) < magni(make_vector(pivot, b)));
	}
	else return a.y > b.y;
}

bool xcomp(const point & a, const point & b){
	return a.x < b.x;
}

bool ycomp(const point & a, const point & b){
	return a.y < b.y;
}


bool color[2123];
point v[2123];	

int32_t main(){
	
	int n,m;
	while(scanf("%lld%lld", &n, &m), n != 0 && m != 0){
		int tot[2];
		tot[0] = tot[1] = 0;
		for(int i=0; i<n; ++i){
			int x,y, val;
			scanf("%lld%lld%lld", &x, &y, &val);
			v[i] = point(x,y,0,val);
			tot[0]+=val;
		}
		for(int i=n; i<n+m; ++i){
			int x,y, val;
			scanf("%lld%lld%lld", &x, &y, &val);
			v[i] = point(x,y,1,val);
			tot[1]+=val;
		}
		
		//base case(not covered)
		if(n + m <= 3){
			printf("0\n");
			continue;
		}
		
		int x = v[0].x;
		int y = v[0].y;
		for(int i = 0; i<n+m; i++){
			if(v[i].x != x) x = (int)(1e9)+1;
			if(v[i].y != y) y = (int)(1e9)+1;
		}
		
		int ans = 99999999;
		
		if(x == v[0].x){
			//linear solve for x
			int curr[2];
			curr[0] = curr[1] = 0;
			sort(v, v+n+m, ycomp);
			for(int i=0; i<n+m; i++){
				curr[v[i].color] += v[i].val;
				int menor = min(curr[0] + (tot[1] - curr[1]), curr[1] + (tot[0]-curr[0]));
				ans = min(ans, menor);
			}
			
			printf("%lld\n", ans);
			continue;
		}
		
		if(y == v[0].y){
			//linear solve for y
			int curr[2];
			curr[0] = curr[1] = 0;
			sort(v, v+n+m, xcomp);
			for(int i=0; i<n+m; i++){
				curr[v[i].color] += v[i].val;
				int menor = min(curr[0] + (tot[1] - curr[1]), curr[1] + (tot[0]-curr[0]));
				ans = min(ans, menor);
			}
			
			printf("%lld\n", ans);
			continue;
		}
		
		
		for(int i=0; i<n+m; i++){
			//take pivot
			pivot = v[i];
			
			//sort points
			vector<point> p;
			for(int j=0; j<n+m; j++){
				if(j == i) continue;
				p.push_back(v[j]);
			}
			sort(p.begin(), p.end(), cmp);
			
			//radial sweep
			
			queue<point> inside;
			int curr[2];
			curr[0] = curr[1] = 0;
			curr[pivot.color] += pivot.val;

			for(int j=0; j<p.size(); j++){
				while(!inside.empty() && cross(make_vector(pivot, inside.front()), make_vector(p[j], pivot)) > 0){
					curr[inside.front().color]-=inside.front().val;
					inside.pop();
				}
				inside.push(p[j]);
				curr[p[j].color] += p[j].val;
			}
			
			for(int j=0; j<p.size(); j++){
				if(inside.front().x == p[j].x && inside.front().y == p[j].y){
					curr[inside.front().color] -= inside.front().val;
					inside.pop();
				}
				while(!inside.empty() && cross(make_vector(pivot, inside.front()), make_vector(p[j], pivot)) > 0){
					curr[inside.front().color]-=inside.front().val;
					inside.pop();
				}
				inside.push(p[j]);
				curr[p[j].color] += p[j].val;
				int menor = min(curr[0] + (tot[1] - curr[1]), curr[1] + (tot[0]-curr[0]));
				ans = min(ans, menor);
			}
			
			//cout << endl;
		}
		printf("%lld\n", ans);
	}
}
