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
  int n, q;
  cin >> n >> q;
  vector<tuple<int, int, string>> qs;
  rep(qi, 0, q)
  {
    int t, p;
    string s;
    cin >> t >> p;
    if (t == 2)
      cin >> s;
    qs.emplace_back(t, p, s);
  }
  int pc = 0;
  vector<string> ans;
  reverse(all(qs));
  for (auto [t, p, s] : qs)
  {
    if (t == 1 and pc == p)
      pc = 0;
    if (t == 2 and pc == p)
      ans.push_back(s);
    if (t == 3 and pc == 0)
      pc = p;
  }
  reverse(all(ans));
  for (string s : ans)
    cout << s;
  cout << endl;
}