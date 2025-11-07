#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int m;
  cin >> m;
  vector<int> ans;
  int ai = 0;
  while (m > 0)
  {
    int d = m % 3;
    for (int j = 0; j < d; j++)
      ans.push_back(ai);
    m /= 3;
    ai++;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << ' ';
  cout << endl;
}
