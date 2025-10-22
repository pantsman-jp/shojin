#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n, d;
  string s;
  cin >> n >> d >> s;
  for (int i = 0; i < d; i++)
  {
    for (int j = n - 1; -1 < j; j--)
    {
      if (s[j] == '@')
      {
        s[j] = '.';
        break;
      }
    }
  }
  cout << s << endl;
}
