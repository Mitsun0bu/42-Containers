#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/lexicographical_compare.hpp"
# include "iterators/iterator.hpp"
# include "iterators/const_iterator.hpp"
# include "iterators/reverse_iterator.hpp"
# include "iterators/iterator_traits.hpp"

namespace ft
{
    /* ************************************************************************** */
    /*                                                                            */
    /*                      ~~~ VECTOR CLASS DEFINITION ~~~                       */
    /*                                                                            */
    /* ************************************************************************** */

    template < typename T, typename Alloc = std::allocator<T> >
    class vector
    {
        private:

            /* ****************************** */
            /*                                */
            /*        ~~~ TYPEDEFS ~~~        */
            /*                                */
            /* ****************************** */

            typedef T           value_type;
            typedef value_type* pointer;
            typedef value_type& reference;
            typedef const T&    const_reference;
            typedef Alloc       allocator_type;
            typedef size_t      size_type;

            /* ********************************* */
            /*                                   */
            /*      ~~~ PRIVATE MEMBERS ~~~      */
            /*                                   */
            /* ********************************* */

            pointer             _dataArray;
            Alloc               _alloc;
            size_type           _size;
            size_type           _capacity;

        public:

            /* ************************************* */
            /*                                       */
            /*      ~~~ DEFAULT CONSTRUCTOR ~~~      */
            /*                                       */
            /* ************************************* */

            explicit vector(const allocator_type& alloc = allocator_type())
                : _dataArray(NULL), _alloc(alloc), _size(0), _capacity(0)
            {
                return ;
            }

            /* ********************************** */
            /*                                    */
            /*      ~~~ FILL CONSTRUCTOR ~~~      */
            /*                                    */
            /* ********************************** */

            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
                : _alloc(alloc), _size(n), _capacity(n)
            {
                _dataArray = _alloc.allocate(_capacity);
                for(size_t i = 0; i < _size; i++)
                    _alloc.construct(_dataArray + i, val);
            }

            /* *********************************** */
            /*                                     */
            /*      ~~~ RANGE CONSTRUCTOR ~~~      */
            /*                                     */
            /* *********************************** */

            template <class InputIterator>
            vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type())
                : _size(0)
            {
                std::ptrdiff_t	size = std::distance(first, last);

                _capacity = size;
                _dataArray = _alloc.allocate(size);
                _alloc = alloc;

                for(std::ptrdiff_t i = 0; i < size; i++)
                {
                    _alloc.construct(_dataArray + i, *(first++));
                    _size++;
                }
            }

            /* ********************************** */
            /*                                    */
            /*      ~~~ COPY CONSTRUCTOR ~~~      */
            /*                                    */
            /* ********************************** */

            vector(const vector<T, Alloc>& x)
                : _dataArray(NULL), _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
            {
                *this = x;
                return ;
            }

            /* **************************** */
            /*                              */
            /*      ~~~ DESTRUCTOR ~~~      */
            /*                              */
            /* **************************** */

            ~vector()
            {
                if (_dataArray)
                    deleteDataArray();
            }

            /* ********************************************** */
            /*                                                */
            /*      ~~~ ASSIGNMENT OPERATOR OVERLOAD ~~~      */
            /*                                                */
            /* ********************************************** */

            vector& operator=(const vector& x)
            {
                // Check for self-assignment
                if (this != &x)
                {
                    // Deallocate the current elements
                    deleteDataArray();

                    // Copy the size and capacity from the other vector
                    _size       = x._size;
                    _capacity   = x._capacity;

                    // Allocate memory for the new elements
                    _dataArray = _alloc.allocate(_capacity);

                    // Copy the elements from the other vector
                    for(size_t i = 0; i < _size; i++)
                        _alloc.construct(_dataArray + i, x._dataArray[i]);
                }
                return (*this);
            }

            /* *************************** */
            /*                             */
            /*      ~~~ ITERATORS ~~~      */
            /*                             */
            /* *************************** */

            friend class                            Iterator< vector<T> >;
            friend class                            Reverse_iterator< vector<T> >;
            friend class                            Const_iterator< vector<T> >;

            typedef Iterator< vector<T> >           iterator;
            typedef Reverse_iterator< vector<T> >   reverse_iterator;
            typedef Const_iterator< vector<T> >     const_iterator;

            iterator begin()
            {
                return (iterator(_dataArray));
            }

            const_iterator begin() const
            {
                return (const_iterator(_dataArray));
            }

            iterator end()
            {
                return (iterator(_dataArray + _size));
            }

            const_iterator end() const
            {
                return (const_iterator(_dataArray + _size));
            }

            const_iterator cbegin() const
            {
                return (const_iterator(_dataArray));
            }

