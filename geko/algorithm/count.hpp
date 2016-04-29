/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_COUNT_HPP
#define GEKO_ALGORITHM_COUNT_HPP

#include <iterator>

namespace geko{
namespace algorithm{

template<typename InputIt, typename T>
inline constexpr typename std::iterator_traits<InputIt>::difference_type
count(InputIt first, InputIt last, const T& value){
    typename std::iterator_traits<InputIt>::difference_type result = 0;

    while (first != last) {
        if (*first == value)
            result++;
        ++first;
    }
    return result;
}

}   // namespace algorithm
}   // namespace geko


#endif
