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
  vector<int> p(n + 1);
  rep(i, 2, n + 1) cin >> p[i];
  int now = n, ans = 0;
  while (now != 1)
    ans++, now = p[now];
  cout << ans << endl;
}