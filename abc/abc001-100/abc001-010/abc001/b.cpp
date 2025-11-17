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
  int m;
  cin >> m;
  if (m < 100)
    cout << "00" << endl;
  else if (m < 1000)
    cout << 0 << m / 100 << endl;
  else if (m <= 5000)
    cout << m / 100 << endl;
  else if (m <= 30000)
    cout << m / 1000 + 50 << endl;
  else if (m <= 70000)
    cout << (m / 1000 - 30) / 5 + 80 << endl;
  else
    cout << "89" << endl;
}