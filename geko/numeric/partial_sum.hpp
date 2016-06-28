/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_NUMERIC_PARTIAL_SUM_HPP
#define GEKO_NUMERIC_PARTIAL_SUM_HPP

// TODO: use my geko.iterator
#include <iterator>
#include <geko/functional/plus.hpp>

namespace geko {
namespace numeric {

template<typename InputIt, typename OutputIt, typename BinaryOp>
inline OutputIt partial_sum(InputIt first, InputIt last, OutputIt result, BinaryOp op) {
    if (first == last)
        return result;

    using value_type = std::iterator_traits<InputIt>::value_type value_type;
    value_type val = *first;
    *result = val;
    first++;
    result++;
    while(first != last) {
        val = op(val, first);
        *result = val;
        first++;
        result++;
    }
    return result;
}

template<typename InputIt, typename OutputIt>
inline OutputIt partial_sum(
        InputIt first, InputIt last,
        OutputIt result) {
    using value_type = std::iterator_traits<InputIt>::value_type;
    return partial_sum(first, last, result, geko::functional::plus<value_type>());
}

}
}

#endif

