/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_NUMERIC_INNER_PRODUCT_HPP
#define GEKO_NUMERIC_INNER_PRODUCT_HPP

namespace geko {
namespace numeric {

template<typename InputIt1, typename InputIt2, typename T>
inline T inner_product(
        InputIt1 first1, InputIt1 last1,
        InputIt2 first2,
        T init) {
    while (first1 != last1) {
        init = init + *first1 * *first2;
        first1++;
        first2++;
    }
    return init;
}

template<
    typename InputIt1, typename InputIt2, typename T,
    typename BinaryOperation1, typename BinaryOperation2>
T inner_product(
        InputIt1 first1, InputIt1 last1,
        InputIt2 first2,
        T init,
        BinaryOperation1 op1, BinaryOperation2 op2) {
    while (first1 != last1) {
        init = op1(init, op2(*first1, *first2));
        first1++;
        first2++;
    }
    return init;
}



}
}

#endif

