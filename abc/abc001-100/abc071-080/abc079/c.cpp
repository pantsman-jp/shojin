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
  string abcd;
  cin >> abcd;
  int a = abcd[0] - '0', b = abcd[1] - '0', c = abcd[2] - '0', d = abcd[3] - '0';
  string op = "";
  if (a + b + c + d == 7)
    op = "+++";
  else if (a + b + c - d == 7)
    op = "++-";
  else if (a + b - c + d == 7)
    op = "+-+";
  else if (a + b - c - d == 7)
    op = "+--";
  else if (a - b + c + d == 7)
    op = "-++";
  else if (a - b + c - d == 7)
    op = "-+-";
  else if (a - b - c + d == 7)
    op = "--+";
  else if (a - b - c - d == 7)
    op = "---";
  cout << a << op[0] << b << op[1] << c << op[2] << d << "=7" << endl;
}