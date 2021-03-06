/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_UTILITY_FORWARD_HPP
#define GEKO_UTILITY_FORWARD_HPP

namespace geko {
namespace utility {

template<typename T, typename U>
inline T&&
forward(U&& u) noexcept {
    return static_cast<T&&>(u);
}

}
}

#endif

