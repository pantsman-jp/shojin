#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod = 998244353;
// const ll mod = 1000000007;

int n, ans = 0;
vector<int> a;

void solve(int start)
{
  vector<int> p;
  for (int i = start; i + 1 < n; i += 2)
  {
    if (a[i] == a[i + 1])
      p.push_back(a[i]);
    else
      p.push_back(-1);
  }
  vector<int> cnt(n + 1);
  int l = 0;
  rep(r, 0, p.size())
  {
    if (p[r] == -1)
    {
      while (l <= r)
      {
        if (p[l] != -1)
          cnt[p[l]]--;
        l++;
      }
      continue;
    }
    while (cnt[p[r]] > 0)
    {
      cnt[p[l]]--;
      l++;
    }
    cnt[p[r]]++;
    chmax(ans, (r - l + 1) * 2);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  a.resize(n);
  rep(i, 0, n) cin >> a[i];
  solve(0);
  solve(1);
  cout << ans << endl;
}