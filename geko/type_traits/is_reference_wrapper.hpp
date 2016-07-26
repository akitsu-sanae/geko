/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_REFERENCE_WRAPPER_HPP
#define GEKO_TYPE_TRAITS_IS_REFERENCE_WRAPPER_HPP

#include <functional>
#include <geko/type_traits/integral_constant.hpp>

namespace geko {
namespace type_traits {

template<typename>
struct is_reference_wrapper : geko::type_traits::false_type {};
template<typename T>
struct is_reference_wrapper<std::reference_wrapper<T>> : std::true_type {};

template<typename T>
static constexpr bool is_reference_wrapper_v = is_reference_wrapper<T>::value;

}
}


#endif

