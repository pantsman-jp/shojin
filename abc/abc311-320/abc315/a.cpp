#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  string s;
  cin >> s;
  for (char c : s)
  {
    if (c == 'a' or c == 'i' or c == 'u' or c == 'e' or c == 'o')
      continue;
    else
      cout << c;
  }
  cout << endl;
}
