/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_UNION_HPP
#define GEKO_TYPE_TRAITS_IS_UNION_HPP

#include <type_traits>
#include <geko/type_traits/integral_constant.hpp>

namespace geko {
namespace type_traits {

template<typename T>
struct is_union : geko::type_traits::integral_constant<
                  bool,
                  std::is_union<T>::value>
{};

template<typename T>
constexpr bool is_union_v = geko::type_traits::is_union<T>::value;

}
}

#endif

