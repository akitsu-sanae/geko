/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_VOID_HPP
#define GEKO_TYPE_TRAITS_IS_VOID_HPP

#include <geko/type_traits/is_same.hpp>
#include <geko/type_traits/remove_cv.hpp>

namespace geko {
namespace type_traits {

template<typename T>
struct is_void : geko::type_traits::is_same<
                 void,
                 typename geko::type_traits::remove_cv<T>::type>
{};

template<typename T>
constexpr bool is_void_v = is_void<T>::value;

}
}

#endif

