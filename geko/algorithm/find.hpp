/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_FIND_HPP
#define GEKO_ALGORITHM_FIND_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class T>
inline constexpr InputIt
find(
        InputIt first,InputIt last,
        const T& value)
{
    for(;first!=last;++first){
        if(*first==value)return first;
    }
    return last;
}

}   // namespace algorithm
}   // namespace geko

#endif
