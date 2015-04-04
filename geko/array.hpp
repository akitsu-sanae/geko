#ifndef GEKO_ARRAY_HPP
#define GEKO_ARRAY_HPP

#include <type_traits>

#include "algorithm/copy.hpp"

namespace geko{

template<class T,std::size_t N>
class array{
public:
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;

    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    // TODO: add reverse_iterator and const_reverse_iterator
public:
    static constexpr size_type static_size = N;
private:
    value_type m_values[static_size?static_size : 1];
public:
    template<typename T2>
    constexpr array&
    operator=(const array<T2,N>& rhs){
        geko::algorithm::copy(rhs.begin(),rhs.end(),begin());
        return *this;
    }
    template<typename T2>
    constexpr array&
    operator=(array<T2,N>&& rhs){
        // TODO: use geko::algorithm::move inpace of copy
        geko::algorithm::copy(rhs.begin(),rhs.end(),begin());
        return *this;
    }
    // TODO: add fill(),assign(),swap()
public:
    constexpr iterator
    begin()noexcept{
        return m_values;
    }
    constexpr const_iterator
    begin()const noexcept{
        return m_values;
    }
    constexpr iterator
    end()noexcept{
        return m_values + size();
    }
    constexpr const_iterator
    end()const noexcept{
        return m_values + size();
    }
    // TODO: add rbegin(), rend(), cbegin(),cend(), crbegin(), crend()
public:
    constexpr size_type size()const noexcept{ return static_size;  }
    constexpr size_type max_size()const noexcept{ return size();  }
    constexpr bool empty()const noexcept{ return size() == 0;  }
public:
    constexpr reference operator[](size_type i){ return m_values[i];  }
    constexpr const_reference operator[](size_type i)const{ return m_values[i];  }
};

template<typename T,std::size_t N>
constexpr typename geko::array<T,N>::size_type geko::array<T,N>::static_size;


}   // namespace geko

#endif
