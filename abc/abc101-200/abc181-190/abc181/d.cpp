#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(tf) cout << (tf ? "Yes\n" : "No\n");
#define dout(x) cout << fixed << setprecision(10) << x << "\n";
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  if (n < 3) {
    sort(all(s));
    do {
      if (stoi(s) % 8 == 0) {
        yn(true);
        return 0;
      }
    } while (next_permutation(all(s)));
    yn(false);
    return 0;
  }
  vector<int> cnt(10);
  for (char c : s) cnt[c - '0']++;
  rep(i, 1, 10) {
    if (cnt[i] == 0) continue;
    cnt[i]--;
    rep(j, 1, 10) {
      if (cnt[j] == 0) continue;
      cnt[j]--;
      rep(k, 1, 10) {
        if (cnt[k] == 0) continue;
        if ((100 * i + 10 * j + k) % 8 == 0) {
          yn(true);
          return 0;
        }
      }
      cnt[j]++;
    }
    cnt[i]++;
  }
  yn(false);
  return 0;
}