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
  int n, x;
  cin >> n >> x;
  x--;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<bool> know(n);
  rep(i, 0, n)
  {
    if (!know[x])
      know[x] = true, x = a[x] - 1;
    else
      break;
  }
  int ans = 0;
  for (bool b : know)
    if (b)
      ans++;
  cout << ans << endl;
}