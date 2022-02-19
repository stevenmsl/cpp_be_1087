#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1087;

/*
Input: “{a,b}c{d,e}f”
Output: [“acdf”,”acef”,”bcdf”,”bcef”]
*/
tuple<string, vector<string>> testFixture1()
{
  return make_tuple<string, vector<string>>(
      "{a,b}c{d,e}f", {"acdf", "acef", "bcdf", "bcef"});
}

/*
Input: “abcd”
Output: [“abcd”]
*/
tuple<string, vector<string>> testFixture2()
{
  return make_tuple<string, vector<string>>(
      "abcd", {"abcd"});
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << Util::toString(get<1>(f)) << endl;
  auto result = Solution::expand(get<0>(f));
  cout << "result: " << Util::toString(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 1 - exepct to see " << Util::toString(get<1>(f)) << endl;
  auto result = Solution::expand(get<0>(f));
  cout << "result: " << Util::toString(result) << endl;
}
main()
{
  test1();
  test2();
  return 0;
}