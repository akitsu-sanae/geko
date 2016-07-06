/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ITERATOR_END_HPP
#define GEKO_ITERATOR_END_HPP

#include <cstddef>

namespace geko {
namespace iterator {

template<typename Con>
inline constexpr auto end(Con& c) { return c.end(); }
template<typename Con>
inline constexpr auto end(Con const& c) { return c.end(); }

template<typename T, std::size_t N>
inline constexpr T* end(T (&arr)[N]) noexcept { return arr + N; }

template<typename Container>
inline constexpr auto cend(Container const& c) {
    return geko::iterator::end(c);
}

}
}

#endif

