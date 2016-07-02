/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ITERATOR_BEGIN_HPP
#define GEKO_ITERATOR_BEGIN_HPP

#include <cstddef>

namespace geko {
namespace iterator {

template<typename Con>
inline auto begin(Con& c) { return c.begin(); }

template<typename Con>
inline auto begin(Con const& c) { return c.begin(); }

template<typename T, std::size_t N>
constexpr inline T* begin(T (&arr)[N]) noexcept { return arr; }

}
}

#endif

