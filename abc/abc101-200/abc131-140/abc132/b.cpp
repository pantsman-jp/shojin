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
  vector<int> p(n);
  rep(i, 0, n) cin >> p[i];
  int ans = 0;
  rep(i, 1, n - 1)
  {
    int mini = min(p[i - 1], min(p[i], p[i + 1]));
    int large = max(p[i - 1], max(p[i], p[i + 1]));
    if (mini < p[i] and p[i] < large)
      ans++;
  }
  cout << ans << endl;
}