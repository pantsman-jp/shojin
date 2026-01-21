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
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ld s, t, ans = INF, base = 0;
  cin >> n >> s >> t;
  vector<ld> A(n), B(n), C(n), D(n);
  rep(i, 0, n)
  {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    base += sqrt((A[i] - C[i]) * (A[i] - C[i]) + (B[i] - D[i]) * (B[i] - D[i])) / t;
  }
  vector<int> order(n);
  rep(i, 0, n) order[i] = i;
  do
  {
    rep(bit, 0, 1 << n)
    {
      ld dis = base;
      vector<ld> sx(n), sy(n), tx(n), ty(n);
      rep(i, 0, n)
      {
        int id = order[i];
        if ((bit & (1 << i)) != 0)
          sx[i] = A[id], sy[i] = B[id], tx[i] = C[id], ty[i] = D[id];
        else
          sx[i] = C[id], sy[i] = D[id], tx[i] = A[id], ty[i] = B[id];
      }
      dis += sqrt(sx[0] * sx[0] + sy[0] * sy[0]) / s;
      rep(i, 0, n - 1)
      {
        ld dx = abs(sx[i + 1] - tx[i]), dy = abs(sy[i + 1] - ty[i]);
        dis += sqrt(dx * dx + dy * dy) / s;
      }
      chmin(ans, dis);
    }
  } while (next_permutation(all(order)));
  dout(ans);
}