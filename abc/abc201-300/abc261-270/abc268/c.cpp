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
  vector<int> p(n), cnt(n);
  rep(i, 0, n) cin >> p[i];
  rep(i, 0, n) rep(k, 0, 3) cnt[((p[i] - i - 1 + n) % n + k) % n]++;
  cout << *max_element(all(cnt)) << endl;
}