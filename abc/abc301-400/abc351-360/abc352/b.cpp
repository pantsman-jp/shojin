#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;
  int ans = 0;
  for (char c : s)
  {
    while (true)
    {
      if (t[ans] == c)
      {
        cout << ++ans << ' ';
        break;
      }
      ++ans;
    }
  }
  cout << endl;
}
