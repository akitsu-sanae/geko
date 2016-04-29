/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_REMOVE_CV_HPP
#define GEKO_TYPE_TRAITS_REMOVE_CV_HPP

namespace geko {
namespace type_traits {

template<typename T>
struct remove_const { using type = T; };
template<typename T>
struct remove_const<const T> { using type = T; };
template<typename T>
struct remove_volatile { using type = T; };
template<typename T>
struct remove_volatile<volatile T> { using type = T; };

template<typename T>
struct remove_cv {
    using type = typename geko::type_traits::remove_volatile<
        typename geko::type_traits::remove_const<T>::type
        >::type;
};

template<typename T>
using remove_const_t = typename geko::type_traits::remove_const<T>::type;
template<typename T>
using remove_volatile_t = typename geko::type_traits::remove_volatile<T>::type;
template<typename T>
using remove_cv_t = typename geko::type_traits::remove_cv<T>::type;


}
}

#endif

