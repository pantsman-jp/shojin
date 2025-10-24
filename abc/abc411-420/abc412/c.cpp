#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int solve()
{
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, 0, n) cin >> s[i];
  if (s.back() <= s[0] * 2)
    return 2;
  vector<int> ns;
  for (int x : s)
  {
    if (x < s[0])
      continue;
    if (x > s.back())
      continue;
    ns.push_back(x);
  }
  s = ns;
  n = s.size();
  sort(all(s));
  rep(i, 0, n - 1)
  {
    if (s[i] * 2 < s[i + 1])
      return -1;
  }
  int last = s[0], ans = 1;
  rep(i, 1, n)
  {
    if (last * 2 < s[i])
      last = s[i - 1], ans++;
  }
  return ans + 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(ti, 0, t) cout << solve() << endl;
}