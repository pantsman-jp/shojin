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
  string x;
  cin >> x;
  vector<char> digit(all(x));
  int n = digit.size();
  sort(all(digit));
  if (digit[0] == '0')
  {
    rep(i, 1, n)
    {
      if (digit[i] != '0')
      {
        char t = digit[0];
        digit[0] = digit[i], digit[i] = t;
        break;
      }
    }
  }
  rep(i, 0, n) cout << digit[i];
  cout << endl;
}