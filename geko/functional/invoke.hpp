/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_FUNCTIONAL_INVOKE_HPP
#define GEKO_FUNCTIONAL_INVOKE_HPP

#include <type_traits>
#include <geko/type_traits/is_reference_wrapper.hpp>

namespace geko {
namespace functioanl {

namespace detail {

template<
    typename Base,
    typename T,
    typename Derived,
    typename ... Args>
static typename std::enable_if<
    std::is_function<T>::value &&
    std::is_base_of<Base, typename std::decay<Derived>::type>::value,
    decltype((std::forward<Derived>(der).*mem_fun_pointer)(std::forward<Args>(args) ...))
>::type
INVOKE(
        T Base::*mem_fun_pointer,
        Derived&& der,
        Args&& ... args){
    return (std::forward<Derived>(der).*mem_fun_pointer)(std::forward<Args>(args) ...);
}

template<typename Base, typename T, typename Wrap, typename ... Args>
static typename std::enable_if<
    std::is_function<T>::value &&
    geko::type_traits::is_reference_wrapprt<typename std::decay<Wrap>::type>::value,
    decltype((wrap.get().*qmf)(std::forward<Args>(args)...))
>::type
INVOKE(
        T Base::*mem_fun_pointer,
        Wrap&& wrap,
        Args&& ... args) {
    return (wrap.get().*qmf)(std::forward<Args>(args)...);
}

template<typename Base, typename T, typename Pointer, typename ... Args>
static typename std::enable_if<
    std::is_function<T>::value &&
    !geko::type_traits::is_reference_wrapprt<typename std::decay<Pointer>::type>::value &&
    !std::is_base_of<Base, typename std::decay<Pointer>::type>::value,
    decltype(((*std::forward<Pointer>(ptr)).*mem_fun_pointer)(std::forward<Args>(args)...))
>::type
INVOKE(
        T Base::*mem_fun_pointer,
        Pointer&& ptr,
        Args&& ... args) {
    return ((*std::forward<Pointer>(ptr)).*mem_fun_pointer)(std::forward<Args>(args)...);
}

template<typename Base, typename T, typename Derived>
static typename std::enable_if<
    !std::is_function<T>::value &&
    std::is_base_of<Base, typename std::decay<Derived>::type>::value,
    decltype(std::forward<Derived>(der).*mem_data_pointer)
>::type
INVOKE(
        T Base::*mem_data_pointer,
        Derived&& der) {
    return std::forward<Derived>(der).*mem_data_pointer;
}

template<typename Base, typename T, typename Wrap>
static typename std::enable_if<
    !std::is_function<T>::value &&
    geko::type_traits::is_reference_wrapper<typename std::decay<Wrap>::type>::value,
    decltype(wrap.get().*mem_data_pointer)
>::type
INVOKE(
        T Base::*mem_data_pointer,
        Wrap&& wrap) {
    return wrap.get().*mem_data_pointer;
}

template<typename Base, typename T, typename Pointer>
static typename std::enable_if<
    !std::is_function<T>::value &&
    !geko::type_traits::is_reference_wrapprt<typename std::decay<Pointer>::type>::value &&
    !std::is_base_of<Base, typename std::decay<Pointer>::type>::value,
    decltype((*std::forward<Pointer>(ptr)).*mem_data_pointer)
>::type
INVOKE(
        T Base::*mem_data_pointer,
        Pointer&& ptr) {
    return (*std::forward<Pointer>(ptr)).*mem_data_pointer;
}

template<typename F, typename ... Args>
static std::enable_if<
    !std::is_member_pointer<std::decay<F>::type>::value,
    decltype(std::forward<F>(f)(std::forward<Args>(args)...))
>::type
INVOKE(
        F&& f,
        Args&& ... args) {
    return std::forward<F>(f)(std::forward<Args>(args)...);
}

} // namespace detail


template<typename F, typename ... ArgTypes>
static auto invoke(F&& f, ArgTypes&& ... args) {
    return detail::INVOKE(std::forward<F>(f), std::forward<ArgTypes>(args) ...);
}

}
}

#endif

