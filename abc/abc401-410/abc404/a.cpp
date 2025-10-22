#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  for (char c : "abcdefghijklmnopqrstuvwxyz")
  {
    if (find(s.begin(), s.end(), c) == s.end())
    {
      cout << c << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
