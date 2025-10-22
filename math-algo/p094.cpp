#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> b(n - 1);
  rep(i, 0, n - 1) cin >> b[i];
  vector<int> a(n);
  a[0] = b[0], a[n - 1] = b[n - 2];
  rep(i, 1, n - 1) a[i] = min(b[i - 1], b[i]);
  cout << reduce(a.begin(), a.end()) << endl;
}