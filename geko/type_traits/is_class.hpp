/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_CLASS_HPP
#define GEKO_TYPE_TRAITS_IS_CLASS_HPP

namespace geko {
namespace type_traits {

template<typename T>
struct is_class : geko::type_traits::integral_constant<
                  bool,
                  std::is_class<T>::value>
{};

template<typename T>
constexpr bool is_class_v = geko::type_traits::is_class<T>::value;

}
}

#endif

