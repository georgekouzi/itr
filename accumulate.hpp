#pragma once

using namespace std;
namespace itertools
{

    class sum
    {
    public:
        template <typename T>
        T operator()(T a, T b)
        {
            return a + b;
        }
    };

    template <typename T, typename function = sum>
    class accumulate
    {
        T container;
        decltype((container.begin())) first;
        decltype((container.begin())) last;
        function _f;

    public:
        accumulate(T contain, function f = sum()) : container(contain), _f(f), first(container.begin()), last(container.end()){};
        class iterator
        {
            decltype((container.begin())) first_index;
            decltype((container.begin())) last_index;

            decltype(*(container.begin())) resulte;
            function _f;

        public:
            iterator(decltype((container.begin())) it, decltype((container.begin())) ite, function f) : first_index(it), last_index(ite), _f(f), resulte(*it){};

            auto operator*() const
            {
                return resulte;
            }

            const iterator &operator++()
            {
                ++first_index;
                if (first_index != last_index)
                {
                    resulte = _f(resulte, *first_index);
                }
                return *this;
            }
            const iterator operator++(int)
            {
                iterator f = *this;
                ++first_index;
                resulte = _f(resulte, *first_index);
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
