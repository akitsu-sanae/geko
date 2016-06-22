/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_FUNCTIONAL_NEGATORS_HPP
#define GEKO_FUNCTIONAL_NEGATORS_HPP

namespace geko {
namespace functional {

template<typename Pred>
struct unary_negate {
    using argument_type = typename Pred::argument_type;
    using result_type = bool;
    explicit constexpr unary_negate(Pred const&& pred) :
        pred(pred)
    {}
    constexpr result_type operator()(argument_type const& v) const {
        return !pred(v);
    }
    Pred const& pred;
};

template<typename Pred>
constexpr unary_negate<Pred> not1(Pred const& pred) {
    return unary_negate<Pred>(pred);
}

template<typename Pred>
struct binary_negate {
    using first_argument_type = typename Pred::first_argument_type;
    using second_argument_type = typename Pred::second_argument_type;
    explicit constexpr binary_negate(Pred const& pred) :
        pred(pred)
    {}
    constexpr result_type operator()(first_argument_type const& lhs, second_argument_type const& rhs) const {
        return !pred(lhs, rhs);
    }
    Pred const& pred;
};

template<typename Pred>
constexpr binary_negate<Pred> not2(Pred const& pred) {
    return binary_negate<Pred>(pred);
}

}
}

#endif

