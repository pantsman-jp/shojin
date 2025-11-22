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
  cout << -1 << endl;
  rep(i, 1, n)
  {
    int ans = -1;
    rep(j, 0, i) if (a[i] < a[j]) ans = j + 1;
    cout << ans << endl;
  }
}