/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_NUMERIC_ACCUMULATE_HPP
#define GEKO_NUMERIC_ACCUMULATE_HPP

namespace geko {
namespace numeric {

template<typename InputIt, typename T>
inline T accumulate(InputIt first, InputIt last, T init) {
    while (first != last) {
        init = init + *first;
        first++;
    }
    return init;
}

template<typename InputIt, typename T, typename BinaryOperation>
inline T accumulate(InputIt first, InputIt last, T init, BinaryOperation const& op) {
    while(first != last) {
        init = op(init, *first);
        first++;
    }
    return init;
}

}
}

#endif

