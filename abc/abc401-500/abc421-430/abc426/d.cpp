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

void solve()
{
  int n;
  string s;
  cin >> n >> s;
  vector<int> cnt(2);
  vector<pair<char, int>> d(1, {s[0], 0});
  for (char c : s)
  {
    cnt[c - '0']++;
    if (d.back().first == c)
      d.back().second++;
    else
      d.emplace_back(c, 1);
  }
  int ans = n * 2;
  for (auto [c, num] : d)
  {
    int i = c - '0';
    vector<int> ncnt = cnt;
    ncnt[i] -= num;
    chmin(ans, ncnt[i] * 2 + ncnt[i ^ 1]);
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) solve();
}