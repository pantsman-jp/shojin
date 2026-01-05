#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod =;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  map<ll, vector<int>> pos7, pos5, pos3;
  rep(i, 0, n)
  {
    if (a[i] % 7 == 0)
      pos7[a[i] / 7].push_back(i);
    if (a[i] % 5 == 0)
      pos5[a[i] / 5].push_back(i);
    if (a[i] % 3 == 0)
      pos3[a[i] / 3].push_back(i);
  }
  ll ans = 0;
  for (auto [x, _] : pos5)
  {
    if (pos7.count(x) == 0 or pos3.count(x) == 0)
      continue;
    for (int i : pos5[x])
    {
      ans += (pos7[x].end() - upper_bound(all(pos7[x]), i)) * (pos3[x].end() - upper_bound(all(pos3[x]), i));
      ans += (lower_bound(all(pos7[x]), i) - pos7[x].begin()) * (lower_bound(all(pos3[x]), i) - pos3[x].begin());
    }
  }
  cout << ans << endl;
}