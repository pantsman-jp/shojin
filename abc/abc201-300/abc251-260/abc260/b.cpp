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
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  vector<int> s(n);
  iota(all(s), 0);
  stable_sort(all(s), [&](int i, int j)
              { return a[i] > a[j]; });
  sort(s.begin() + x, s.end());
  stable_sort(s.begin() + x, s.end(), [&](int i, int j)
              { return b[i] > b[j]; });
  sort(s.begin() + x + y, s.end());
  stable_sort(s.begin() + x + y, s.end(), [&](int i, int j)
              { return a[i] + b[i] > a[j] + b[j]; });
  sort(s.begin(), s.begin() + x + y + z);
  rep(i, 0, x + y + z) cout << s[i] + 1 << endl;
}
