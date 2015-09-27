#ifndef GEKO_ARRAY_HPP
#define GEKO_ARRAY_HPP

#include <cstddef>

namespace geko {
namespace array {

template<typename T, std::size_t N>
struct array {
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;
    using reference = T&;
    using const_reference = T const&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using const_pointer = T const*;

    constexpr size_type size() const noexcept {
        return static_size;
    }

    constexpr iterator begin() noexcept {
        return iterator(elems);
    }
    constexpr const_iterator begin() const noexcept {
        return iterator(elems);
    }
    constexpr iterator end() noexcept {
        return iterator(elems) + size();
    }
    constexpr const_iterator end() const noexcept {
        return iterator(elems) + size();
    }

    static constexpr std::size_t static_size = N;

    value_type elems[static_size];
};

}
}



#endif
