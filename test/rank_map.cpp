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

#include "reimplalgo/rank_map.hpp"

#include <functional>
#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(RankMapTest, NullInputTest)
{
  const std::vector<int> input {};
  EXPECT_TRUE(reimplalgo::rank_map(input.cbegin(), input.cend()).empty());
  EXPECT_TRUE(reimplalgo::rank_map(input.cbegin(), input.cend(), std::greater<int>{}).empty());
  EXPECT_TRUE(reimplalgo::rank_map(input.cbegin(), input.cend(), [](auto lhs, auto rhs){return lhs < rhs;}).empty());
}

TEST(RankMapTest, OrderInputTest)
{
  using ::testing::ElementsAre;
  using ::testing::Pair;

  const std::vector input {1, 2, 3, 4, 5};
  EXPECT_THAT(reimplalgo::rank_map(input.cbegin(), input.cend()),
              ElementsAre(Pair(1, 0), Pair(2, 1), Pair(3, 2), Pair(4, 3), Pair(5, 4)));
  EXPECT_THAT(reimplalgo::rank_map(input.cbegin(), input.cend(), std::greater<int>{}),
              ElementsAre(Pair(5, 0), Pair(4, 1), Pair(3, 2), Pair(2, 3), Pair(1, 4)));
}

TEST(RankMapTest, ReverseInputTest)
{
  using ::testing::ElementsAre;
  using ::testing::Pair;

  const std::vector input {5, 4, 3, 2, 1};
  EXPECT_THAT(reimplalgo::rank_map(input.cbegin(), input.cend()),
              ElementsAre(Pair(1, 0), Pair(2, 1), Pair(3, 2), Pair(4, 3), Pair(5, 4)));
  EXPECT_THAT(reimplalgo::rank_map(input.cbegin(), input.cend(), std::greater<int>{}),
              ElementsAre(Pair(5, 0), Pair(4, 1), Pair(3, 2), Pair(2, 3), Pair(1, 4)));
}

TEST(RankMapTest, DuplicationInputTest)
{
  using ::testing::ElementsAre;
  using ::testing::Pair;

  const std::vector input {1, 1, 2, 2, 3};
  EXPECT_THAT(reimplalgo::rank_map(input.cbegin(), input.cend()),
              ElementsAre(Pair(1, 0), Pair(2, 2), Pair(3, 4)));
  EXPECT_THAT(reimplalgo::rank_map(input.cbegin(), input.cend(), std::greater<int>{}),
              ElementsAre(Pair(3, 0), Pair(2, 1), Pair(1, 3)));
}

TEST(RankMapTest, UnorderInputTest)
{
  using ::testing::ElementsAre;
  using ::testing::Pair;

  const std::vector input {4, 2, 1, 3, 5};
  EXPECT_THAT(reimplalgo::rank_map(input.cbegin(), input.cend()),
              ElementsAre(Pair(1, 0), Pair(2, 1), Pair(3, 2), Pair(4, 3), Pair(5, 4)));
  EXPECT_THAT(reimplalgo::rank_map(input.cbegin(), input.cend(), std::greater<int>{}),
              ElementsAre(Pair(5, 0), Pair(4, 1), Pair(3, 2), Pair(2, 3), Pair(1, 4)));
}
