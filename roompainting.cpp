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

#define ALL(v) (v).begin(),(v).end()
#define forn(n) for(int i = 0; i < n; ++i)//SOLO USAR SI ES UNICA INTRUCCION
#define forr(i, n) for(int i = 0; i < n; ++i)//SOLO USAR SI ES UNICA INTRUCCION
#define SET(a,b) ((a) | 1<<(b))



int bb(const vi& vec, int a){ //O(log(n))
   return vec[ lower_bound(ALL(vec),a) - vec.begin()];
}

void solve() {
    int n,m; cin >> n >> m;
    vi pinturas(n);
    forn(n) cin >> pinturas[i];

    sort(ALL(pinturas)); // O(nlog(n))
    
    ll res=0LL;
    for (int i = 0; i < m; ++i)
    {
        int h; cin >> h;
        res += bb(pinturas,h)-h;
    } cout << res << '\n';

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