            const_iterator cend() const
            {
                return (const_iterator(_dataArray + _size));
            }

            reverse_iterator rbegin()
            {
                return (reverse_iterator(_dataArray));
            }

            reverse_iterator rend()
            {
                return (reverse_iterator(_dataArray + _size));
            }

            /* ************************** */
            /*                            */
            /*      ~~~ CAPACITY ~~~      */
            /*                            */
            /* ************************** */

            size_t size(void) const
            {
                return (_size);
            }

            size_t max_size(void) const
            {
                return (_alloc.max_size());
            }

            void resize(size_type n, value_type val = value_type())
            {
                // size_t old_size = _size;

                // _size = n;
                // reallocDataArray(n);

                // if (n > old_size)
                //     for (size_type i = old_size; i < n; ++i)
                //         _dataArray[i] = val;

                if (n < _size)
                {
                    pointer newDataArray = _alloc.allocate(n);
                    for (size_t i = 0; i < n; i++)
                        _alloc.construct(newDataArray + i);
                    for (size_t i = 0; i < n; i++)
                        newDataArray[i] = _dataArray[i];
                    deleteDataArray();
                    _size = n;
                    _dataArray  = newDataArray;
                }
                else if (n > _size && n < _capacity)
                {
                    pointer newDataArray = _alloc.allocate(n);
                    for (size_t i = 0; i < n; i++)
                        _alloc.construct(newDataArray + i);
                    size_t i = 0;
                    for (; i < _size; i++)
                        newDataArray[i] = _dataArray[i];
                    for (; i < n; i ++)
                        newDataArray[i] = val;
                    deleteDataArray();
                    _size = n;
                    _dataArray  = newDataArray;
                }
                else if (n > _size && n > _capacity)
                {
                    pointer newDataArray = _alloc.allocate(n);
                    for (size_t i = 0; i < n; i++)
                        _alloc.construct(newDataArray + i);
                    size_t i = 0;
                    for (; i < _size; i++)
                        newDataArray[i] = _dataArray[i];
                    for (; i < n; i ++)
                        newDataArray[i] = val;
                    deleteDataArray();
                    _size = n;
                    _capacity = n;
                    _dataArray  = newDataArray;
                }
                return ;
            }

            size_t capacity(void) const
            {
                return (_capacity);
            }

            bool empty(void) const
            {
                if (_size == 0)
                    return (true);
                else
                    return (false);
            }

            void reserve(size_type n)
            {
                if (n > max_size())
                    throw (std::bad_alloc());

                if (_capacity < n)
                {
                    pointer newDataArray = _alloc.allocate(n);

                    for (size_t i = 0; i < n; i++)
                        _alloc.construct(newDataArray + i);

                    for (size_t i = 0; i < _size; i++)
                        newDataArray[i] = _dataArray[i];

                    deleteDataArray();

                    _capacity   = n;
                    _dataArray  = newDataArray;
                }

                return ;
            }

            void shrink_to_fit(void)
            {
                _capacity = _size;
                reallocDataArray(_capacity);
                return ;
            }

            /* ******************************** */
            /*                                  */
            /*      ~~~ ELEMENT ACCESS ~~~      */
            /*                                  */
            /* ******************************** */

            reference operator[](size_type n)
            {
                return (_dataArray[n]);
            }

            const_reference operator[](size_type n) const
            {
                return (_dataArray[n]);
            }

            reference at(size_type n)
            {
                if (n < 0 || n >= _size)
                    throw (std::out_of_range("Vector index out of range"));

                return (_dataArray[n]);
            }

            const_reference at(size_type n) const
            {
                if (n < 0 || n >= _size)
                    throw (std::out_of_range("Vector index out of range"));

                return (_dataArray[n]);
            }

            reference front(void)
            {
                return (_dataArray[0]);
            }

            const_reference front(void) const
            {
                return (_dataArray[0]);
            }

            reference back(void)
            {
                return (_dataArray[_size - 1]);
            }

            const_reference back(void) const
            {
                return (_dataArray[_size - 1]);
            }

            value_type* data(void)
            {
                return (&_dataArray[0]);
            }

            const value_type* data(void) const
            {
                return (&_dataArray[0]);
            }

            /* ************************** */
            /*                            */
            /*      ~~~ MODIFIERS ~~~     */
            /*                            */
            /* ************************** */

            // template <class InputIterator> void     assign (InputIterator first, InputIterator last);
            // template <class InputIterator> void     insert (iterator position, InputIterator first, InputIterator last);

            void assign(size_type n, const value_type& val)
            {
                clear();
                reserve(n);
                for (size_type i = 0; i < n; ++i)
                    _dataArray[i] = val;

                _size = n;

                return;
            }

