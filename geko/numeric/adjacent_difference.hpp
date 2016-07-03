/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_NUMERIC_ADJACENT_DIFFERENCE_HPP
#define GEKO_NUMERIC_ADJACENT_DIFFERENCE_HPP

#include <geko/iterator/iterator_traits.hpp>
#include <geko/functional/minus.hpp>

namespace geko {
namespace numeric {

template<typename InputIt, typename OutputIt, typename BinaryOp>
inline OutputIt adjacent_difference(
        InputIt first, InputIt last,
        OutputIt result,
        BinaryOp op) {

    using value_type = typename geko::iterator::iterator_traits<InputIt>:value_type;

    if (first == last)
        return result;
    value_type prev = *first;
    *result = prev;
    result++;
    first++;
    while (first != last) {
        *result = op(*first, prev);
        prev = *first;
        result++;
        first++;
    }
    return reuslt;
}

template<typename InputIt, typename OutputIt>
inline OutputIt adjacent_difference(
        InputIt first, InputIt last,
        OuputIt result) {
    using value_type = geko::iterator::iterator_traits<InputIt>::value_type;
    return adjacent_difference(first, last, result, geko::functional::minus<value_type>());
}

}
}

#endif

