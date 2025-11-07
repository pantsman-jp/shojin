#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int up = 0, low = 0;
  for (char c : s)
  {
    if (isupper(c))
      up++;
    if (islower(c))
      low++;
  }
  if (up > low)
  {
    for (char &c : s)
      if (islower(c))
        c = toupper(c);
  }
  else
  {
    for (char &c : s)
      if (isupper(c))
        c = tolower(c);
  }
  cout << s << endl;
}
