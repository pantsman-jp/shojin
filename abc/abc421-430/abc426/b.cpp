#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  map<char, int> count;
  for (char c : s)
    count[c] += 1;
  for (auto [c, n] : count)
  {
    if (n == 1)
    {
      cout << c << endl;
      return 0;
    }
  }
}
