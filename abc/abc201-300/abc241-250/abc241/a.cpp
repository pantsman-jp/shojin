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
  vector<int> a(9);
  rep(i, 0, 10) cin >> a[i];
  int k = 0;
  rep(_, 0, 3) k = a[k];
  cout << k << endl;
}