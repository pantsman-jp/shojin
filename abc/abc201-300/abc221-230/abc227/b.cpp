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
  vector<int> s(n);
  rep(i, 0, n) cin >> s[i];
  int correct = 0;
  rep(i, 0, n)
  {
    bool ok = false;
    rep(a, 1, 1001) rep(b, 1, 1001) if (4 * a * b + 3 * a + 3 * b == s[i]) ok = true;
    if (ok)
      correct++;
  }
  cout << n - correct << endl;
}