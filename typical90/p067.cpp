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

ll str8_to_ll10(string n)
{
  ll ans = 0;
  rep(i, 0, n.size()) ans = ans * 8 + int(n[i] - '0');
  return ans;
}

string ll10_to_str9(ll n)
{
  if (n == 0)
    return "0";
  string ans;
  while (n > 0)
    ans = char(n % 9 + '0') + ans, n /= 9;
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string n;
  int k;
  cin >> n >> k;
  rep(_, 0, k)
  {
    n = ll10_to_str9(str8_to_ll10(n));
    rep(i, 0, n.size()) if (n[i] == '8') n[i] = '5';
  }
  cout << n << endl;
}