#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
#define yn(p) cout << (p ? "Yes" : "No") << '\n';
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> pts(n, k);
  rep(_, 0, q)
  {
    int a;
    cin >> a;
    pts[a - 1]++;
  }
  rep(i, 0, n) yn(pts[i] - q > 0)
}