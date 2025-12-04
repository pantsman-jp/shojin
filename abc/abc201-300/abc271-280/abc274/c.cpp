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
  vector<int> ans(2 * n + 2);
  rep(i, 1, n + 1)
  {
    int a;
    cin >> a;
    ans[2 * i] += ans[a] + 1, ans[2 * i + 1] += ans[a] + 1;
  }
  rep(i, 1, 2 * n + 2) cout << ans[i] << endl;
}