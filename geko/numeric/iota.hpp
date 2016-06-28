/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_NUMERIC_IOTA_HPP
#define GEKO_NUMERIC_IOTA_HPP

namespace geko{
namespace numeric {

template<class ForwardIt,class T>
inline void iota(ForwardIt first, ForwardIt last, T value){
    while (first != last) {
        *first = value;
        ++first;
        ++value;
    }
}

}   // namespace algorithm
}   // namespace geko


#endif

