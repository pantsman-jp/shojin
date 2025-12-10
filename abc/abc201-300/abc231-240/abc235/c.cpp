#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

map<int, vector<int>> inds;

void solve()
{
  int x, k;
  cin >> x >> k;
  if (inds[x].size() < k)
    cout << -1 << endl;
  else
    cout << inds[x][k - 1] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    inds[a].push_back(i + 1);
  }
  rep(_, 0, q) solve();
}