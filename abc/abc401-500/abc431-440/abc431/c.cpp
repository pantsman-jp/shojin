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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> h(n), b(m);
  rep(i, 0, n) cin >> h[i];
  rep(i, 0, m) cin >> b[i];
  sort(all(h)), sort(all(b));
  int i = 0, j = 0, ans = 0;
  while (i < n and j < m)
  {
    if (h[i] <= b[j])
      ans++, i++, j++;
    else
      j++;
  }
  if (k <= ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}