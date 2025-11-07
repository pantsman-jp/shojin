#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  vector<int> count(26);
  for (char c : s)
    ++count[c - 'a'];
  int mx = *max_element(count.begin(), count.end());
  rep(i, 26)
  {
    if (count[i] == mx)
    {
      cout << char('a' + i) << endl;
      return 0;
    }
  }
}
