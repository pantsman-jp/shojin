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
  int n;
  cin >> n;
  if (1 <= n and n <= 125)
    cout << 4 << endl;
  else if (126 <= n and n <= 211)
    cout << 6 << endl;
  else
    cout << 8 << endl;
}