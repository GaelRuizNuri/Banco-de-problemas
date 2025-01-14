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
#define PUTALL(v) for(auto& x: (v)) cin >> x

#define forn(n) for(int i = 0; i < n; ++i)
#define forr(i,a, b) for(int i = a; i < b; ++i)
#define ford(n) for(int i = n-1; i >=0; --i)
#define SET(a,b) ((a) | 1LL<<(b))
#define TEST(a,b) ((a) & 1LL<<(b))
#define CLEAR(a,b) ((a) & ~(1LL<<(b)))
#define FLIP(a,b) ((a) ^ 1LL<<(b))
#define MSB(a) ((a) & -(a))

class UnionFind {                               
private:
  vi p, rank, setSize;                          
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 
    int x = findSet(i), y = findSet(j);         
    if (rank[x] > rank[y]) swap(x, y);          
    p[x] = y;                                    
    if (rank[x] == rank[y]) ++rank[y];          
  }
};

unordered_map<string, int> ids;
unordered_map<int, vi> groups;
vi color;
vvi graph;

bool isBicolorable(int s) {
  queue<ii> q; q.push({s, 0});
  while (!q.empty()) {
    auto [node, c] = q.front(); q.pop();
    color[node] = c;
    for (auto vec : graph[node]) { 
      if (color[vec] == c) return false;
      if (color[vec] < 0) q.push({vec, (c + 1) % 2}); 
    }
  }
  return true;
}

void solve() {
  int n, m; cin >> n;
  vector<string> productos;
  UnionFind uf(n);
  forr(i, 0, n) { //O(n)
    string p; cin >> p;
    productos.emplace_back(p);
    ids[p] = i; 
  }
  color.resize(n, -1);
  graph.resize(n);
  cin >> m;
  forr(i, 0, m) { //O(m)
    string p, pp; cin >> p >> pp;
    int a = ids[p], b = ids[pp];
    uf.unionSet(a, b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  forn(n) groups[uf.findSet(i)].push_back(i); //O(n*a(n)) a(n):= función inversa de Ackerman
  bool bc = true;
  for (auto& [root, group] : groups) bc &= isBicolorable(group[0]);  //O(n+m)
  if (!bc) {
    cout << "impossible\n";
    return;
  }
  string w = "", j = "";
  forr(i, 0, n) {  //O(n)
    if (color[i]) w += productos[i] + " ";
    else j += productos[i] + " ";
  } 
  w += '\n'; j += '\n';
  cout << w << j;
}

int main() {
  optimizar_io;
  int t = 1; 
  //cin >> t;
  while (t--) solve(); //O(2n+2m +n*a(n)) = O(n+m) / a(n) es practicamete constante
  return 0;
}
