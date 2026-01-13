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
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  vector<int> swp(n + 1);
  rep(_, 0, m)
  {
    int l, r;
    cin >> l >> r;
    l--;
    swp[l]++, swp[r]--;
  }
  rep(i, 0, n) swp[i + 1] += swp[i];
  rep(i, 0, n)
  {
    if (swp[i] % 2 == 0)
      cout << s[i];
    else
      cout << t[i];
  }
  cout << endl;
}