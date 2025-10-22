#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<string> ss(n);
  for (int i = 0; i < n; i++)
    cin >> ss[i];
  int m = 0;
  for (string s : ss)
    m = max(m, (int)s.size());
  for (int j = 0; j < m; j++)
  {
    string t;
    for (int i = n - 1; -1 < i; i--)
    {
      if (j < (int)ss[i].size())
        t += ss[i][j];
      else
        t += '*';
    }
    while (!t.empty() && t.back() == '*')
      t.pop_back();
    cout << t << endl;
  }
}
