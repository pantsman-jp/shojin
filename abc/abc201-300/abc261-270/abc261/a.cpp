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
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  if (min(r1, r2) <= max(l1, l2))
    cout << 0 << endl;
  else
    cout << min(r1, r2) - max(l1, l2) << endl;
}