/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_FUNCTIONAL_LESS_HPP
#define GEKO_FUNCTIONAL_LESS_HPP

namespace geko {
namespace functional {

template<typename T>
struct less {
    using result_type = bool;
    using first_argument_type = T;
    using second_argument_type = T;
    constexpr bool operator()(T const& lhs, T const& rhs) const {
        return lhs < rhs;
    }
};


}
}

#endif