            void push_back(const value_type& val)
            {
                if (_size == 0)
                    reallocDataArray(1);

                else if (_size == _capacity)
                    reallocDataArray(_capacity * 2);

                _dataArray[_size] = val;
                _size ++;

                return ;
            }

            void pop_back(void)
            {
                if (_size == 0)
                    return ;

                _alloc.destroy(_dataArray + _size);

                _size --;

                return ;
            }

            iterator insert(iterator position, const value_type& val)
            {
                size_t pos = position - this->begin();

                if (_size + 1 > _capacity)
                {
                    if (_capacity == 0)
                        reallocDataArray(1);
                    else
                        reallocDataArray(_capacity * 2);
                }

                size_t i = _size;
                for (; i != pos; i --)
                    _dataArray[i] = _dataArray[i - 1];

                _dataArray[i] = val;
                ++_size;

                return (position);
            }

            void insert(iterator position, size_type n, const value_type& val)
            {
                size_t pos = position - this->begin();

                if (_size + n > _capacity)
                    reallocDataArray(_capacity + n);

                for (size_t i = _size + n - 1; i != pos + n; i--)
                    _dataArray[i] = _dataArray[i - n];

                for (size_t i = pos; i < pos + n; i++)
                    _dataArray[i] = val;

                _size += n;
            }

            iterator erase(iterator position)
            {
                size_t pos = position - this->begin();

                _alloc.destroy(_dataArray + pos);

                for (size_t i = pos; i < _size - 1; i++)
                    _dataArray[i] = _dataArray[i + 1];

                --_size;

                return (this->begin() + pos);
            }

            iterator erase(iterator first, iterator last)
            {
                size_t  start    = first - this->begin();
                size_t  end      = last - this->begin();
                size_t  n        = end - start;

                for (size_t i = end; i < _size; i++)
                    _dataArray[i - n] = _dataArray[i];

                for (size_t i = _size - n; i < _size; i++)
                    _alloc.destroy(_dataArray + i);

                _size -= n;

                return (first);
            }

            void swap(vector& x)
            {
                std::swap(_size, x._size);
                std::swap(_capacity, x._capacity);
                std::swap(_dataArray, x._dataArray);
                std::swap(_alloc, x._alloc);

                return ;
            }

            void clear()
            {
                for (size_t i = 0; i < _size; ++i)
                    _alloc.destroy(&_dataArray[i]);

                _size = 0;

                return ;
            }

            /* ************************************** */
            /*                                        */
            /*      ~~~ RELATIONAL OPERATORS ~~~      */
            /*                                        */
            /* ************************************** */

            // bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            // {

            // }
            // bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            // {

            // }
            // bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            // {

            // }
            // bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            // {

            // }
            // bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            // {

            // }
            // bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
            // {

            // }

            /* *********************** */
            /*                         */
            /*      ~~~ UTILS ~~~      */
            /*                         */
            /* *********************** */

            void deleteDataArray(void)
            {
                if (_dataArray)
                {
                    for (size_type i = 0; i < _capacity; ++i)
                        _alloc.destroy(_dataArray + i);
                    _alloc.deallocate(_dataArray, _capacity);
                }
                return ;
            }

            void reallocDataArray(size_type newCapacity)
            {
                if (newCapacity < _capacity)
                    return ;

                _capacity = newCapacity;

                pointer newDataArray = _alloc.allocate(newCapacity);

                for (size_t i = 0; i < _capacity; i++)
                    _alloc.construct(newDataArray + i);

                for (size_t i = 0; i < _size; i++)
                    newDataArray[i] = _dataArray[i];

                deleteDataArray();

                _dataArray  = newDataArray;
            }
    };

            /* ************************************** */
            /*                                        */
            /*      ~~~ RELATIONAL OPERATORS ~~~      */
            /*                                        */
            /* ************************************** */


            template <class T, class Alloc>
            bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
            {
                size_t size;

                size = lhs.size();
                if(lhs.size() != rhs.size())
                    return (false);
                else
                {
                    for(size_t i = 0; i < size; i++)
                    {
                        if(*(lhs.begin() + i) != *(rhs.begin() + i))
                            return (false);
                    }
                }
                return (true);
            }

            template <class T, class Alloc>
            bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
            {
                if (lhs == rhs)
                    return (false);
                return (true);
            }

            template <class T, class Alloc>
            bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
            {
                return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
            }

            template <class T, class Alloc>
            bool operator> (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
            {
                return(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
            }

            template <class T, class Alloc>
            bool operator<=  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
            {
                if (lhs < rhs || lhs == rhs)
                    return (true);
                return (false);
            }

            template <class T, class Alloc>
            bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
            {
                if (lhs > rhs || lhs == rhs)
                    return (true);
                return (false);
            }

}

# endif