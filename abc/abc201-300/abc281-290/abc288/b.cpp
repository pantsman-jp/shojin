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
  int n, k;
  cin >> n >> k;
  vector<string> s(n), ans;
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, k) ans.push_back(s[i]);
  sort(all(ans));
  rep(i, 0, k) cout << ans[i] << endl;
}