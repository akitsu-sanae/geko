/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ITERATOR_ITERATOR_HPP
#define GEKO_ITERATOR_ITERATOR_HPP

#include <cstddef>

namespace geko {
namespace iterator {

template<
    typename Category,
    typename T,
    typename Distance = std::ptrdiff_t,
    typename Pointer = T*,
    typename Reference = T&>
struct iterator {
    using value_type = T;
    using difference_type = Distance;
    using pointer = Pointer;
    using reference = Reference;
    using iterator_category = Category;
};

}
}

#endif

