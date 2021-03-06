/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ITERATOR_NEXT_HPP
#define GEKO_ITERATOR_NEXT_HPP

#include <iterator>
#include <geko/iterator/iterator_traits.hpp>

namespace geko {
namespace iterator {

template<typename ForwardIterator>
ForwardIterator next(
        ForwardIterator it,
        typename geko::iterator::iterator_traits<ForwardIterator>::difference_type n) {
    std::advance(it, n);
    return it;
}


}
}

#endif

