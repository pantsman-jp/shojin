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
  int l1, l2, l3;
  cin >> l1 >> l2 >> l3;
  if (l1 == l2)
    cout << l3 << endl;
  else if (l2 == l3)
    cout << l1 << endl;
  else
    cout << l2 << endl;
}