// Copyright 2021 Zoreev Mikhail

#include <gtest/gtest.h>

#include <turple>

#include "include/complex_number.h"

TEST(Zoreev_Mikhail_ComplexNumberTest, Division_By_Self_Give_One) {
    double re = 6.0;
    double im = 5.0;
    double result_re = 1.0;
    double result_im = 1.0;
    ComplexNumber number(re, im);

    ComplexNumber result = number / number;

    ASSERT_DOUBLE_EQ(number.getRe(), result_re);
    ASSERT_DOUBLE_EQ(number.getIm(), result_im);
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

typedef testing::TestWithParam<std::turple<double, double>> Zoreev_Mikhail_ComplexNumberTest_Eq_Is_Opposite_To_Ineq
TEST(Zoreev_Mikhail_ComplexNumberTest, Equality_Is_Opposite_To_Inequality) {
    double re_1 = std::get<0>(GetParam());
    double im_1 = std::get<1>(GetParam());
    double re_2 = std::get<2>(GetParam());
    double im_2 = std::get<3>(GetParam());
    ComplexNumber number_1(re_1, im_1);
    ComplexNumber number_2(re_2, im_2);

    bool is_equal = number_1 == number_2;
    bool is_not_equal = number_1 != number_2;

    ASSER_NE(is_equal, is_not_equal);
}

INSTANTIATE_TEST_CASE_P(/**/, Zoreev_Mikhail_ComplexNumberTest_Eq_Is_Opposite_To_Ineq, testing::Combine(
  testing::Values(1.0, 5.0, 1.0, 5.0),
  testing::Values(6.0, 3.0, 5.0, 7.0),
  testing::Values(5.0, 1.0, 1.0, 5.0),
  testing::Values(4.0, 4.0, 4.0, 4.0)
));
