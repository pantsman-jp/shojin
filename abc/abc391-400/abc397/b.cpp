#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int ans = 0;
  char expected = 'i';
  for (char c : s)
  {
    if (c == expected)
    {
      if (expected == 'i')
        expected = 'o';
      else
        expected = 'i';
      continue;
    }
    else
      ans++;
  }
  if ((ans + (int)s.size()) % 2 == 0)
    cout << ans << endl;
  else
    cout << ++ans << endl;
}
