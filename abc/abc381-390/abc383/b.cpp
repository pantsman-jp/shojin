#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int h, w, d;
  cin >> h >> w >> d;
  vector<string> s(h);
  for (int i = 0; i < h; i++)
    cin >> s[i];
  int ans = 0;
  for (int i1 = 0; i1 < h; i1++)
  {
    for (int j1 = 0; j1 < w; j1++)
    {
      if (s[i1][j1] == '#')
        continue;
      for (int i2 = i1; i2 < h; i2++)
      {
        for (int j2 = j1; j2 < w; j2++)
        {
          if ((s[i2][j2] == '#') || ((i1 == i2) && (j1 == j2)))
            continue;
          int tmp = 0;
          for (int i = 0; i < h; i++)
          {
            for (int j = 0; j < w; j++)
            {
              if ((s[i][j] == '.') && ((abs(i - i1) + abs(j - j1) <= d) || (abs(i - i2) + abs(j - j2) <= d)))
                tmp++;
            }
          }
          ans = max(ans, tmp);
        }
      }
    }
  }
  cout << ans << endl;
}
