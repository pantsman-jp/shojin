#include <iostream>
#include <vector>
using namespace std;

int main()
{
  string s;
  cin >> s;
  vector<int> ans;
  int count = 0;
  for (char c : s)
  {
    if (c == '-')
      count++;
    if (c == '|')
    {
      ans.push_back(count);
      count = 0;
    }
  }
  ans.erase(ans.begin());
  for (int i = 0; i < ans.size(); i++)
  {
    if (i != 0)
      cout << ' ';
    cout << ans[i];
  }
  cout << endl;
}
