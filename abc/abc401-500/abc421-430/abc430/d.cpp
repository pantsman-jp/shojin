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
  int n;
  cin >> n;
  ll ans = 0;
  vector<int> dist(n + 2);
  set<pair<int, int>> st;
  st.emplace(0, 0);
  st.emplace(2e9, n + 1);
  dist[0] = 2e9;
  ans += 2e9;
  auto update = [&](int i, int d)
  {
    ans -= dist[i];
    dist[i] = min(dist[i], d);
    ans += dist[i];
  };
  rep(i, 1, n + 1)
  {
    int x;
    cin >> x;
    auto it = st.emplace(x, i).first;
    int dprev = x - prev(it)->first;
    int dnext = next(it)->first - x;
    dist[i] = min(dprev, dnext);
    ans += dist[i];
    int pi = prev(it)->second;
    int ni = next(it)->second;
    update(pi, dprev);
    update(ni, dnext);
    cout << ans << endl;
  }
}