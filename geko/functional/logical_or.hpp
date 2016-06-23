/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_FUNCTIONAL_LOGICAL_OR_HPP
#define GEKO_FUNCTIONAL_LOGICAL_OR_HPP

namespace geko {
namespace functional {

template<typename T>
struct logical_or {
    using first_argument_type = T;
    using second_argument_type = T;
    using result_type = bool;
    result_type constexpr operator()(T const& lhs, T const& rhs) const {
        return lhs || rhs;
    }
};

template<>
struct logical_or<void> {
    using is_transparent = void;
    template<typename T, typename U>
    constexpr auto operator()(T&& lhs, U&& rhs) const {
        return lhs || rhs;
    }
};

}
}

#endif
