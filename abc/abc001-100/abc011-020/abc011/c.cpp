#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "YES\n" : "NO\n");
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
  int n, ng1, ng2, ng3;
  cin >> n >> ng1 >> ng2 >> ng3;
  if (n == ng1 or n == ng2 or n == ng3)
  {
    yn(false);
    return 0;
  }
  int now = n;
  rep(i, 0, 100)
  {
    if (now >= 3 and (now - 3 != ng1 and now - 3 != ng2 and now - 3 != ng3))
      now -= 3;
    else if (now >= 2 and (now - 2 != ng1 and now - 2 != ng2 and now - 2 != ng3))
      now -= 2;
    else if (now >= 1 and (now - 1 != ng1 and now - 1 != ng2 and now - 1 != ng3))
      now -= 1;
    else
      break;
  }
  yn(now == 0);
}