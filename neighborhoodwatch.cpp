#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull; 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int, int> tupla; 
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vii> vvii;
const int INF=1e9;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

#define ALL(v) (v).begin(), (v).end()
#define forn(n) for(int i = 0; i < n; ++i)//SOLO USAR SI ES UNICA INTRUCCION
#define forr(i, n) for(int i = 0; i < n; ++i)//SOLO USAR SI ES UNICA INTRUCCION
#define SET(a,b) ((a) | 1<<(b))



void solve() {
    ll n, k, res = 0L;
    cin >> n >> k;
    vi watch(k);
    for (int i = 0; i < k; ++i) {
        cin >> watch[i];
    }

    int idx = 0;  
    for (int i = 1; i <= n; ++i) {
        if (idx >= k) break;  
        if (watch[idx] < i) idx++; 
        if (idx < k) res += (n - watch[idx] + 1);
    }
    cout << res << '\n';
}

int main() {
    optimizar_io
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}