#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, a, b, p, q, r, s;
  cin >> n >> a >> b >> p >> q >> r >> s;
  string t = "";
  vector<string> ans;
  rep(i, 0, s - r + 1) t += ".";
  rep(i, 0, q - p + 1) ans.push_back(t);
  rep(i, max(p - a, r - b), min(q - a, s - b) + 1) ans[a + i - p][b + i - r] = '#';
  rep(i, max(p - a, b - s), min(q - a, b - r) + 1) ans[a + i - p][b - i - r] = '#';
  rep(i, 0, q - p + 1) cout << ans[i] << endl;
}