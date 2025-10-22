#include <iostream>
#include <string>
using namespace std;

int main()
{
  int w, b;
  cin >> w >> b;
  string s = "wbwbwwbwbwbw";
  for (int i = 0; i < s.size(); ++i)
  {
    int cb = 0, cw = 0;
    for (int j = 0; j < w + b; ++j)
    {
      if (s[(i + j) % s.size()] == 'w')
        ++cw;
      else
        ++cb;
    }
    if (cw == w && cb == b)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
