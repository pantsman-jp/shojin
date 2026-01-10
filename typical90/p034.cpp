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
// const ll mod =;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  int l = 0, r = 0, ans = 0, kind = 0;
  map<int, int> cnt;
  while (r < n)
  {
    if (cnt[a[r]] == 0)
      kind++;
    cnt[a[r]]++, r++;
    while (kind > k)
    {
      cnt[a[l]]--;
      if (cnt[a[l]] == 0)
        kind--;
      l++;
    }
    chmax(ans, r - l);
  }
  cout << ans << endl;
}