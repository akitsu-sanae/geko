/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

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


    struct out_of_range {};

    reference at(size_type pos) {
        if (pos < 0 || pos > static_size)
            throw out_of_range{};
        return elems[pos];
    }
    const_reference at(size_type pos) const {
        if (pos < 0 || pos > static_size)
            throw out_of_range{};
        return elems[pos];
    }
    reference operator[](size_type pos) {
        return at(pos);
    }
    const_reference operator[](size_type pos) const {
        return at(pos);
    }

    reference front() {
        return at(static_cast<size_type>(0));
    }
    const_reference front() const {
        return at(static_cast<size_type>(0));
    }

    reference back() {
        return at(static_cast<size_type>(static_size - 1));
    }
    const_reference back() const {
        return at(static_cast<size_type>(static_size -1));
    }

    value_type* data() {
        return elems;
    }
    const value_type* data() const {
        return elems;
    }

    constexpr size_type size() const noexcept {
        return static_size;
    }

    constexpr iterator begin() noexcept {
        return iterator(elems);
    }
    constexpr const_iterator begin() const noexcept {
        return iterator(elems);
    }
    constexpr const_iterator cbegin() const noexcept {
        return iterator(elems);
    }
    constexpr iterator end() noexcept {
        return iterator(elems) + size();
    }
    constexpr const_iterator end() const noexcept {
        return iterator(elems) + size();
    }
    constexpr const_iterator cend() const noexcept {
        return iterator(elems) + size();
    }

    constexpr bool empty() const noexcept {
        return static_size == 0;
    }

    void fill(T const& value) {
        for (auto&& e : elems)
            e = value;
    }
    void swap(array& other) noexcept {
        for (size_type i=0; i<static_size; i++) {
            value_type tmp = elems[i];
            elems[i] = other.at(i);
            other.at(i) = std::move(tmp);
        }
    }

    static constexpr std::size_t static_size = N;

    value_type elems[static_size];
};

}
}



#endif
