/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_COMPLEX_HPP
#define GEKO_COMPLEX_HPP

namespace geko {

template<typename T>
struct complex {
    using value_type = T;

    // ctors
    constexpr complex(T const& real = T(), T const& image = T()) :
        m_real(real),
        m_image(image)
    {}
    constexpr complex(complex const& other) :
        m_real(other.real()),
        m_image(other.imag())
    {}
    template<typename U>
    constexpr complex(complex<U> const& other) :
        m_real(static_cast<T>(other.real())),
        m_image(static_cast<T>(other.imag()))
    {}

    // default dtor
    ~complex() = default {}

    // operators
    complex<T>& operator=(T const& rhs) {
        m_real = rhs;
        m_image = static_cast<T>(0);
        return *this;
    }
    complex<T>& operator=(complex<T> const& rhs) {
        m_real = rhs.real();
        m_image = rhs.imag();
        return *this;
    }
    complex<T>& operator+=(T const& rhs) {
        m_real += rhs;
        return *this;
    }
    template<typename U>
    complex<T>& operator+=(complex<U> const& rhs) {
        m_real += rhs.real();
        m_image += rhs.imag();
        return *this;
    }


    constexpr value_type real() const { return m_real; }
    void real(T v) { m_real = v; }

    constexpr value_type imag() const { return m_image; }
    void imag(T v) { m_image = v; }



private:
    value_type m_real;
    value_type m_image;
};

template<typename T>
constexpr 

}

#endif

