#ifndef GEKO_ALGORITHM_COPY_HPP
#define GEKO_ALGORITHM_COPY_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class OutputIt>
inline constexpr OutputIt
copy(InputIt first,InputIt last,OutputIt dist)
{
    while(first != last){
        *dist++ = *first++;
    }
    return dist;
}

}   // namespace algorithm
}   // namespace geko
#endif
