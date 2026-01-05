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
  ll n;
  cin >> n;
  vector<ll> cnt(n + 1);
  for (ll x = 1; x * x <= n; x++)
    for (ll y = x + 1; x * x + y * y <= n; y++)
      cnt[x * x + y * y]++;
  vector<ll> ans;
  rep(i, 1, n + 1) if (cnt[i] == 1) ans.push_back(i);
  cout << ans.size() << endl;
  for (int a : ans)
    cout << a << ' ';
  cout << endl;
}