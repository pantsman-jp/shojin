#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> a;

void query()
{
  int l, r, t;
  cin >> l >> r >> t;
  l--;
  rep(i, l, r) a[i] = t;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  a.resize(n, 0);
  rep(_, 0, q) query();
  rep(i, 0, n) cout << a[i] << endl;
}