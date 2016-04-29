/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_MAX_HPP
#define GEKO_ALGORITHM_MAX_HPP

namespace geko{
namespace algorithm{

template<class T>
inline constexpr const T&
max(const T& a,const T& b){
    return (a<b)? b :a;
}

template<class T,class Compare>
inline constexpr const T&
max(const T& a,const T& b,Compare comp){
    return (comp(a,b))? b: a;
}

}   // namespace algorithm
}   // namespace geko

    #endif
