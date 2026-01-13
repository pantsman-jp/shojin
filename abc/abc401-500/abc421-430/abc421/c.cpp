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
  vector<int> a, b;
  rep(i, 0, 2 * n)
  {
    if (s[i] == 'A')
      a.push_back(i);
    else
      b.push_back(i);
  }
  ll x = 0, y = 0;
  rep(i, 0, n)
  {
    x += abs(a[i] - (2 * i)) + abs(b[i] - (2 * i + 1));
    y += abs(b[i] - (2 * i)) + abs(a[i] - (2 * i + 1));
  }
  cout << min(x, y) / 2 << endl;
}