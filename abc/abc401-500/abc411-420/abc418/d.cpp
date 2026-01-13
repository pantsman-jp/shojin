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
  string t;
  cin >> n >> t;
  vector<int> sum(n + 1, 0);
  rep(i, 0, n) sum[i + 1] = sum[i] + (t[i] == '0');
  ll even = 0, odd = 0;
  rep(i, 0, n + 1)
  {
    if (sum[i] % 2 == 0)
      even++;
    else
      odd++;
  }
  cout << even * (even - 1) / 2 + odd * (odd - 1) / 2 << endl;
}