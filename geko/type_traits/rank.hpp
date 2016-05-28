/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_RANK_HPP
#define GEKO_TYPE_TRAITS_RANK_HPP

#include <geko/type_traits/integral_constant.hpp>

namespace geko {
namespace type_traits {

template<typename T>
struct rank : public geko::type_traits::integral_constant<std::size_t, 0> {};

template<typename T>
struct rank<T[]> : public geko::type_traits::integral_constant<std::size_t, rank<T>::value + 1> {};

template<typename T, std::size_t N>
struct rank<T[N]> : public geko::type_traits::integral_constant<std::size_t, rank<T>::value + 1> {};

}
}

#endif
