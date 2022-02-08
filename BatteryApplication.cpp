#include <assert.h>
#include <iostream>
#include <TestBattery.cpp>

using namespace std;

int main() {
  TestBattery test;
  test.testBattery(58, 60, 0.8, false);
  test.testBattery(40, 80, 0.7, false);
  test.testBattery(40, 60, 0.8, false);
  test.testBattery(40, 60, 0.7, true);
}
