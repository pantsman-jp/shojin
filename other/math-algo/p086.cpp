#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, cnt = 0;
  string s;
  cin >> n >> s;
  for (char c : s)
  {
    if (c == '(')
      cnt++;
    if (c == ')')
      cnt--;
    if (cnt < 0)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  if (cnt == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}