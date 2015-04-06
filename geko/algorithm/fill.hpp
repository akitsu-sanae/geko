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
