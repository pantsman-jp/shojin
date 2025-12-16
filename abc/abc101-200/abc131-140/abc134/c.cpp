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
  vector tmp = a;
  sort(all(tmp));
  int large1 = tmp[n - 1], large2 = tmp[n - 2];
  rep(i, 0, n)
  {
    if (a[i] == large1)
      cout << large2 << endl;
    else
      cout << large1 << endl;
  }
}