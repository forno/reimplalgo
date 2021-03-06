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

#include "reimplalgo/combination.hpp"

#include <limits>

#include <gtest/gtest.h>

using numeric_type = int;
using func_signature = numeric_type(*)(const numeric_type&, const numeric_type&);

class CombinationTest
  : public ::testing::TestWithParam<func_signature>
{
protected:
  virtual ~CombinationTest();
};

CombinationTest::~CombinationTest() = default;

TEST_P(CombinationTest, NormalInputTest)
{
  EXPECT_EQ(3, GetParam()(3, 2));
  EXPECT_EQ(6, GetParam()(4, 2));
  EXPECT_EQ(124750, GetParam()(500, 2));
  EXPECT_EQ(142506, GetParam()(30, 5));
  EXPECT_EQ(38760, GetParam()(20, 6));
  EXPECT_EQ(11440, GetParam()(16, 7));
}

TEST_P(CombinationTest, ZeroInputTest)
{
  EXPECT_EQ(1, GetParam()(0, 0));
  EXPECT_EQ(1, GetParam()(1, 0));
  EXPECT_EQ(1, GetParam()(5, 0));
}

TEST_P(CombinationTest, TopInputTest)
{
  EXPECT_EQ(1, GetParam()(1, 1));
  EXPECT_EQ(1, GetParam()(5, 5));
}

TEST_P(CombinationTest, BigInputTest)
{
  constexpr auto max_value {std::numeric_limits<numeric_type>::max()};
  EXPECT_EQ(1, GetParam()(max_value, 0));
  EXPECT_EQ(max_value, GetParam()(max_value, 1));
  EXPECT_EQ(1, GetParam()(max_value, max_value));
  EXPECT_EQ(max_value, GetParam()(max_value, max_value - 1));
}

INSTANTIATE_TEST_CASE_P(FunctionsParameterized, CombinationTest,
    ::testing::Values(reimplalgo::no_recursive::combination<numeric_type>,
                      reimplalgo::simple_recursive::combination<numeric_type>));
