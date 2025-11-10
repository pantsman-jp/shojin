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
  string s;
  cin >> s;
  vector<int> x(4);
  rep(i, 0, 4) x[i] = s[i] - '0';
  if (set<int>(all(x)).size() == 1)
  {
    cout << "Weak" << endl;
    return 0;
  }
  bool ok = true;
  rep(i, 0, 3) if ((x[i] + 1) % 10 != x[i + 1]) ok = false;
  if (ok)
    cout << "Weak" << endl;
  else
    cout << "Strong" << endl;
}