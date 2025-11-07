#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<vector<int>> a;

void solve()
{
  int s, t;
  cin >> s >> t;
  s--, t--;
  cout << a[s][t] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  a.resize(n);
  rep(i, 0, n)
  {
    int l;
    cin >> l;
    a[i].resize(l);
    rep(j, 0, l) cin >> a[i][j];
  }
  rep(_, 0, q) solve();
}