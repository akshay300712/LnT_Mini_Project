#include "fun.h"
#include "unity.h"

  /* Modify these two lines according to the project */
    #define PROJECT_NAME    "Tic Tac Toe"

    /* Prototypes for all the test functions */
    void test_isFull(void);
/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}
 int main(void)
    {
    /* Initiate the Unity Test Framework */
      UNITY_BEGIN();

    /* Run Test functions */
      RUN_TEST(test_isFull);
      RUN_TEST(test_insrtValue);
      

      /* Close the Unity Test Framework */
      return UNITY_END();
    }
void test_isFull(void) {
      char grid1[3][3] =  {{'X','O','X'},{'X','X','O'},{'O','O','X'}};      

      TEST_ASSERT_EQUAL(0, isFull());
   

    }
 void test_insertValue(void)
    {
      TEST_ASSERT_EQUAL('X', insertValue(1,0,X));
      TEST_ASSERT_EQUAL('O', nsertValue(1,0,O));
    }
