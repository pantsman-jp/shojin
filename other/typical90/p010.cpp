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
  cin >> n;
  vector<int> p1(n), p2(n);
  rep(i, 0, n)
  {
    int c, p;
    cin >> c >> p;
    if (c == 1)
      p1[i] = p;
    else
      p2[i] = p;
  }
  vector<int> sum1(n + 1), sum2(n + 1);
  rep(i, 0, n)
  {
    sum1[i + 1] = sum1[i] + p1[i];
    sum2[i + 1] = sum2[i] + p2[i];
  }
  int q;
  cin >> q;
  rep(_, 0, q)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << sum1[r + 1] - sum1[l] << ' ' << sum2[r + 1] - sum2[l] << endl;
  }
}