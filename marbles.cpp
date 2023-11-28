#include <bits/stdc++.h>
using namespace std;

#define task "marbles"

const int N = 5e4+1;

long long n, m, u, v, r;
long long b[N], c[N];
long long ans = 0;

void input(){
    cin >> n >> m >> u >> v >> r;
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < m; i++){
        cin >> c[i];
    }
}

void work(){
    sort(b, b + n);
    sort(c, c + m);
    for(int i = 0; i < m; i++){
        if(r*r >= (c[i] - v)*(c[i] - v)){
            long double temp = sqrt(r*r - (c[i] - v) * (c[i] - v));
            ans += upper_bound(b, b + n, u + temp) - lower_bound(b, b + n, u - temp);
        }
    }
    cout << abs((m*n - ans) - ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    input();
    work();
}