/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ITERATOR_BACK_INSERT_ITERATOR_HPP
#define GEKO_ITERATOR_BACK_INSERT_ITERATOR_HPP

#include <geko/memory/addressof.hpp>
#include <geko/iterator/tags.hpp>
#include <geko/iterator/iterator.hpp>

namespace geko {
namespace iterator {

template<typename Container>
struct back_insert_iterator :
    public geko::iterator<
        geko::iterator::output_iterator_tag,
        void, void, void, void>
{
    // member type
    using containerr_type = Container;

    // ctor
    explicit back_insert_iterator(containerr_type& c) :
        container(geko::memory::addressof(c))
    {}

    // operators
    back_insert_iterator<containerr_type>& operator=(typename containerr_type::value_type const& value) {
        container->push_back(value);
        return *this;
    }
    back_insert_iterator<containerr_type>& operator=(typename containerr_type::value_type&& value) {
        container->push_back(std::move(value));
        return *this;
    }

    // for satisfy the requirement of OutputIterator
    back_insert_iterator<containerr_type>& operator*() { return *this; }
    back_insert_iterator<containerr_type>& operator++() { return *this; }
    back_insert_iterator<containerr_type>& operator++(int) { return *this; }
protected:
    container_type* container;
};

template<typename Container>
inline constexpr back_insert_iterator<Container>
back_inserter(Container& c) {
    return back_insert_iterator<Container>(c);
}

}
}

#endif

