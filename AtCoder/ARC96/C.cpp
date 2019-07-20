#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if(2LL*c <= a+b){
    	ans += 2LL*c*min(x,y);
    	int tira = min(x,y);
    	x -= tira;
    	y -= tira;
    }
    else {
    	ans += x*a + y*b;
    	x = 0;
    	y = 0;
    }
    if(x == 0){
    	swap(x,y);
    	swap(a,b);
    }
    if(2*c <= a){
    	ans += 2*c*x;
    }
    else {
    	ans += x*a;
    }
    cout << ans << endl;
}
