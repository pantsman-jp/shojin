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
  int n;
  cin >> n;
  int ans = 0;
  for (int a = 1; a * a < n; a++)
    ans++;
  for (int a = 1; a * a < n; a++)
    ans += max((n - 1) / a - a, 0) * 2;
  cout << ans << endl;
}