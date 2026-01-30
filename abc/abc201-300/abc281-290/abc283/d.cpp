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
// using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  vector<bool> isin(26);
  vector<char> st;
  for (auto c : s) {
    if (c == ')') {
      while (!st.empty() and st.back() != '(') {
        isin[st.back() - 'a'] = false;
        st.pop_back();
      }
      st.pop_back();
    } else if (c == '(') {
      st.push_back(c);
    } else {
      if (isin[c - 'a']) {
        yn(false);
        return 0;
      }
      st.push_back(c);
      isin[c - 'a'] = true;
    }
  }
  yn(true);
  return 0;
}