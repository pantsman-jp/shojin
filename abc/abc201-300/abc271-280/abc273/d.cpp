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
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;#include <bits/stdc++.h>

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w, si, sj, n;
  cin >> h >> w >> si >> sj >> n;
  map<int, vector<int>> mpl, mpr, mpu, mpd;
  rep(_, 0, n) {
    int i, j;
    cin >> i >> j;
    mpr[i].push_back(j);
    mpl[i].push_back(-j);
    mpd[j].push_back(i);
    mpu[j].push_back(-i);
  }
  auto init = [&](map<int, vector<int>>& mp, int r) {
    for (auto& p : mp) {
      sort(all(p.second));
      p.second.push_back(r);
    }
  };
  init(mpr, w + 1);
  init(mpl, 0);
  init(mpd, h + 1);
  init(mpu, 0);
  auto f = [&](map<int, vector<int>>& mp, int i, int j, int l, int r) {
    auto it = mp.find(i);
    if (it == mp.end()) return min(j + l, r - 1);
    auto& is = it->second;
    int wj = *lower_bound(all(is), j);
    return min(j + l, wj - 1);
  };
  int q;
  cin >> q;
  rep(_, 0, q) {
    char d;
    int l;
    cin >> d >> l;
    if (d == 'R') sj = f(mpr, si, sj, l, w + 1);
    if (d == 'L') sj = -f(mpl, si, -sj, l, 0);
    if (d == 'D') si = f(mpd, sj, si, l, h + 1);
    if (d == 'U') si = -f(mpu, sj, -si, l, 0);
    cout << si << " " << sj << endl;
  }
  return 0;
}