#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;
  int len = min(s.size(), t.size());
  for (int i = 0; i < len; i++)
  {
    if (s[i] != t[i])
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
  if (s.size() != t.size())
    cout << len + 1 << endl;
  else
    cout << 0 << endl;
}
