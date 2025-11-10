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
  int a, b;
  cin >> a >> b;
  if (15 <= a + b and 8 <= b)
    cout << 1 << endl;
  else if (10 <= a + b and 3 <= b)
    cout << 2 << endl;
  else if (3 <= a + b)
    cout << 3 << endl;
  else
    cout << 4 << endl;
}