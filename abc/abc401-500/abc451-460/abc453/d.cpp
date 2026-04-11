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
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define dout(x) cout << fixed << setprecision(10) << x << "\n"
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

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

const string dc = "URDL";

struct state {
  int i, j, d;
};

static int dist[1000][1000][4];
static state pre[1000][1000][4];

bool out(int i, int j, int h, int w) {
  return i < 0 or i >= h or j < 0 or j >= w;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  int si, sj, gi, gj;
  rep(i, 0, h) {
    cin >> s[i];
    rep(j, 0, w) {
      if (s[i][j] == 'S') si = i, sj = j;
      if (s[i][j] == 'G') gi = i, gj = j;
      rep(d, 0, 4) dist[i][j][d] = -1;
    }
  }
  queue<state> q;
  rep(d, 0, 4) {
    int ni = si + di[d], nj = sj + dj[d];
    if (!out(ni, nj, h, w) and s[ni][nj] != '#' and dist[ni][nj][d] == -1) {
      dist[ni][nj][d] = 1;
      pre[ni][nj][d] = {-1, -1, -1};
      q.push({ni, nj, d});
    }
  }
  int fi = -1, fj = -1, fd = -1;
  while (!q.empty()) {
    state now = q.front();
    q.pop();
    if (now.i == gi and now.j == gj) {
      fi = now.i, fj = now.j, fd = now.d;
      break;
    }
    char t = s[now.i][now.j];
    rep(dir, 0, 4) {
      if ((t == 'o' and dir != now.d) or (t == 'x' and dir == now.d)) continue;
      int ni = now.i + di[dir], nj = now.j + dj[dir];
      if (!out(ni, nj, h, w) and s[ni][nj] != '#' and dist[ni][nj][dir] == -1) {
        dist[ni][nj][dir] = dist[now.i][now.j][now.d] + 1;
        pre[ni][nj][dir] = now;
        q.push({ni, nj, dir});
      }
    }
  }
  if (fi == -1)
    yn(false);
  else {
    yn(true);
    string ans = "";
    while (fi != -1) {
      ans += dc[fd];
      state p = pre[fi][fj][fd];
      fi = p.i;
      fj = p.j;
      fd = p.d;
    }
    reverse(all(ans));
    cout << ans << '\n';
  }
  return 0;
}