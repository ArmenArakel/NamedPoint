#include <assert.h>
#include <string.h>

#include <iostream>

#include "src/named_point.hpp"

int main()
{
  const char* name1 = "point_1";
  float x1 = -1.77;
  float y1 = 5.25;
  NamedPoint namP_1(x1, y1, name1);
  
  assert(x1 == namP_1.getX());
  assert(y1 == namP_1.getY());
  assert(strcmp(name1, namP_1.getName()) == 0);

  x1 = 2.33;
  namP_1.setX(x1);
  assert(x1 == namP_1.getX());

  y1 = 5.33;
  namP_1.setY(y1);
  assert(y1 == namP_1.getY());

  const char* name2 = "point_2";
  namP_1.setName(name2);
  assert(strcmp(name2, namP_1.getName()) == 0);

  NamedPoint namP_2(namP_1);
  assert(namP_1 == namP_2);
  
  const char* name3 = "point_3";
  NamedPoint namP_3(-1.77, 5.25, name3);
  namP_2 = namP_3;

  assert(namP_2 == namP_3);

  namP_3.moveTo(2.0, 1.0);
  assert(2.0 == namP_3.getX() && 1.0 == namP_3.getY());

  const char* name4 = "point_4";
  NamedPoint namP_4(-1, -3, name4);
  assert(namP_3.distance(namP_4) == 5);

  std::cout << "Tests passed successfuly" << std::endl;

  return 0;
}
