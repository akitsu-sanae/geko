/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ITERATOR_ITERATOR_TRAITS_HPP
#define GEKO_ITERATOR_ITERATOR_TRAITS_HPP

#include <cstddef>
#include <geko/iterator/tags.hpp>

namespace geko {
namespace iterator {

template<typename T>
struct iterator_traits {
    using difference_type = typename T::difference_type;
    using value_type = typename T::value_type;
    using pointer = typename T::pointer;
    using reference = typename T::reference;
    using iterator_category = typename T::iterator_category;
};

template<typename T>
struct iterator_traits<T*> {
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using iterator_category = geko::iterator::random_access_iterator_tag;
};

template<typename T>
struct iterator_traits<const T*> {
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = const T*;
    using reference = const T&;
    using iterator_category = geko::iterator::random_access_iterator_tag;
};


}
}

#endif

