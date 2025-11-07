#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int n, start = 0;
vector<int> a;

void solve()
{
  int t, p, x, k;
  cin >> t;
  if (t == 1)
  {
    cin >> p >> x;
    p--;
    a[(start + p) % n] = x;
  }
  if (t == 2)
  {
    cin >> p;
    p--;
    cout << a[(start + p) % n] << endl;
  }
  if (t == 3)
  {
    cin >> k;
    start = (start + k) % n;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> n >> q;
  a.resize(n);
  rep(i, 0, n) a[i] = i + 1;
  rep(qi, 0, q) solve();
}