#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<bool> used(n + 1, false);
  for (int i = 0; i < n; i++)
  {
    if (a[i] != -1)
    {
      if (used[a[i]])
      {
        cout << "No" << endl;
        return 0;
      }
      used[a[i]] = true;
    }
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
  {
    if (a[i] == -1)
    {
      for (int j = 1; j <= n; j++)
      {
        if (!used[j])
        {
          ans[i] = j;
          used[j] = true;
          break;
        }
      }
    }
    else
      ans[i] = a[i];
  }
  cout << "Yes" << endl;
  for (int i = 0; i < n; i++)
  {
    if (i > 0)
      cout << ' ';
    cout << ans[i];
  }
  cout << endl;
}
