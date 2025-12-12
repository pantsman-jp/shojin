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
  vector<int> l(n), r(n);
  rep(i, 0, n)
  {
    int t;
    cin >> t >> l[i] >> r[i];
    l[i] *= 2, r[i] *= 2;
    if (t == 2)
      r[i]--;
    else if (t == 3)
      l[i]++;
    else if (t == 4)
      l[i]++, r[i]--;
  }
  int ans = 0;
  rep(i, 0, n) rep(j, 0, i) if (r[i] >= l[j] and r[j] >= l[i]) ans++;
  cout << ans << endl;
}