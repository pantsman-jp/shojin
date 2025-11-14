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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  int ans = 1e8;
  rep(i, 0, n)
  {
    int cnt = 0;
    while (a[i] % 2 == 0)
      a[i] /= 2, cnt++;
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}