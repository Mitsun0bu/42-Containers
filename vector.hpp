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

			// Type of the elements stored in the vector
			typedef T			value_type;

			// Pointer to an element of the vector
			typedef value_type*	pointer;

			// Reference to an element of the vector
			typedef value_type&	reference;

			// Constant reference to an element of the vector
			typedef const T&	const_reference;

			// Type of the allocator used by the vector
			typedef Alloc		allocator_type;

			// Type used to represent the size of the vector
			typedef size_t		size_type;

			// Type used to represent the difference between two iterators of the vector
			typedef ptrdiff_t	difference_type;

			/* ********************************* */
			/*                                   */
			/*      ~~~ PRIVATE MEMBERS ~~~      */
			/*                                   */
			/* ********************************* */

			// Pointer to the memory block where the elements of the vector are stored
			pointer		_dataArray;

			// Object of the allocator type used by the vector
			Alloc		_alloc;

			// Number of elements currently stored in the vector
			size_type	_size;

			// Number of elements the vector can currently hold without having to resize its memory block
			size_type	_capacity;

		public:

			/* ************************************* */
			/*                                       */
			/*      ~~~ DEFAULT CONSTRUCTOR ~~~      */
			/*                                       */
			/* ************************************* */

			// Initializes the private members of the class
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
				// Allocate memory for '_dataArray' with '_capacity'
				_dataArray = _alloc.allocate(_capacity);

				// Construct '_dataArray' element at 'i' with value 'val'
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
				std::ptrdiff_t	inputRangeSize = std::distance(first, last);

				// Set the '_capacity' of the vector to the 'inputRangeSize'
				_capacity = inputRangeSize;

				// Allocate memory for '_dataArray' using '_capacity'
				_alloc = alloc;
				_dataArray = _alloc.allocate(_capacity);

				for(std::ptrdiff_t i = 0; i < inputRangeSize; i++)
				{
					// Construct '_dataArray' element at 'i' using the value pointed by 'first'
					_alloc.construct(_dataArray + i, *(first++));
					// Increment the '_size' of the vector
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
				// Initialize the current vector with the values of the other vector 'x'
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

					// Copy the '_size' and '_capacity' from the other vector 'x'
					_size		= x._size;
					_capacity	= x._capacity;

					// Allocate memory for '_dataArray' using '_capacity'
					_dataArray = _alloc.allocate(_capacity);

					// Construct '_dataArray' element at 'i' using 'x._dataArray[i]' from the other vector
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
				if (n == _size)
					return ;
				if (n > size())
				{
					reserve(n);
					for (size_type i = _size; i < _capacity; i ++)
						_alloc.construct(_dataArray + i, val);
					_size = _capacity;
				}
				else if (n < size())
				{
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(_dataArray + i);
				}
				_size = n;
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
				pointer	new_array;
				size_t	old_capacity = _capacity;
				try
				{
					if (n <= _capacity)
						return ;
					if (n > _capacity * 2 )
						_capacity = n;
					else
						_capacity *= 2;
					new_array = _alloc.allocate(_capacity);
					for (size_t i = 0; i < _size; i++)
					{
						_alloc.construct(new_array + i, _dataArray[i]);
						_alloc.destroy(_dataArray + i);
					}
					_alloc.deallocate(_dataArray, old_capacity);
					_dataArray = new_array;
				}
				catch(const std::bad_alloc& e)
				{
					throw;
				}
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
                if (n < 0 || n > _size)
                    throw (std::out_of_range("Vector index out of range"));

                return (_dataArray[n]);
            }

            const_reference at(size_type n) const
            {
                if (n < 0 || n > _size)
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

			template <class InputIterator>
			void	assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				ptrdiff_t size = std::distance(first, last);
				clear();
				reserve(size);
				for (ptrdiff_t i = 0; i < size; i++)
					_alloc.construct(_dataArray + i, *(first + i));
				_size = size;
			}

			void assign(size_type n, const value_type& val)
			{
				clear();
				reserve(n);
				for (size_type i = 0; i < n; ++i)
					_alloc.construct(_dataArray + i, val);

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

			template <class InputIterator>
			void insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				if (position < begin() || position > end())
					throw std::out_of_range("Invalid iterator position");
				if (first > last)
					throw std::invalid_argument("Invalid range");

				ft::vector<typename ft::iterator_traits<InputIterator>::value_type> buff;
				while (first != last)
					buff.push_back(*first++);

				difference_type	pos			= position - this->begin();
				size_type		count		= buff.size();
				size_type		new_size	= size() + count;

				reserve(new_size);
				for (size_type i = 0; i < count; i++)
					_alloc.construct(_dataArray + i, *(_dataArray + i - std::distance(first, last)));
				for (size_type i = size() + count - 1; i >= pos + count; i--)
					_dataArray[i] = _dataArray[i - count];
				try
				{
				for (size_type i = 0; i < count; i++)
					_dataArray[pos + i] = buff[i];
				}
				catch (...)
				{
					_capacity = 0;
					throw;
				}
				_size += count;
			}

			iterator insert(iterator position, const value_type& val)
			{
				difference_type pos = position - this->begin();

				if (static_cast<unsigned long>(pos) > _size || pos < 0)
					throw std::out_of_range("Invalid iterator position");

				if (_size + 1 > _capacity)
				{
					if (_capacity == 0)
						reallocDataArray(1);
					else
						reallocDataArray(_capacity * 2);
				}

				difference_type i = 0;
				for (i = _size; i > pos; i--)
					_dataArray[i] = _dataArray[i - 1];

				_dataArray[i] = val;
				++_size;

				return (begin() + pos);
			}

			void insert(iterator position, size_type n, const value_type& val)
			{
				size_t pos = position - this->begin();

				if (position < begin() || position > end())
					throw std::out_of_range("Invalid iterator position");

				if (_size == 0)
				{
					reserve(n);
					for (size_type i = 0; i < n; i++)
						push_back(val);
					return ;
				}

				reserve(_size + n);
				for (size_type i = _size; i > pos + n; i--)
				{
					_alloc.construct(_dataArray + i, *(_dataArray + i - n));
					_alloc.destroy(_dataArray + i - n);
				}
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_dataArray + pos + i, val);

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
				size_t	start	= first - this->begin();
				size_t	end		= last - this->begin();
				size_t	n		= end - start;

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

			/* *********************** */
			/*                         */
			/*      ~~~ UTILS ~~~      */
			/*                         */
			/* *********************** */

			void deleteDataArray(void)
			{
				if (_dataArray)
				{
					// Destroy all elements in '_dataArray'
					for (size_type i = 0; i < _capacity; ++i)
						_alloc.destroy(_dataArray + i);
					// Deallocate memory of '_dataArray' using '_capacity'
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

			template <class InputIterator>
			void copy( InputIterator first, InputIterator last, iterator result )
			{
				while (first!=last) {
					*result = *first;
					++result; ++first;
				}
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