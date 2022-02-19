#include "solution.h"
#include "util.h"
#include <queue>
#include <numeric>
#include <algorithm>
#include <string>
#include <deque>
#include <sstream>
using namespace sol1087;
using namespace std;

/*takeaways
  - every brace expression represents a level
    in the BFS
    - "{a,b}c{d,e}f" has 4 levels
    - a b (1) - c (2) - de (3) - f(4)
  - when you perform a BFS you are merging levels
    on level at a time
    - an given element at the previous level
      need to be merged with each elements at
      the current level before it can be poped
      out from the queue.
*/
vector<string> Solution::expand(string s)
{
  for (auto i = 0; i < s.size(); i++)
    if (s[i] == '{' || s[i] == '}')
      s[i] = ' ';

  /*C++ notes
    - use deque to later we can convert
      it to a vector easily
  */
  auto q = deque<string>();
  auto ss = stringstream(s);
  string level;

  while (getline(ss, level, ' '))
  {
    /*
      - if there is a leading space the first
        token will be empty
    */
    if (level == "")
      continue;
    auto ts = stringstream(level);
    string option;

    /* collect all the elements at this level */
    auto options = vector<string>();
    while (getline(ts, option, ','))
      if (option != "")
        options.push_back(option);

    int size = q.size();
    if (size == 0)
      for (auto o : options)
        q.push_back(o);
    else
    {
      while (size > 0)
      {
        for (auto o : options)
          q.push_back(q.front() + o);
        /*
          - you can now pop this element from the
            previous level out as it has been merged
            with every element at this level
        */
        q.pop_front();
        size--;
      }
    }
  }

  return vector<string>(q.begin(), q.end());
}