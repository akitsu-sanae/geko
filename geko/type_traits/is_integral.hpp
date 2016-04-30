/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_INTEGRAL_HPP
#define GEKO_TYPE_TRAITS_IS_INTEGRAL_HPP

#include <limits>
#include <geko/type_traits/integral_constant.hpp>

namespace geko {
namespace type_traits {

template<typename T>
struct is_integral :
    // TODO: In the feature, use geko::numeric_limits<T>::is_integer
    geko::type_traits::integral_constant<bool, std::numeric_limits<T>::is_integer>
{};

template<typename T>
constexpr bool is_integral_v = geko::type_traits::is_integral<T>::value;

}
}

#endif

