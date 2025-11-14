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
  int n, m;
  cin >> n;
  map<string, int> s, t;
  rep(i, 0, n)
  {
    string x;
    cin >> x;
    s[x]++;
  }
  cin >> m;
  rep(i, 0, m)
  {
    string y;
    cin >> y;
    t[y]++;
  }
  int ans = 0;
  for (auto [x, c] : s)
    ans = max(ans, c - t[x]);
  cout << ans << endl;
}