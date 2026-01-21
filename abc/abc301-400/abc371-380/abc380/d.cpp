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

int search(ll l, ll r, ll k)
{
  if (l + 1 >= r)
    return 0;
  ll mid = (l + r) / 2;
  if (k < mid)
    return search(l, mid, k);
  return search(mid, r, k) + 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  cin >> s;
  for (char c : s)
  {
    if (isupper(c))
      t += tolower(c);
    else
      t += toupper(c);
  }
  int q;
  cin >> q;
  ll k, n = s.size();
  rep(_, 0, q)
  {
    cin >> k;
    k--;
    ll i = k % n;
    k /= n;
    if (search(0, INF, k) % 2 == 0)
      cout << s[i] << ' ';
    else
      cout << t[i] << ' ';
  }
  cout << endl;
}