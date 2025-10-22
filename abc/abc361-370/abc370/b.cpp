#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
    {
      cin >> a[i][j];
      a[i][j]--;
    }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (ans >= i)
      ans = a[ans][i];
    else
      ans = a[i][ans];
  }
  cout << ans + 1 << endl;
}
