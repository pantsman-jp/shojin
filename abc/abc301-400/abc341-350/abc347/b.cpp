#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  set<string> ans;
  for (int len = 1; len < (int)s.size() + 1; ++len)
    for (int i = 0; i + len < (int)s.size() + 1; ++i)
      ans.insert(s.substr(i, len));
  cout << ans.size() << endl;
}
