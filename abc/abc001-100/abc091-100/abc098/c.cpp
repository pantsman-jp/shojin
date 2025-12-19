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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  vector<int> w(n + 1), e(n + 1);
  rep(i, 0, n)
  {
    w[i + 1] = w[i], e[i + 1] = e[i];
    if (s[i] == 'W')
      w[i + 1]++;
    else
      e[i + 1]++;
  }
  int ans = inf;
  rep(i, 0, n) chmin(ans, w[i] + e[n] - e[i + 1]);
  cout << ans << endl;
}