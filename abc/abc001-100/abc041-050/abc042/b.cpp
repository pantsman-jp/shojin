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
  int n, l;
  cin >> n >> l;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  sort(all(s));
  string ans = "";
  rep(i, 0, n) ans += s[i];
  cout << ans << endl;
}