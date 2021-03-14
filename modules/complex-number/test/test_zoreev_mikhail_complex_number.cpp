// Copyright 2021 Zoreev Mikhail

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Zoreev_Mikhail_ComplexNumberTest, Multiplication_On_Pair_Give_Zero_Im) {
    double re_1 = 4.0;
    double im_1 = 1.0;
    double re_2 = 4.0;
    double im_2 = -1.0;
    ComplexNumber number(re_1, im_1);
    ComplexNumber pair_number(re_2, im_2);

    ComplexNumber result = number * pair_number;

    ASSERT_DOUBLE_EQ(result.getIm(), 0.0);
}

TEST(Zoreev_Mikhail_ComplexNumberTest, Equality_Transitivity) {
    double re = 5.5;
    double im = 7.1;

    ComplexNumber number_1(re, im);
    ComplexNumber number_2(re, im);
    ComplexNumber number_3(re, im);

    ASSERT_TRUE(number_1 == number_2);
    ASSERT_TRUE(number_2 == number_3);
    ASSERT_TRUE(number_3 == number_1);
}

TEST(Zoreev_Mikhail_ComplexNumberTest, Summ_With_Opposite_Give_Zero) {
    double re_1 = 4.3;
    double im_1 = 6.5;
    double re_2 = -4.3;
    double im_2 = -6.5;
    ComplexNumber number(re_1, im_1);
    ComplexNumber opposite_number(re_2, im_2);

    ComplexNumber result = number + opposite_number;

    ASSERT_DOUBLE_EQ(result.getRe(), 0.0);
    ASSERT_DOUBLE_EQ(result.getIm(), 0.0);
}

typedef testing::TestWithParam<std::tuple<double, double, double, double>>
        Zoreev_Mikhail_ComplexNumberTest_Parametrized;
TEST_P(Zoreev_Mikhail_ComplexNumberTest_Parametrized,
       Equality_Is_Opposite_To_Inequality) {
    double re_1 = std::get<0>(GetParam());
    double im_1 = std::get<1>(GetParam());
    double re_2 = std::get<2>(GetParam());
    double im_2 = std::get<3>(GetParam());
    ComplexNumber number_1(re_1, im_1);
    ComplexNumber number_2(re_2, im_2);

    bool is_equal = number_1 == number_2;
    bool is_not_equal = number_1 != number_2;

    ASSERT_NE(is_equal, is_not_equal);
}

INSTANTIATE_TEST_CASE_P(/**/, Zoreev_Mikhail_ComplexNumberTest_Parametrized,
    testing::Combine(
  testing::Values(5.0, 3.0, 5.0, 3.0),
  testing::Values(0.0, 7.0, 4.0, 8.0),
  testing::Values(2.0, 6.0, 7.0, 1.0),
  testing::Values(3.5, 3.5, 3.5, 3.5)
));
