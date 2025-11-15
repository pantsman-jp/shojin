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
  if (a == 1)
    a = 14;
  if (b == 1)
    b = 14;
  if (a == b)
    cout << "Draw" << endl;
  else if (a < b)
    cout << "Bob" << endl;
  else
    cout << "Alice" << endl;
}