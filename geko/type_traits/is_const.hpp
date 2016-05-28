/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_CONST_HPP
#define GEKO_TYPE_TRAITS_IS_CONST_HPP

namespace geko {
namespace type_traits {

template<typename T>
struct is_const : geko::type_traits::false_type {};
template<typename T>
struct is_const<const T> : geko::type_traits::true_type {};

}
}

#endif




