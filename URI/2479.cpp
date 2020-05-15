#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    char c;
    int comp=0, ncomp=0;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin >> c >> v[i];
        if(c == '-') ncomp++;
        else comp++;
    }
    for(int i=0; i<n-1; i++){
        int menor = i;
        for(int j=i+1; j<n; j++){
            if(v[j] < v[menor]) menor = j;
        }
        swap(v[i], v[menor]);
    }
    for(int i=0; i<n; i++) cout << v[i] << endl;
    cout << "Se comportaram: " << comp << " | Nao se comportaram: " << ncomp << endl;
    return 0;
}
