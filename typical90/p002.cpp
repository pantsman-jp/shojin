#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

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
