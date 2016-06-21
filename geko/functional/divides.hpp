/*============================================================================
Copyright (C) 2015-2016 akitsu sanae
https://github.com/akitsu-sanae/geko
Distributed under the Boost Software License, Version 1.0. (See accompanying
file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_FUNCTIONAL_DIVIDES_HPP
#define GEKO_FUNCTIONAL_DIVIDES_HPP

namespace geko {
namespace functional {

template<typename = void>
struct divides {
    using first_argument_type = T;
    using second_argument_type = T;
    using result_type = T;
    constexpr result_type operator()(T const& lhs, T const& rhs) const {
        return lhs / rhs;
    }
};

template<>
struct divides<void> {
    using is_transparent = void;
    template<typename T, typename U>
    constexpr auto operator()(T&& lhs, U&& rhs) const {
        return lhs / rhs;
    }
};

}
}

#endif

