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

istream& operator>>(std::istream& in, std::pair<int, int>& p) {
    in >> p.first >> p.second;
    return in;
}

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(v) (v).begin(),(v).end()
#define PUTALL(v) for(auto& x: (v)) cin >> x

#define forn(n) for(int i = 0; i < n; ++i)
#define forr(i,a, b) for(int i = a; i < b; ++i)
#define ford(n) for(int i = n-1; i >=0; --i)
#define SET(a,b) ((a) | 1LL<<(b))
#define TEST(a,b) ((a) & 1LL<<(b))
#define CLEAR(a,b) ((a) & ~(1LL<<(b)))
#define FLIP(a,b) ((a) ^ 1LL<<(b))
#define MSB(a) ((a) & -(a))


void solve() {
  int n; cin >> n;
  vii temp(n); PUTALL(temp);
  sort(ALL(temp),[](const ii& a, const ii& b ){return  a.second == b.second ? a.first<b.first:a.second<b.second;});
  int rooms=0; int lasT=-1;
  forr(i,0,n){ 
    if(temp[i].first<=lasT) continue;
    rooms++; lasT=temp[i].second;

  }
  cout << rooms << '\n';
}

int main() {
  optimizar_io;
  int t = 1; 
  //cin >> t;
  while (t--) solve(); //O(2n+2m +n*a(n)) = O(n+m) / a(n) es practicamete constante
  return 0;
}
