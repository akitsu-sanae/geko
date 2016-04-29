/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_FIND_IF_NOT_HPP
#define GEKO_ALGORITHM_FIND_IF_NOT_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class Predicate>
inline constexpr InputIt
find_if_not(InputIt first,InputIt last,Predicate pred){
    for(;first!=last;++first){
        if( !pred(*first)  )return first;
    }
    return last;
}

}   // namespace algorithm
}   // namespace geko

#endif
