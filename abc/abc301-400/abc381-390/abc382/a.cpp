#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, d;
  string s;
  cin >> n >> d >> s;
  int count = 0;
  for (char c : s)
  {
    if (c == '.')
      ++count;
  }
  cout << count + d << endl;
}
