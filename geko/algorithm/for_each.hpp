#ifndef GEKO_ALGORITHM_FOR_EACH_HPP
#define GEKO_ALGORITHM_FOR_EACH_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class Function>
inline constexpr Function for_each(
        InputIt first,InputIt last,
        Function f
        )
{
    for(;first != last;++first){
        f(*first);
    }
    return f;
}

}   // namespace algorithm
}   // namespace geko

#endif
