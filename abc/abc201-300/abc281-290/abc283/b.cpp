#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> a;

void solve()
{
  int n, k, x;
  cin >> n >> k;
  k--;
  if (n == 1)
  {
    cin >> x;
    a[k] = x;
  }
  else
    cout << a[k] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n;
  a.resize(n);
  rep(i, 0, n) cin >> a[i];
  cin >> q;
  rep(_, 0, q) solve();
}