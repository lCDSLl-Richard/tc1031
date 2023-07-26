#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "priority_queue.h"
#include <iostream>

TEST_CASE("testing push", "[push]")
{
  int adding[] = {50, 25, 75, 12, 40, 60, 80, 5, 18, 30, 45, 55, 80};
  Priority_queue<int> q1, q2, q3;

  q1.push(1);

  for (int i = 0; i < 13; i++)
  {
    if (i < 5)
    {
      q2.push(adding[i]);
    }
    q3.push(adding[i]);
  }

  REQUIRE(q1.top() == 1);
  REQUIRE(q2.top() == 75);
  REQUIRE(q3.top() == 80);
}
