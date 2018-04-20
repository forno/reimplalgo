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
#include "reimplalgo/pow.hpp"

#include <limits>

#include <gtest/gtest.h>

using numeric_type = int;
using func_signature = numeric_type(*)(const numeric_type&, const numeric_type&);

class PowTest
  : public ::testing::TestWithParam<func_signature>
{
protected:
  virtual ~PowTest();
};

PowTest::~PowTest() = default;

TEST_P(PowTest, ZeroInputTest)
{
  EXPECT_EQ(1, GetParam()(0, 0));
  EXPECT_EQ(0, GetParam()(0, 1));
  EXPECT_EQ(0, GetParam()(0, 5));
  EXPECT_EQ(1, GetParam()(1, 0));
  EXPECT_EQ(1, GetParam()(5, 0));
  constexpr auto max_value {std::numeric_limits<numeric_type>::max()};
  EXPECT_EQ(1, GetParam()(max_value, 0));
  //EXPECT_EQ(0, GetParam()(0, max_value));
}

TEST_P(PowTest, NormalInputTest)
{
  EXPECT_EQ(1, GetParam()(1, 1));
  EXPECT_EQ(1, GetParam()(1, 5));
  EXPECT_EQ(5, GetParam()(5, 1));
  EXPECT_EQ(125, GetParam()(5, 3));
}

INSTANTIATE_TEST_CASE_P(FunctionsParameterized, PowTest,
    ::testing::Values(reimplalgo::no_recursive::pow<numeric_type>,
                      reimplalgo::recursive::pow<numeric_type>));
