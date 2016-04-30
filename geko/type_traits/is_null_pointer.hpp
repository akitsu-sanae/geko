/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_NULL_POINTER_HPP
#define GEKO_TYPE_TRAITS_IS_NULL_POINTER_HPP

#include <geko/type_traits/is_same.hpp>

namespace geko {
namespace type_traits {

template<typename T>
struct is_null_pointer : geko::type_traits::is_same<T, decltype(nullptr)> {};

template<typename T>
constexpr bool is_null_pointer_v = geko::type_traits::is_null_pointer<T>::value;

}
}

#endif

