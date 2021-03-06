/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_FILL_HPP
#define GEKO_ALGORITHM_FILL_HPP

namespace geko{
namespace algorithm{

template<class ForwardIt,class T>
inline constexpr void
fill(ForwardIt first,ForwardIt last,const T& value){
    while(first!=last){
        *first++ = value;
    }
}

}   // namespace algorithm
}   // namespace geko

#endif
