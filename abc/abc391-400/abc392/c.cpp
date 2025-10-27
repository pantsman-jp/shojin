#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n), q(n), pos(n + 1);
  rep(i, 0, n) cin >> p[i];
  rep(i, 0, n)
  {
    cin >> q[i];
    pos[q[i]] = i;
  }
  rep(i, 1, n + 1) cout << q[p[pos[i]] - 1] << ' ';
  cout << endl;
}
