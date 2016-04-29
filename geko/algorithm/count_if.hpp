/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_COUNT_IF_HPP
#define GEKO_ALGORITHM_COUNT_IF_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class Predicate>
inline constexpr std::size_t
count_if(InputIt first,InputIt last,Predicate pred){
    std::size_t result = 0;
    while(first!=last){
        if( pred(*first)  )result++;
        ++first;
    }
    return result;
}

}   // namespace algorithm
}   // namespace geko

#endif
