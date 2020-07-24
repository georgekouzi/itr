#pragma once
#include <iostream>
using namespace std;
namespace itertools
{
    class range
    {
        int first;
        int last;

    public:
        range(int f = 0, int e = 0) : first(f), last(e){};
        class iterator
        {
            int it_num;

        public:
            iterator(int f) : it_num(f){};

            auto operator*() const
            {

                return it_num;
            }
            // int const &operator*() const
            // {
            //     return it_first;
            // }
            const iterator &operator++()
            {
                it_num++;
                return *this;
            }
            const iterator operator++(int)
            {
                iterator f = *this;
                it_num++;
                return f;
            }
            bool operator!=(const iterator &other) const
            {
                return it_num != other.it_num;
            }
            bool operator==(const iterator &other) const
            {
                return it_num == other.it_num;
            }
        };
        iterator begin()
        {
            return iterator{first};
        }
        iterator end()
        {
            return iterator{last};
        }
    };
}; // namespace itertools
