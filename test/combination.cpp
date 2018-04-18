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
#include "reimplalgo/combination.hpp"

#include <gtest/gtest.h>

using func_signature = int(*)(const int&, const int&);

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
}

INSTANTIATE_TEST_CASE_P(FunctionsParameterized, CombinationTest,
    ::testing::Values(reimplalgo::no_recursive::combination<int>,
                      reimplalgo::simple_recursive::combination<int>));

//TEST(AnswerTest, NormalInputTest)
//{
//  for (auto n {0}; n <= 5; ++n) {
//    for (auto r {0}; r <= n; ++r)
//      std::cout << n << " C " << r << '=' << reimplalgo::combination_fool(n, r) << "  ";
//    std::cout << '\n';
//  }
//}
