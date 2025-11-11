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
  int ans = 0, gcdd = 0;
  rep(k, 2, *max_element(all(a)) + 1)
  {
    int cnt = 0;
    rep(i, 0, n) if (a[i] % k == 0) cnt++;
    if (cnt >= gcdd)
      ans = k, gcdd = cnt;
  }
  cout << ans << endl;
}