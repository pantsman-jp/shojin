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
  string abc;
  cin >> abc;
  int a, b, c;
  a = (int)(abc[0] - '0');
  b = (int)(abc[1] - '0');
  c = (int)(abc[2] - '0');
  cout << 111 * (a + b + c) << endl;
}