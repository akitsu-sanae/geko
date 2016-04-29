/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_ADD_CV_HPP
#define GEKO_TYPE_TRAITS_ADD_CV_HPP

namespace geko {
namespace type_traits {

template<typename T>
struct add_cv { using type = const volatile T; };

template<typename T>
struct add_const { using type = const T; };

template<typename T>
struct add_volatile { using type = volatile T; };

}
}

#endif

