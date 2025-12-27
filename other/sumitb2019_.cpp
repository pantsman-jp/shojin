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
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, 0, 1000)
  {
    vector c = {i / 100, (i / 10) % 10, i % 10};
    int cnt = 0;
    rep(j, 0, n)
    {
      if (s[j] == (c[cnt] + '0'))
        cnt++;
      if (cnt == 3)
      {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}