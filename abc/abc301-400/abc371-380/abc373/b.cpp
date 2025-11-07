#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  map<char, int> sx;
  for (int i = 0; i < s.size(); i++)
    sx[s[i]] = i;
  int ans = 0, now = sx['A'];
  for (char c = 'B'; c <= 'Z'; c++)
  {
    ans += abs(sx[c] - now);
    now = sx[c];
  }
  cout << ans << endl;
}
