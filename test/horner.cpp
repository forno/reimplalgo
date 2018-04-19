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
#include "reimplalgo/horner.hpp"

#include <gtest/gtest.h>

using numeric_type = double;
using func_signature = numeric_type(*)(std::vector<numeric_type>::iterator, std::vector<numeric_type>::iterator, const numeric_type&);

class HornerTest
  : public ::testing::TestWithParam<func_signature>
{
protected:
  virtual ~HornerTest();
};

HornerTest::~HornerTest() = default;

TEST_P(HornerTest, NormalInputTest)
{
  std::vector<numeric_type> values {1, 2, 3, 4, 5};
  EXPECT_EQ(1, GetParam()(values.begin(), values.end(), 0));
  EXPECT_EQ(15, GetParam()(values.begin(), values.end(), 1));
  EXPECT_EQ(129, GetParam()(values.begin(), values.end(), 2));
  EXPECT_EQ(547, GetParam()(values.begin(), values.end(), 3));
  EXPECT_EQ(1593, GetParam()(values.begin(), values.end(), 4));
  EXPECT_EQ(3711, GetParam()(values.begin(), values.end(), 5));
}

INSTANTIATE_TEST_CASE_P(FunctionsParameterized, HornerTest,
    ::testing::Values(static_cast<func_signature>(reimplalgo::no_recursive::horner),
                      static_cast<func_signature>(reimplalgo::recursive::horner)));
