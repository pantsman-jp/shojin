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
  string a;
  cin >> a;
  if (a == "a")
    cout << -1 << endl;
  else if (a.size() > 1)
    cout << a.substr(0, a.size() - 1) << endl;
  else
    cout << 'a' << endl;
}