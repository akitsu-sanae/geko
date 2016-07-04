/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_MEMORY_ADDRESSSOF_HPP
#define GEKO_MEMORY_ADDRESSSOF_HPP

namespace geko {
namespace memory {

template<typename T>
inline T* addressof(T& arg) {
    return reinterpret_cast<T*>(
            &const_cast<char&>(
                reinterpret_cast<const volatile char&>(arg)));
}

}
}

#endif

