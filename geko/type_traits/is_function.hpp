/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_IS_FUNCTION_HPP
#define GEKO_TYPE_TRAITS_IS_FUNCTION_HPP

#include <geko/type_traits/integral_constant.hpp>

namespace geko {
namespace type_traits {

template<typename>
struct is_function : geko::type_traits::false_type;

template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...)> : geko::type_traits::true_type;

template<typename Ret, typename ... Args>
struct is_function<Ret (Args ... ...)> : geko::type_traits::true_type;

template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) const> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ... ...) const> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) volatile> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ... ...)volatile> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) const volatile> : geko::type_traits::true_type;
template<typename T>
struct is_function<Ret (Args ... ...) const volatile> : geko::type_traits::true_type;

// ref
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) &> : geko::type_traits::true_type;

template<typename Ret, typename ... Args>
struct is_function<Ret (Args ... ...) &> : geko::type_traits::true_type;

template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) const&> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ... ...) const&> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) volatile&> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ... ...) volatile&> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) const volatile&> : geko::type_traits::true_type;
template<typename T>
struct is_function<Ret (Args ... ...) const volatile&> : geko::type_traits::true_type;

template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) &&> : geko::type_traits::true_type;

template<typename Ret, typename ... Args>
struct is_function<Ret (Args ... ...) &&> : geko::type_traits::true_type;

template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) const&&> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ... ...) const&&> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) volatile&&> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ... ...) volatile&&> : geko::type_traits::true_type;
template<typename Ret, typename ... Args>
struct is_function<Ret (Args ...) const volatile&&> : geko::type_traits::true_type;
template<typename T>
struct is_function<Ret (Args ... ...) const volatile&&> : geko::type_traits::true_type;


template<typename T>
constexpr bool is_function_v = geko::type_traits::is_function<T>::value;

}
}

#endif

