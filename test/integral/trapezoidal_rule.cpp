/*
BSD 2-Clause License

Copyright (c) 2018, Doi Yusuke
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "reimplalgo/integral/trapezoidal_rule.hpp"

#include <tuple>

#include <gtest/gtest.h>

using func_signature = double(*)(double);

class TrapezoidalRuleTest
  : public ::testing::TestWithParam<std::tuple<func_signature, std::tuple<double, double, double, std::size_t>>>
{
protected:
  virtual ~TrapezoidalRuleTest();
};

TrapezoidalRuleTest::~TrapezoidalRuleTest() = default;

TEST_P(TrapezoidalRuleTest, GeneralTest)
{
  const auto test_data {GetParam()};
  const auto integrand {std::get<0>(test_data)};
  const auto parameters {std::get<1>(test_data)};
  EXPECT_EQ(std::get<0>(parameters),
            reimplalgo::integral::trapezoidal_rule(
                integrand,
                std::get<1>(parameters),
                std::get<2>(parameters),
                std::get<3>(parameters)));
}

INSTANTIATE_TEST_CASE_P(ConstantZeroTest, TrapezoidalRuleTest, ::testing::Combine(
    ::testing::Values([](double){return 0.;}),
    ::testing::Values(std::tuple{0., 0., 0., 0},
                      std::tuple{0., 0., 0., 1},
                      std::tuple{0., 0., 0., std::numeric_limits<std::size_t>::max()},
                      std::tuple{0., 1., 1., 0},
                      std::tuple{0., -1., -1., 0})));

INSTANTIATE_TEST_CASE_P(SimpleLinearProportionalTest, TrapezoidalRuleTest, ::testing::Combine(
    ::testing::Values([](double e){return e;}),
    ::testing::Values(std::tuple{0., 0., 0., 0},
                      std::tuple{0., 0., 0., 1},
                      std::tuple{0., 0., 0., std::numeric_limits<std::size_t>::max()},
                      std::tuple{0., 1., 1., 0},
                      std::tuple{0., -1., -1., 0})));

INSTANTIATE_TEST_CASE_P(HalfSizeLinearProportionalTest, TrapezoidalRuleTest, ::testing::Combine(
    ::testing::Values([](double e){return e/2;}),
    ::testing::Values(std::tuple{0., 0., 0., 0},
                      std::tuple{0., 0., 0., 1},
                      std::tuple{0., 0., 0., std::numeric_limits<std::size_t>::max()},
                      std::tuple{0., 1., 1., 0},
                      std::tuple{0., -1., -1., 0})));


INSTANTIATE_TEST_CASE_P(SquareTest, TrapezoidalRuleTest, ::testing::Combine(
    ::testing::Values([](double e){return e*e;}),
    ::testing::Values(std::tuple{0., 0., 0., 0},
                      std::tuple{0., 0., 0., 1},
                      std::tuple{0., 0., 0., std::numeric_limits<std::size_t>::max()},
                      std::tuple{0., 1., 1., 0},
                      std::tuple{0., -1., -1., 0})));
