#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
using ld = long double;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ld ans = 0;
  rep(_, 0, n)
  {
    ld x;
    string u;
    cin >> x >> u;
    if (u == "JPY")
      ans += x;
    else
      ans += x * 380000.0;
  }
  cout << fixed << setprecision(10) << ans << endl;
}