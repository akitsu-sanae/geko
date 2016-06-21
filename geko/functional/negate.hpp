/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_FUNCTIONAL_NEGATE_HPP
#define GEKO_FUNCTIONAL_NEGATE_HPP

namespace geko {
namespace functional {

template<typename T = void>
struct negate {
    using argument_type = T;
    using result_type = T;
    constexpr result_type operator()(T const& v) const {
        return -v;
    }
};

template<>
struct negate<void> {
    using is_transparent = void;
    template<typename T>
    constexpr auto operator()(T&& v) const {
        return -v;
    }
};

}
}

#endif

