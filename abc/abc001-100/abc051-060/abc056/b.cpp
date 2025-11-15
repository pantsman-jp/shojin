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
  int w, a, b;
  cin >> w >> a >> b;
  if (a > b)
    swap(a, b);
  if (b <= a + w)
    cout << 0 << endl;
  else
    cout << b - (a + w) << endl;
}