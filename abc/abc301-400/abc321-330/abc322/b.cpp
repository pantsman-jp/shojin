#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  bool head = true, tail = true;
  rep(i, n)
  {
    if (s[i] != t[i])
      head = false;
    if (s[i] != t[m - n + i])
      tail = false;
  }
  if (head and tail)
    cout << 0 << endl;
  else if (head and !tail)
    cout << 1 << endl;
  else if (tail and !head)
    cout << 2 << endl;
  else
    cout << 3 << endl;
}
