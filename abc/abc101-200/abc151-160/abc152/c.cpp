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
  int mini = n + 1, ans = 0;
  rep(i, 0, n)
  {
    int p;
    cin >> p;
    mini = min(mini, p);
    if (mini == p)
      ans++;
  }
  cout << ans << endl;
}