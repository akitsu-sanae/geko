/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_ARRAY_HPP
#define GEKO_TYPE_TRAITS_IS_ARRAY_HPP

#include <array>
#include <geko/type_traits/integral_constant.hpp>

namespace geko {
namespace type_traits {

template<typename T>
struct is_array : geko::type_traits::false_type {};

template<typename T>
struct is_array<T[]> : geko::type_traits::true_type {};

template<typename T, std::size_t N>
struct is_array<T[N]> : geko::type_traits::true_type {};

template<typename T, std::size_t N>
struct is_array<std::array<T, N>> : geko::type_traits::true_type {};

}
}

#endif

