#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

bool isvalid(string s)
{
  int score = 0;
  for (char c : s)
  {
    if (c == '(')
      ++score;
    if (c == ')')
      --score;
    if (score < 0)
      return false;
  }
  return (score == 0);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < (1 << n); ++i)
  {
    string ans;
    for (int j = n - 1; j >= 0; --j)
    {
      if ((i & (1 << j)) == 0)
        ans += "(";
      else
        ans += ")";
    }
    if (isvalid(ans))
      cout << ans << endl;
  }
}
