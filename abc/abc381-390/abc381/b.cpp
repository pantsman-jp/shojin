#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int len = s.size();
  if (len % 2 != 0)
  {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < len / 2; i++)
  {
    if (s[2 * i] != s[2 * i + 1])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  map<char, int> count;
  for (char c : s)
    count[c]++;
  for (auto [_, n] : count)
  {
    if (n != 2)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
