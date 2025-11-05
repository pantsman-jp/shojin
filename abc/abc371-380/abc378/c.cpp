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
  vector<int> a(n + 1);
  rep(i, 1, n + 1) cin >> a[i];
  map<int, int> where;
  rep(i, 1, n + 1)
  {
    int bi = where[a[i]];
    if (bi == 0)
      cout << -1 << ' ';
    else
      cout << bi << ' ';
    where[a[i]] = i;
  }
  cout << endl;
}