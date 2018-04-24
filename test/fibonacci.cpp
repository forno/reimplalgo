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
#include "reimplalgo/fibonacci.hpp"

#include <gtest/gtest.h>

using numeric_type = int;
using func_signature = numeric_type(*)(const numeric_type&);

class FibonacciTest
  : public ::testing::TestWithParam<func_signature>
{
protected:
  virtual ~FibonacciTest();
};

FibonacciTest::~FibonacciTest() = default;

TEST_P(FibonacciTest, InitialInputTest)
{
  EXPECT_EQ(0, GetParam()(0));
  EXPECT_EQ(1, GetParam()(1));
}

TEST_P(FibonacciTest, NormalInputTest)
{
  EXPECT_EQ(1, GetParam()(2));
  EXPECT_EQ(2, GetParam()(3));
  EXPECT_EQ(3, GetParam()(4));
  EXPECT_EQ(5, GetParam()(5));
  EXPECT_EQ(8, GetParam()(6));
  EXPECT_EQ(13, GetParam()(7));
  EXPECT_EQ(21, GetParam()(8));
  EXPECT_EQ(34, GetParam()(9));
  EXPECT_EQ(55, GetParam()(10));
}

INSTANTIATE_TEST_CASE_P(FunctionsParameterized, FibonacciTest,
    ::testing::Values(static_cast<func_signature>(reimplalgo::no_recursive::fibonacci),
                      static_cast<func_signature>(reimplalgo::recursive::fibonacci)));
