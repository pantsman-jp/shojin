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
  int n, k, ans = 0;
  cin >> n >> k;
  rep(i, 1, n + 1) rep(j, 1, k + 1) ans += (100 * i + j);
  cout << ans << endl;
}