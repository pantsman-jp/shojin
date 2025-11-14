#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> g(n);
  rep(_, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a]++, g[b]++;
  }
  rep(i, 0, n) cout << g[i] << endl;
}