#pragma once
#include <iostream>
#include <vector>

using namespace std;
namespace itertools
{
    template <typename T, typename function>
    class filterfalse
    {
        T container;
        decltype((container.begin())) first;
        decltype((container.begin())) last;
        function _f;

    public:
        filterfalse(function f, T contain) : container(contain), _f(f), first(container.begin()), last(container.end()){};

        class iterator
        {
            decltype((container.begin())) &first_index;
            decltype((container.end())) &end_index;
            decltype(*(container.begin())) resulte;
            function _f;

        public:
            iterator(decltype((container.begin())) &itb, decltype(container.begin()) &ite, function f) : first_index(itb), end_index(ite), _f(f), resulte(ifFalse()){};

            decltype(*(first_index)) ifFalse()
            {

                for (; first_index != end_index && _f(*first_index); ++first_index)
                {
                }
                return (*first_index);
            }

            auto &operator*() const
            {
                return resulte;
            }

            const iterator &operator++()
            {
                ++first_index;
                resulte = ifFalse();
                return *this;
            }
            const iterator operator++(int)
            {
                iterator f = *this;
                ++first_index;
                resulte = ifFalse();
                return f;
            }
            bool operator!=(const iterator &other) const
            {
                return first_index != other.first_index;
            }
            bool operator==(const iterator &other) const
            {
                return first_index == other.first_index;
            }
        };

        iterator begin()
        {
            return iterator(first, last, _f);
        }
        iterator end()
        {
            return iterator(last, last, _f);
        }
    };
}; // namespace itertools
