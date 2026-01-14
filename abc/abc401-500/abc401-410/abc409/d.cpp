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
  int l = -1;
  rep(i, 0, n - 1)
  {
    if (s[i] > s[i + 1])
    {
      l = i;
      break;
    }
  }
  if (l != -1)
  {
    int r = n - 1;
    rep(i, l + 1, n - 1)
    {
      if (s[l] < s[i + 1])
      {
        r = i;
        break;
      }
    }
    rotate(s.begin() + l, s.begin() + (l + 1), s.begin() + (r + 1));
  }
  cout << s << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) solve();
}