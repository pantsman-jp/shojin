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
  char x, y;
  cin >> x >> y;
  if (x < y)
    cout << '<' << endl;
  else if (x == y)
    cout << '=' << endl;
  else
    cout << '>' << endl;
}