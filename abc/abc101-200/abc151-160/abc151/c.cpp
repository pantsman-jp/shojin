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
  int n, m;
  cin >> n >> m;
  int ac = 0, pena = 0;
  map<int, int> wa;
  map<int, bool> isac;
  rep(_, 0, m)
  {
    int p;
    string s;
    cin >> p >> s;
    if (s == "AC")
    {
      if (!isac[p])
        ac++, pena += wa[p], isac[p] = true;
    }
    else
      wa[p]++;
  }
  cout << ac << ' ' << pena << endl;
}
