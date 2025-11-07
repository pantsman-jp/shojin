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
  int n, t;
  cin >> n >> t;
  vector<int> c(n), r(n);
  rep(i, 0, n) cin >> c[i];
  rep(i, 0, n) cin >> r[i];
  int color = t;
  bool exist = false;
  rep(i, 0, n) if (c[i] == t) exist = true;
  if (!exist)
    color = c[0];
  int ans = -1, best = -1;
  rep(i, 0, n) if (c[i] == color and r[i] > best) best = r[i], ans = i + 1;
  cout << ans << endl;
}