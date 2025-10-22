#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> s(n), t(m);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i = 0; i < m; i++)
    cin >> t[i];
  for (int a = 0; a <= n - m; a++)
  {
    for (int b = 0; b <= n - m; b++)
    {
      bool ans = true;
      for (int i = 0; i < m; i++)
      {
        for (int j = 0; j < m; j++)
        {
          if (s[a + i][b + j] != t[i][j])
          {
            ans = false;
            break;
          }
        }
      }
      if (ans)
        cout << a + 1 << " " << b + 1 << endl;
    }
  }
}
