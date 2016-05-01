/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_LVALUE_REFRENCE_HPP
#define GEKO_TYPE_TRAITS_IS_LVALUE_REFRENCE_HPP

#include <geko/type_traits/integral_constant.hpp>

namespace geko {
namespace type_traits {

template<typename>
struct is_lvalue_reference : geko::type_traits::false_type {};
template<typename T>
struct is_lvalue_reference<T&> : geko::type_traits::true_type {};

template<typename T>
constexpr bool is_lvalue_reference_v = geko::type_traits::is_lvalue_reference<T>::value;

}
}

#endif

