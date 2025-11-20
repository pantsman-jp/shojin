#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> a, b, c;
set<int> sum;

void solve()
{
  int x;
  cin >> x;
  if (sum.count(x) != 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, l, q;
  cin >> n;
  a.resize(n);
  rep(i, 0, n) cin >> a[i];
  cin >> m;
  b.resize(m);
  rep(i, 0, m) cin >> b[i];
  cin >> l;
  c.resize(l);
  rep(i, 0, l) cin >> c[i];
  rep(i, 0, n) rep(j, 0, m) rep(k, 0, l) sum.insert(a[i] + b[j] + c[k]);
  cin >> q;
  rep(_, 0, q) solve();
}