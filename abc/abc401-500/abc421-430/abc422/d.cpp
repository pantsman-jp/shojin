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
  vector<int> ans = {k};
  rep(i, 0, n)
  {
    vector<int> nxt;
    for (int x : ans)
    {
      nxt.push_back(x / 2);
      nxt.push_back(x - x / 2);
    }
    ans = nxt;
  }
  int u = 1;
  if (k % (1 << n) == 0)
    u = 0;
  cout << u << endl;
  for (int x : ans)
    cout << x << ' ';
  cout << endl;
}