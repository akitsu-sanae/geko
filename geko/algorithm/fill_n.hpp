#ifndef GEKO_ALGORITHM_FILL_N_HPP
#define GEKO_ALGORITHM_FILL_N_HPP

namespace geko{
namespace algorithm{

template<class OutputIt,class Size,class T>
inline constexpr OutputIt
fill_n(OutputIt first,Size count,const T& value){
    while(count-- > 0){
        *first++ = value;
    }
    return first;
}

}   // namespace algorithm
}   // namespace geko

#endif
