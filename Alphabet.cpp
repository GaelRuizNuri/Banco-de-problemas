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


const string y = ".abcdefghijklmnopqrstuvwxyz";


void solve() {
    string x; cin >> x; x="+"+x;
    vvi LCS(x.size(),vi(y.size(),0));
    for (int i = 0; i < x.size(); ++i)
        {
            for (int j = 0; j < y.size(); ++j)
            {
                if( i>0 && j>0 && x[i]==y[j]) LCS[i][j]= 1+LCS[i-1][j-1];
                else if(i>0 && j>0 ) LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    cout << 26 - LCS[x.size()-1][y.size()-1] << '\n';
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