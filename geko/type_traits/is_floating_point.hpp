/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_FLOATING_POINT_HPP
#define GEKO_TYPE_TRAITS_IS_FLOATING_POINT_HPP

#include <geko/type_traits/integral_constant.hpp>

namespace geko {
namespace type_traits {

template<typename>
struct is_floating_point :
    geko::type_traits::integral_constant<
    bool,
    geko::type_traits::is_same<
        typename geko::type_traits::remove_cv<T>::type,
        float>::value ||
    geko::type_traits::is_same<
        typename geko::type_traits::remove_cv<T>::type,
        double>::value ||
    geko::type_traits::is_same<
        typename geko::type_traits::remove_cv<T>::type,
        long double>::value
    > {};

template<typename T>
constexpr bool is_floating_point_v = geko::type_traits::is_floating_point<T>::value;

}
}

#endif

