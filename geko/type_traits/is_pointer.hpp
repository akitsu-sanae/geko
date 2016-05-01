/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_POINTER_HPP
#define GEKO_TYPE_TRAITS_IS_POINTER_HPP

#include <geko/type_traits/integral_constant.hpp>
#include <geko/type_traits/remove_cv.hpp>

namespace geko {
namespace type_traits {

namespace detail {
template<typename>
struct is_pointer_helper : geko::type_traits::false_type;

template<typename T>
struct is_pointer_helper<T*> : geko::type_traits::true_type;

}

template<typename T>
struct is_pointer : geko::type_traits::detail::is_pointer_helper<
    typename geko::type_traits::remove_cv<T>::type>
{};

template<typename T>
constexpr bool is_pointer_v = geko::type_traits::is_pointer<T>::value;

}
}

#endif

