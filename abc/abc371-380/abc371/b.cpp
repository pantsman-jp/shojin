#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<bool> ok(n, true);
  for (int i = 0; i < m; i++)
  {
    int a;
    char b;
    cin >> a >> b;
    a--;
    if (b == 'F')
      cout << "No" << endl;
    else
    {
      if (ok[a])
      {
        cout << "Yes" << endl;
        ok[a] = false;
      }
      else
        cout << "No" << endl;
    }
  }
}
