#ifndef GEKO_ALGORITHM_COPY_N_HPP
#define GEKO_ALGORITHM_COPY_N_HPP

namespace geko{
namespace algorithm{

template<class InputIt,typename Size,typename OutputIt>
inline constexpr OutputIt
copy_n(InputIt first,Size count,OutputIt dist){
    if(count<=0)return dist;
    *dist++ = *first;
    for(Size i=static_cast<Size>(1);i<count;++i){
        *dist++ = *++first;
    }
    return dist;
}

}   // namespace algorithm
}   // namespace geko

#endif
