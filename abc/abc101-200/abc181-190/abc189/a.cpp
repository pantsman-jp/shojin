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
  string c;
  cin >> c;
  if (c[0] == c[1] and c[1] == c[2])
    cout << "Won" << endl;
  else
    cout << "Lost" << endl;
}