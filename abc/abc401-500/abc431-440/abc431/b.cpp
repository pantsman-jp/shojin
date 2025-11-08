#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int x;
vector<int> w;
vector<bool> equipped;

void solve()
{
  int p;
  cin >> p;
  p--;
  if (equipped[p])
    x -= w[p], equipped[p] = false;
  else
    x += w[p], equipped[p] = true;
  cout << x << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> x >> n;
  w.resize(n), equipped.resize(n);
  rep(i, 0, n) cin >> w[i];
  cin >> q;
  rep(_, 0, q) solve();
}