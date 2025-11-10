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
  string s;
  cin >> s;
  string x = s.substr(0, s.find('.'));
  int y = s.back() - '0';
  if (0 <= y and y < 3)
    cout << x + '-' << endl;
  else if (3 <= y and y < 7)
    cout << x << endl;
  else
    cout << x + '+' << endl;
}