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
using P = pair<ll, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod =;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  priority_queue<P, vector<P>, greater<P>> pq;
  ll empty = k, ans = 0;
  rep(i, 0, n)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    while (pq.size() and pq.top().first < a)
    {
      empty += pq.top().second;
      pq.pop();
    }
    ans = max<ll>(ans, a);
    while (empty < c)
    {
      ans = pq.top().first;
      empty += pq.top().second;
      pq.pop();
    }
    empty -= c;
    pq.emplace(ans + b, c);
    cout << ans << endl;
  }
}