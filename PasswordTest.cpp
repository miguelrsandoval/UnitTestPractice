/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, leading_characters)
{
    Password my_password;
	int actual = my_password.count_leading_characters("zzzz");
	ASSERT_EQ(4,actual);
}
TEST(PasswordTest, leading_symbols)
{
    Password my_password;
	int actual = my_password.count_leading_characters("$$$z");
	ASSERT_EQ(3,actual);
}
TEST(PasswordTest, leading_same_numbers)
{
    Password my_password;
	int actual = my_password.count_leading_characters("111z");
	ASSERT_EQ(3,actual);
}
TEST(PasswordTest, mixed_case)
{
    Password my_password;
	int actual = my_password.has_mixed_case("aBc");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, all_lower_case)
{
    Password my_password;
	int actual = my_password.has_mixed_case("abc");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, all_upper_case)
{
    Password my_password;
	int actual = my_password.has_mixed_case("ABC");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, mixed_symbols_and_upper_letters)
{
    Password my_password;
	int actual = my_password.has_mixed_case("A$B$C*");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, mixed_numbers_and_upper_letters)
{
    Password my_password;
	int actual = my_password.has_mixed_case("A1B2C3");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, symbols_and_mixed_case_letters)
{
    Password my_password;
	int actual = my_password.has_mixed_case("a$B*c&D");
	ASSERT_EQ(1,actual);
}