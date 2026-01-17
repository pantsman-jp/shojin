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
// const ll mod = 1e9 + 7;

ll count(vector<int> &a, int l, int r)
{
  if (r - l <= 1)
    return 0;
  int m = (l + r) / 2;
  ll cnt = count(a, l, m) + count(a, m, r);
  vector<int> tmp;
  int i = l, j = m;
  while (i < m and j < r)
  {
    if (a[i] < a[j])
    {
      cnt += (r - j);
      tmp.push_back(a[i++]);
    }
    else
      tmp.push_back(a[j++]);
  }
  while (i < m)
    tmp.push_back(a[i++]);
  while (j < r)
    tmp.push_back(a[j++]);
  copy(all(tmp), a.begin() + l);
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  string s;
  cin >> n >> s;
  vector<int> sum(n + 1);
  rep(i, 0, n)
  {
    int v = 0;
    if (s[i] == 'A')
      v = 1;
    else if (s[i] == 'B')
      v = -1;
    sum[i + 1] = sum[i] + v;
  }
  cout << count(sum, 0, n + 1) << endl;
}