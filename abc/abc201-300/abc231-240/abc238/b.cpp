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
  vector<int> a(n), cut;
  rep(i, 0, n) cin >> a[i];
  cut.push_back(0);
  int sum = 0;
  rep(i, 0, n) sum += a[i], cut.push_back(sum % 360);
  cut.push_back(360);
  sort(all(cut));
  int ans = 0;
  rep(i, 0, n + 1) ans = max(ans, cut[i + 1] - cut[i]);
  cout << ans << endl;
}