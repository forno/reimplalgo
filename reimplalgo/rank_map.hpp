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

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <map>
#include <type_traits>
#include <utility>

namespace reimplalgo
{

template<typename Iter1,
         typename Iter2,
         typename Compare =
             std::less<std::common_type_t<
                           typename std::iterator_traits<Iter1>::value_type,
                           typename std::iterator_traits<Iter2>::value_type>>,
         typename ValueType =
             std::common_type_t<typename std::iterator_traits<Iter1>::value_type,
                                typename std::iterator_traits<Iter2>::value_type>>
std::map<ValueType, std::size_t, Compare>
rank_map(Iter1 begin, Iter2 end, Compare comp_function = Compare{})
{
  std::map<ValueType, std::size_t, Compare> ans(std::move(comp_function));
  std::for_each(begin, end, [&ans](const auto& e){++ans[e];});

  std::size_t rank_value {0};
  std::for_each(ans.begin(), ans.end(), [&rank_value](auto& e) {
    rank_value += std::exchange(e.second, rank_value);
  });
  return ans;
}

}
