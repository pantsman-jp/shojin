#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

bool check(map<char, int> count)
{
  for (char c : {'A', 'B', 'C'})
  {
    if (count[c] < 1)
      return false;
  }
  return true;
}

int main()
{
  int n;
  string s;
  cin >> n >> s;
  map<char, int> count = {{'A', 0}, {'B', 0}, {'C', 0}};
  rep(i, n)
  {
    ++count[s[i]];
    if (check(count))
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
