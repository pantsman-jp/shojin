#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  vector<int> count(26);
  for (char c : s)
    ++count[c - 'a'];
  vector<int> freq(s.size() + 1);
  for (int n : count)
    if (n > 0)
      ++freq[n];
  for (int x : freq)
    if (x != 0 && x != 2)
    {
      cout << "No" << endl;
      return 0;
    }
  cout << "Yes" << endl;
}
