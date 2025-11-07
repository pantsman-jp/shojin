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
  vector<int> s(n + 1), a(n + 1);
  rep(i, 1, n + 1) cin >> s[i];
  rep(i, 0, n) a[i + 1] = s[i + 1] - s[i];
  rep(i, 1, n + 1) cout << a[i] << ' ';
  cout << endl;
}
