#pragma once

#include <iostream>
#include <memory>
#include "Matrix.hpp"

namespace ft
{
	template <class T>
	class Matrix;

	template <class T>
	class Vector
	{
	private:
		typedef		T									value_type;
		typedef		T*									pointer;
		typedef		std::size_t							size_type;
		typedef		std::initializer_list<value_type>	init_list;

	private:
		pointer			_vector;
		size_type		_size;

	public:
	//Construcor and Destructor:
		Vector()
		{
			// std::cout << "Vector()" << std::endl;
			_size = 0;
			_vector = new value_type[_size];
		}

		Vector(size_type size)
		{
			// std::cout << "Vector(size_type size)" << std::endl;
			_size = size;
			_vector = new value_type[_size];
		}

		Vector(init_list data): _vector(NULL)
		{
			// std::cout << "Vector(init_list data)" << std::endl;
			*this = data;
		}

		Vector(const Vector& copy): _vector(NULL)
		{
			// std::cout << "Vector(const Vector& copy)" << std::endl;
			*this = copy;
		}

		Vector	&operator=(const Vector &copy)
		{
			// std::cout << "Vector &operator=(const Vector &copy)" << std::endl;
			if (this == &copy)
				return *this;
			delete [] _vector;
			_size = copy._size;
			_vector = new value_type[_size];
			for (size_type i = 0; i < _size; i++)
				_vector[i] = copy[i];
			return *this;
		}

		Vector	&operator=(const init_list data)
		{
			// std::cout << "Vector& operator= (const init_list data)" << std::endl;
			delete [] _vector;
			_size = data.size();
			_vector = new value_type[_size];
			size_type	s = 0;
			for (auto item : data)
				_vector[s++] = item;
			return *this;
		}

		~Vector() 
		{
			// std::cout << "~Vector()" << std::endl;
			delete [] _vector;
		}

//Help overloading from Matrix
		size_type			getSize() const { return _size; }
		pointer				getVec() const { return _vector; }
		void				setSize(size_type n) { _size = n; }
		void				setVec(pointer vec) { _vector = vec; }
		size_type			shape() const { return getSize(); }
		void				print() const { std::cout << *this << std::endl; }

//reshape
		Matrix<value_type>	reshape_vector_to_matrix(size_type row, size_type col)
		{
			if (row * col != _size)
				throw std::length_error("THROW reshape_vector_to_matrix: matrix_size != vector_size");

			Matrix<value_type>	tmp;
			pointer				tmp_point = new value_type[_size];

			tmp.setRow(row);
			tmp.setCol(col);
			for (size_type i = 0; i < _size; i++)
				tmp_point[i] = _vector[i];
			tmp.setMat(tmp_point);
			return tmp;
		}

//delete_elem
		void				delete_element(int n)
		{
			if (n < 0 || (size_type)n >= _size)
				throw std::length_error("THROW VECTOR delete_element: wrong element");
			
			pointer	tmp = new value_type[_size - 1];
			for (size_type i = 0, j = 0; i < _size; i++)
			{
				if (i == (size_type)n)
					continue ;
				tmp[j++] = _vector[i];
			}
			delete [] _vector;
			_vector = tmp;
			_size--;
		}

//overload
		value_type			&operator[](size_type n) { return _vector[n]; }
		const value_type	&operator[](size_type n) const { return _vector[n]; }

//ex00
		Vector	&add(const Vector<value_type> &vec)
		{
			if (_size != vec.getSize())
				throw std::length_error("THROW VECTOR add: wrong size");

			for (size_type i = 0; i < _size; i++)
				(*this)[i] += vec[i];
			return *this;
		}

		Vector	operator+(const Vector<value_type> &vec) const
		{ 
			Vector	tmp(*this);
			return	tmp.add(vec);
		}

		Vector	&operator+=(const Vector<value_type> &vec) { return add(vec); }

		Vector	&sub(const Vector<value_type> &vec)
		{
			if (_size != vec.getSize())
				throw std::length_error("THROW VECTOR sub: wrong size");

			for (size_type i = 0; i < _size; i++)
				(*this)[i] -= vec[i];
			return *this;
		}

		Vector	operator-(const Vector<value_type> &vec) const
		{ 
			Vector	tmp(*this);
			return	tmp.sub(vec);
		}

		Vector	&operator-=(const Vector<value_type> &vec) { return sub(vec); }

		Vector	&scl(const value_type &a)
		{
			for (size_type i = 0; i < _size; i++)
				(*this)[i] *= a;
			return *this;
		}

		Vector	operator*(const value_type &a) const
		{ 
			Vector	tmp(*this);
			return	tmp.scl(a);
		}

		Vector	&operator*=(const value_type &a) { return scl(a); }

	};

	template<class T>
	Vector<T> operator*(const T &a, const Vector<T> &vec) { return vec * a; }

//Print
	template<class T>
	std::ostream& operator<<(std::ostream& os, const ft::Vector<T> &vec)
	{
		size_t i = 0;
		for (; i < vec.getSize(); i++) 
		{
			os << "\t[";
			os << vec[i];
			os << "]";
			if (i != vec.getSize() - 1)
				os << std::endl;
		}
		if (i == 0)
			os << "\t[]";
		return os;
	}

//ex01
	template<class T>
	Vector<T> linear_combination(const Matrix<T> &mat, const std::initializer_list<T> &vec_list)
	{
		Vector<T>	vec(vec_list);
		return linear_combination(mat, vec);
	}

	template<class T> 
	Vector<T> linear_combination(const std::initializer_list<Vector<T>> &mat_list, const std::initializer_list<T> &vec_list)
	{
		Matrix<T>	mat(mat_list);
		Vector<T>	vec(vec_list);
		return linear_combination(mat, vec);
	}

	template<class T> 
	Vector<T> linear_combination(const Matrix<T> &mat, const Vector<T> &vec)
	{
		if (mat.getRow() != vec.getSize())
			throw std::length_error("THROW linear_combination: mat.getRow() != vec.getSize()");

		Vector<T>	tmp(mat.getCol());
		for (size_t c = 0; c < tmp.getSize(); c++)
			tmp[c] = 0;
		for (size_t r = 0; r < mat.getRow(); r++)
			for (size_t c = 0; c < mat.getCol(); c++)
				tmp[c] += mat[r * mat.getCol() + c] * vec[r];
		return tmp;
	}
}