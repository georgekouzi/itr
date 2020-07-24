#pragma once
#include <iostream>
#include <vector>

using namespace std;
namespace itertools
{
    template <typename T1, typename T2>
    class compress
    {
        T1 container1;
        T2 container2;

        decltype((container1.begin())) first_container1;
        decltype((container1.begin())) last_container1;
        decltype((container2.begin())) first_container2;
        decltype((container2.begin())) last_container2;

    public:
        compress(T1 contain1, T2 contain2) : container1(contain1), container2(contain2), first_container1(container1.begin()), last_container1(container1.end()), first_container2(container2.begin()), last_container2(container2.end()){};

        class iterator
        {
            decltype((container1.begin())) &first_index_it1;
            decltype((container1.end())) &end_index_it1;
            decltype((container2.begin())) &first_index_it2;
            decltype((container2.end())) &end_index_it2;

            decltype(*(container1.begin())) resulte;

        public:
            iterator(decltype((container1.begin())) &fit1, decltype(container1.begin()) &eit1, decltype((container2.begin())) &fit2, decltype((container2.begin())) &eit2) : first_index_it1(fit1), end_index_it1(eit1), first_index_it2(fit2), end_index_it2(eit2), resulte(ifTrue()){};

            decltype(*(first_index_it1)) ifTrue()
            {
                for (; (first_index_it1 != end_index_it1) && (first_index_it2 != end_index_it2) && !(*first_index_it2); ++first_index_it2, ++first_index_it1)
                {
                }
                return (*first_index_it1);
            }

            auto &operator*() const
            {
                return resulte;
            }

            const iterator &operator++()
            {
                ++first_index_it2;
                ++first_index_it1;
                resulte = ifTrue();
                return *this;
            }
            const iterator operator++(int)
            {
                iterator f = *this;
                ++first_index_it2;
                ++first_index_it1;
                resulte = ifTrue();
                return f;
            }
            bool operator!=(const iterator &other) const
            {
                return first_index_it1 != other.first_index_it1;
            }
            bool operator==(const iterator &other) const
            {
                return first_index_it1 == other.first_index_it1;
            }
        };

        iterator begin()
        {
            return iterator(first_container1, last_container1, first_container2, last_container2);
        }
        iterator end()
        {
            return iterator(last_container1, last_container1, last_container2, last_container2);
        }
    };
}; // namespace itertools
