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

namespace reimplalgo
{
namespace no_recursive
{

template<typename T>
constexpr T combination_impl(const T& n, const T& r)
{
  T ans {1};
  for (T i {0}; i < r; ++i)
    ans = ans * (n - i) / (i + 1); // avoid under flow
  return ans;
}

template<typename T>
constexpr T combination(const T& n, const T& r)
{
  return combination_impl(n, r <= n / 2 ? r : n - r);
}

}

namespace simple_recursive
{

template<typename T>
constexpr T combination_impl(const T& n, const T& r)
{
  if (r == 0)
    return 1;
  return combination_impl(n, r - 1) * (n - r + 1) / r;
}

template<typename T>
constexpr T combination(const T& n, const T& r)
{
  return combination_impl(n, r <= n / 2 ? r : n - r);
}

}
}
