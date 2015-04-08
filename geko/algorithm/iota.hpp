#ifndef GEKO_ALGORITHM_IOTA_HPP
#define GEKO_ALGORITHM_IOTA_HPP

namespace geko{
namespace algorithm{

template<class ForwardIt,class T>
void iota(ForwardIt first,ForwardIt last,T value){
    while(first!=last){
        *first++ = value;
        ++value;
    }
}

}   // namespace algorithm
}   // namespace geko

#endif
