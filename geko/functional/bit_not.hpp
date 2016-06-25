/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_FUNCTIONAL_BIT_NOT_HPP
#define GEKO_FUNCTIONAL_BIT_NOT_HPP

namespace geko {
namespace functional {

template<typename T = void>
struct bit_not {
    using argument_type = T;
    using result_type = T;
    constexpr result_type operator()(T const& v) const {
        return ~v;
    }
};

template<>
struct bit_not<void> {
    using is_transparent = void;
    template<typename T, typename U>
    constexpr auto operator()(T&& v) const {
        return ~std::forward<T>(v);
    }
};

}
}

#endif

