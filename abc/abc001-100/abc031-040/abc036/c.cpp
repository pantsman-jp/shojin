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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector b = a;
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  for (auto m : a)
    cout << lower_bound(all(b), m) - b.begin() << endl;
}