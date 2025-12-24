#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  rep(_, 0, q)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    a[l]++, a[r + 1]--;
  }
  rep(i, 0, n - 1) a[i + 1] += a[i];
  rep(i, 0, n)
  {
    if (a[i] % 2 == 0)
      cout << 0;
    else
      cout << 1;
  }
  cout << endl;
}