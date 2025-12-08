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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  rep(r, 0, k)
  {
    vector<int> b;
    for (int i = r; i < n; i += k)
      b.push_back(a[i]);
    sort(all(b));
    for (int i = r; i < n; i += k)
      a[i] = b[i / k];
  }
  vector<int> tmp = a;
  sort(all(tmp));
  if (a == tmp)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}