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
  string s;
  cin >> n >> k >> s;
  vector<int> a;
  rep(i, 0, n) a.push_back(((int)(s[i] - 'a')));
  sort(all(a));
  int ans = 0;
  bool ok, flag;
  while (true)
  {
    ok = true;
    rep(i, 0, n - k + 1)
    {
      flag = true;
      rep(j, 0, k) if (a[i + j] != a[i + k - 1 - j]) flag = false;
      if (flag)
        ok = false;
    }
    if (ok)
      ans++;
    if (!next_permutation(all(a)))
    {
      cout << ans << endl;
      return 0;
    }
  }
}
