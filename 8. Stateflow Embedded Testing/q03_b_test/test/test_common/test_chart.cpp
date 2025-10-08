#include "unity.h"
extern "C" {
  #include "Chart.h"
}

void test_start() {
    Chart_step();
    rtU.start = 1;
    Chart_step();

    TEST_ASSERT_EQUAL(0, rtY.shut);
    TEST_ASSERT_EQUAL(1, rtY.a);
    TEST_ASSERT_EQUAL(0, rtY.b);
    TEST_ASSERT_EQUAL(0, rtY.on);
    TEST_ASSERT_EQUAL(1, rtY.off);

    rtU.start = 0;
    Chart_step();
}

void test_t_on() {
    rtU.t_on = 1;
    Chart_step();

    TEST_ASSERT_EQUAL(0, rtY.shut);
    TEST_ASSERT_EQUAL(1, rtY.a);
    TEST_ASSERT_EQUAL(0, rtY.b);
    TEST_ASSERT_EQUAL(1, rtY.on);
    TEST_ASSERT_EQUAL(0, rtY.off);

    rtU.t_on = 0;
    Chart_step();
}

void test_inc() {
    rtU.inc = 1;
    Chart_step();

    TEST_ASSERT_EQUAL(0, rtY.shut);
    TEST_ASSERT_EQUAL(0, rtY.a);
    TEST_ASSERT_EQUAL(1, rtY.b);
    TEST_ASSERT_EQUAL(1, rtY.on);
    TEST_ASSERT_EQUAL(0, rtY.off);

    rtU.inc = 0;
    Chart_step();
}

void test_dec() {
    rtU.dec = 1;
    Chart_step();

    TEST_ASSERT_EQUAL(0, rtY.shut);
    TEST_ASSERT_EQUAL(1, rtY.a);
    TEST_ASSERT_EQUAL(0, rtY.b);
    TEST_ASSERT_EQUAL(1, rtY.on);
    TEST_ASSERT_EQUAL(0, rtY.off);

    rtU.dec = 0;
    Chart_step();
}

void test_stop() {
    rtU.stop = 1;
    Chart_step();

    TEST_ASSERT_EQUAL(1, rtY.shut);
    TEST_ASSERT_EQUAL(0, rtY.a);
    TEST_ASSERT_EQUAL(0, rtY.b);
    TEST_ASSERT_EQUAL(0, rtY.on);
    TEST_ASSERT_EQUAL(0, rtY.off);

    rtU.stop = 0;
    Chart_step();
}

void runTests() {
  RUN_TEST(test_start);
  RUN_TEST(test_t_on);
  RUN_TEST(test_inc);
  RUN_TEST(test_dec);
  RUN_TEST(test_stop);
}

int main() {
  UNITY_BEGIN();
  runTests();
  UNITY_END();

  return 0;
}


