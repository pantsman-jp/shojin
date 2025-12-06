#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> H(3), W(3);
  rep(i, 0, 3) cin >> H[i];
  rep(i, 0, 3) cin >> W[i];
  int ans = 0;
  rep(a, 1, 31) rep(b, 1, 31) rep(d, 1, 31) rep(e, 1, 31)
  {
    int c = H[0] - a - b, f = H[1] - d - e;
    int g = W[0] - a - d, h = W[1] - b - e;
    int i = W[2] - c - f;
    if (min(c, min(f, min(g, min(h, i)))) > 0 and g + h + i == H[2])
      ans++;
  }
  cout << ans << endl;
}