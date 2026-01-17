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
// const ll mod = 998244353;
// const ll mod = 1e9 + 7;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  string s, t;
  cin >> n >> m >> s >> t >> q;
  vector<bool> in_s(26, false), in_t(26, false);
  for (char c : s)
    in_s[c - 'a'] = true;
  for (char c : t)
    in_t[c - 'a'] = true;
  rep(_, 0, q)
  {
    string w;
    cin >> w;
    bool takahashi = true, aoki = true;
    for (char c : w)
    {
      if (!in_s[c - 'a'])
        takahashi = false;
      if (!in_t[c - 'a'])
        aoki = false;
    }
    if (takahashi and !aoki)
      cout << "Takahashi" << endl;
    else if (!takahashi and aoki)
      cout << "Aoki" << endl;
    else
      cout << "Unknown" << endl;
  }
}