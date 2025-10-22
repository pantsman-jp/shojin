#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int ans = 0, i = 0, length = s.size() - 1;
  while (true)
  {
    if (i == s.size())
    {
      cout << ans << endl;
      return 0;
    }
    if ((s[i] == '0') && (s[i + 1] == '0'))
    {
      ans++;
      i += 2;
    }
    else
    {
      ans++;
      i++;
    }
  }
}
