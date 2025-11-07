#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<string> a(n), b(n);
  for (string &s : a)
    cin >> s;
  for (string &s : b)
    cin >> s;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (a[i][j] != b[i][j])
      {
        cout << ++i << ' ' << ++j << endl;
        return 0;
      }
    }
  }
}
