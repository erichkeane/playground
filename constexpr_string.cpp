// early demo implementation of the const_expr_string class
#include <iostream>
#include <stdexcept>
#include <limits>
#include <type_traits>

namespace const_expr_string
{
template<typename CharT>
class const_expr_string
{
    public:
        using value_type = CharT;
        using traits_type = std::char_traits<value_type>;
        using size_type = size_t;
        using difference_type = std::ptrdiff_t;

        using const_pointer = const CharT*;
        using pointer = const_pointer;

        using const_reference = const CharT&;
        using reference = const_reference;

        using const_iterator = const CharT*;
        using iterator = const_iterator;

        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
        using reverse_iterator = const_reverse_iterator;

        static constexpr size_type npos = size_type(-1);

        constexpr const_expr_string(const_pointer data) noexcept : _data(data){}
        constexpr const_expr_string(const_expr_string& other) noexcept : _data(other.data){}

        constexpr size_t length() const noexcept
        {
            return calc_len(_data);
        }

        constexpr size_t size() const noexcept
        {
            return length();
        }

        constexpr const_iterator begin() const noexcept
        {
            return std::begin(_data);
        }

        constexpr const_iterator cbegin() const noexcept
        {
            return begin();
        }

        constexpr const_iterator end() const noexcept
        {
            return _data + size();
        }

        constexpr const_iterator cend() const noexcept
        {
            return end();
        }

        constexpr const_reverse_iterator rbegin() const noexcept
        {
            return const_reverse_iterator(end());
        }

        constexpr const_reverse_iterator crbegin() const noexcept
        {
            return rbegin();
        }

        constexpr const_reverse_iterator rend() const noexcept
        {
            return const_reverse_iterator(begin());
        }

        constexpr const_reverse_iterator crend() const noexcept
        {
            return rend();
        }

        constexpr const_reference operator[](size_type pos) const
        {
            return _data[pos];
        }

        constexpr const_reference at(size_type pos) const
        {
            return pos >= size() ?
                throw std::out_of_range("call to at with too large index") :
                operator[](pos);
        }

        constexpr const_reference front() const
        {
            return operator[](0);
        }

        constexpr const_reference back() const
        {
            return operator[](size() - 1);
        }

        constexpr const_pointer data() const noexcept
        {
            return _data;
        }

        // Not sure what this is supposed to be.  It seems that this class could easily handle
        // anything that the OS could, but the string_view component of this would be odd
        constexpr size_type max_size() const noexcept
        {
            return std::numeric_limits<size_type>::max();
        }

        constexpr bool empty() const noexcept
        {
            return _data[0] == '\0';
        }

        constexpr void swap(const_expr_string& v)
        {
            std::swap(_data, v._data);
        }

        constexpr operator const_pointer() const
        {
            return _data;
        }

        constexpr int compare (const_expr_string v) const
        {
            if (size() < v.size()) return -1;
            if (size() > v.size()) return 1;

            return traits_type::compare(_data, v._data, size());
        }

        constexpr int compare(size_type pos1, size_type count1, const_expr_string v) const;
        constexpr int compare(size_type pos1, size_type count1, const_expr_string v) const;

        constexpr int compare(const_pointer md) const
        {
            constexpr const_expr_string rhs(md);
            return compare(rhs);
        }


        //constexpr int compare(size_type pos1, size_type count1, const_pointer md) const
        //{
            // TODO
        //}

        /*constexpr size_type find(const_expr_string v, size_type pos = 0) const
        {
            // TODO
        }*/

        constexpr size_type find(value_type v, size_type pos = 0) const
        {
            // TODO
            for(; pos < size(); ++pos)
            {
                if (_data[pos] == v)
                    return pos;
            }

            return npos;
        }

        /*constexpr size_type find(const_pointer v, size_type pos, size_type count) const
        {
            // TODO
        }*/

        /*constexpr size_type find(const_pointer v, size_type pos = 0) const
        {
        }*/


    private:
        static constexpr size_type calc_len(const_pointer t)
        {
    //return t[0] == '\0' ? 0 : 1 + my_strlen(t + 1);
            size_type i = 0;
            while(t[i] != '\0') ++i;
            return i;
        }

    const_pointer _data;
};

template<typename CharT>
constexpr bool operator==(const_expr_string<CharT> lhs, const_expr_string<CharT> rhs)
{
    return lhs.compare(rhs) == 0;
}

template<typename CharT>
constexpr bool operator!=(const_expr_string<CharT> lhs, const_expr_string<CharT> rhs)
{
    return !(lhs == rhs);
}

template<typename CharT>
constexpr bool operator < (const_expr_string<CharT> lhs, const_expr_string<CharT> rhs)
{
    return lhs.compare(rhs) < 0;
}

template<typename CharT>
constexpr bool operator <= (const_expr_string<CharT> lhs, const_expr_string<CharT> rhs)
{
    return lhs.compare(rhs) <= 0;
}

template<typename CharT>
constexpr bool operator > (const_expr_string<CharT> lhs, const_expr_string<CharT> rhs)
{
    return lhs.compare(rhs) > 0;
}

template<typename CharT>
constexpr bool operator >= (const_expr_string<CharT> lhs, const_expr_string<CharT> rhs)
{
    return lhs.compare(rhs) >= 0;
}

template <typename CharT, typename Traits>
std::basic_ostream<CharT, Traits&> operator << (std::basic_ostream<CharT, Traits>& os,
    const_expr_string<CharT> v)
{
    return os << v;
}

} // namespace const_expr_string

