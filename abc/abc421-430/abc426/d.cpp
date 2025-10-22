#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int t;
  cin >> t;
  rep(i, t)
  {
    int n;
    string s;
    cin >> n >> s;
    int zero = 0;
    for (char c : s)
    {
      if (c == 0)
        ++zero;
    }
  }
}
