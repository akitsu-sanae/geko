/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_FUNCTIONAL_NOT_EQUAL_TO_HPP
#define GEKO_FUNCTIONAL_NOT_EQUAL_TO_HPP

namespace geko {
namespace functional {

template<typename T = void>
struct not_equal_to {
    using first_arument_type = T;
    using second_arugment_type = T;
    using result_type = bool;
    constexpr result_type operator()(T const& lhs, T const& rhs) const {
        return lhs != rhs;
    }
};

template<>
struct equal_to<void> {
    using is_transparent = void;
    template<typename T, typename U>
    auto operator()(T&& lhs, U&& rhs) const {
        return lhs != rhs;
    }
};

}
}

#endif

