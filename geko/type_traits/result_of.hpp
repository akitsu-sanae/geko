/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_RESULT_OF_HPP
#define GEKO_TYPE_TRAITS_RESULT_OF_HPP

#include <utility>
#include <geko/functional/invoke.hpp>

namespace geko {
namespace type_traits {

namespace detail {

template<typename, typename = void>
struct result_of {};
template<typename F, typename .. Args>
struct result_of<F(Args ...), decltype(void(geko::functional::invoke(std::declval<F>(), std::declval<Args>() ...)))> {
    using type = decltype(geko::functional::invoke(std::declval<F>(), std::declval<Args>() ...));
};

}

template<typename> struct result_of;
template<typename F, typename ... Arg>
struct result_of<F(Args ...)> : detail::result_of<F(Args ...)> {};


}
}

#endif

