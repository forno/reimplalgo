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

#include <cstddef>

namespace reimplalgo
{
namespace integral
{

template<typename F, typename T>
T trapezoidal_rule_impl(F integrand, const T& begin, const T& end, std::size_t count_partions)
{
  if (count_partions == 0)
    return 0;
  if (count_partions == 1)
    return integrand(begin) * (end - begin);
  const auto counts_left {count_partions / 2};
  const auto mid {begin + (end - begin) / static_cast<T>(count_partions) * static_cast<T>(counts_left)};
  return trapezoidal_rule_impl(integrand, begin, mid, counts_left) +
         trapezoidal_rule_impl(integrand, mid, end, count_partions - counts_left);
}

template<typename F, typename T>
T trapezoidal_rule(F integrand, const T& begin, const T& end, std::size_t count_partions)
{
  if (begin > end)
    return -trapezoidal_rule(integrand, end, begin, count_partions);
  if (begin == end || count_partions == 0)
    return 0;
  return trapezoidal_rule_impl(integrand, begin, end, count_partions) + 
             (-integrand(begin) + integrand(end)) * (end - begin) / static_cast<T>(count_partions) / 2;
}

}
}
