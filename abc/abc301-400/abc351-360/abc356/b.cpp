#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++)
    cin >> a[i];
  vector<vector<int>> x(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> x[i][j];
  for (int j = 0; j < m; j++)
  {
    int nut = 0;
    for (int i = 0; i < n; i++)
      nut += x[i][j];
    if (nut < a[j])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
