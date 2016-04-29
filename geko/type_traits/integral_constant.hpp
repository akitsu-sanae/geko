/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP
#define GEKO_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP

namespace geko {
namespace type_traits {

template<typename T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant;
    constexpr operator value_type() const noexcept { return value; }
    constexpr value_type operator()() const noexcept { return value; }
};

using true_type = geko::type_traits::integral_constant<bool, true>;
using false_type = geko::type_traits::integral_constant<bool, false>;

}
}

#endif

