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
  string a, b, c;
  cin >> a >> b >> c;
  if (a.back() == b[0] and b.back() == c[0])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}