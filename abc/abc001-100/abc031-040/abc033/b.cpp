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
  vector<string> s(n);
  vector<int> p(n);
  rep(i, 0, n) cin >> s[i] >> p[i];
  int half = reduce(all(p)) / 2;
  string ans = "atcoder";
  rep(i, 0, n) if (p[i] > half) ans = s[i];
  cout << ans << endl;
}