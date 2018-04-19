/*
BSD 2-Clause License

Copyright (c) 2017, Doi Yusuke
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
#include "reimplalgo/factorial.hpp"

#include <gtest/gtest.h>

using numeric_type = int;
using func_signature = numeric_type(*)(const numeric_type&);

class FuctorialTest
  : public ::testing::TestWithParam<func_signature>
{
protected:
  virtual ~FuctorialTest();
};

FuctorialTest::~FuctorialTest() = default;

TEST_P(FuctorialTest, NormalInputTest)
{
  EXPECT_EQ(1, GetParam()(0));
  EXPECT_EQ(1, GetParam()(1));
  EXPECT_EQ(2, GetParam()(2));
  EXPECT_EQ(6, GetParam()(3));
  EXPECT_EQ(40320, GetParam()(8));
}

INSTANTIATE_TEST_CASE_P(FunctionsParameterized, FuctorialTest,
    ::testing::Values(reimplalgo::no_recursive::factorial<numeric_type>));
