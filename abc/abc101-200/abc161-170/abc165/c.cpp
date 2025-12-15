#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n, m, q;
vector<int> a, b, c, d;
int ans = -1;

void dfs(vector<int> xs)
{
  if (xs.size() == n + 1)
  {
    int now = 0;
    rep(i, 0, q) if (xs[b[i]] - xs[a[i]] == c[i]) now += d[i];
    ans = max(ans, now);
    return;
  }
  xs.push_back(xs.back());
  while (xs.back() <= m)
    dfs(xs), xs.back()++;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> q;
  a = b = c = d = vector<int>(q);
  rep(i, 0, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  dfs(vector<int>(1, 1));
  cout << ans << endl;
}