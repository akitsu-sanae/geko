/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_STRING_HPP
#define GEKO_STRING_HPP

#include <utility>

namespace geko {
namespace string {

template<std::size_t N>
struct string {
    static constexpr std::size_t size = N;

    template<std::size_t ... I>
    constexpr string(const char* str, std::index_sequence<I ...>) :
        elems({str[I] ...})
    {}

    constexpr string(const char* str) :
        string(str, std::make_index_sequence<N>())
    {}
    char elems[N+1];
};

}
}

#endif

