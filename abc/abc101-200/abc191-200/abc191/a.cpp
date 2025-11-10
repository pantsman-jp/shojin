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
  double v, t, s, d;
  cin >> v >> t >> s >> d;
  if (t <= d / v and d / v <= s)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}