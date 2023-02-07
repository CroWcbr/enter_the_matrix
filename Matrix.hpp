#pragma once

#include <iostream>
#include <memory>
#include "Vector.hpp"

namespace ft
{
	template <class T>
	class Vector;

	template <class T>
	class Matrix
	{
	private:
		typedef		T															value_type;
		typedef		T*															pointer;
		typedef		std::size_t													size_type;
		typedef		std::initializer_list<std::initializer_list<value_type>>	init_list;
		typedef		std::pair<size_type, size_type>								pair_shape;

	private:
		pointer			_matrix;
		size_type		_row;
		size_type		_col;

	private:
		void	check_init_matrix_col(init_list data)
		{
			for (auto row : data)
				if (_col !=  row.size())
					throw std::length_error("THROW MATRIX : wrong matrix size");
		}

	public:
	//Construcor and Destructor:
		Matrix()
		{
			std::cout << "Matrix()" << std::endl;
			_row = 0;
			_col = 0;
			_matrix = new value_type[_row * _col];
		}

		Matrix(size_type row, size_type col)
		{
			std::cout << "Matrix(size_type row, size_type col)" << std::endl;
			_row = row;
			_col = col;
			_matrix = new value_type[_row * _col];
		}

		Matrix(init_list data): _matrix(NULL)
		{
			std::cout << "Matrix(init_list data)" << std::endl;
			*this = data;
		}

		Matrix(const Matrix& copy): _matrix(NULL)
		{
			std::cout << "Matrix(const Matrix& copy)" << std::endl;
			*this = copy;
		}

		Matrix	&operator=(const Matrix &copy)
		{
			std::cout << "Matrix &operator=(const Matrix& copy)" << std::endl;
			if (this == &copy)
				return *this;
			delete [] _matrix;
			_row = copy._row;
			_col = copy._col;
			_matrix = new value_type[_row * _col];
			for (size_type i = 0; i < _row * _col; i++)
				_matrix[i] = copy[i];
			return *this;
		}

		Matrix	&operator=(const init_list data)
		{		
			std::cout << "Matrix& operator= (const init_list init)" << std::endl;
			delete [] _matrix;
			_row = data.size();
			_col = data.begin()->size();
			check_init_matrix_col(data);
			_matrix = new value_type[_row * _col];
			size_type	r = 0;
			for (auto row : data)
			{
				size_type c = 0;
				for (auto item : row) 
					_matrix[r * _col + c++] = item;
				r++;
			}
			return *this;
		}

		~Matrix() 
		{	
			std::cout << "~Matrix()" << std::endl;
			delete [] _matrix; 
		}

//Help
		size_type			getRow() const { return _row; }
		size_type			getCol() const { return _col; }
		pointer				getMat() const { return _matrix; }
		void				setRow(size_type n) { _row = n; }
		void				setCol(size_type n) { _col = n; }
		void				setMat(pointer mat) { _matrix = mat; }
		pair_shape			shape() const { return std::make_pair(getRow(), getCol() ); }
		bool				is_square() const { return (getRow() == getCol()); }
		void				print() const { std::cout << *this << std::endl; }

//reshape
		Vector<value_type>	reshape_matrix_to_vector()
		{
			Vector<value_type>	tmp;
			pointer				tmp_point = new value_type[_row * _col];

			tmp.setSize(_row * _col);
			for (size_type i = 0; i < _row * _col; i++)
				tmp_point[i] = _matrix[i];
			tmp.setVec(tmp_point);
			return tmp;
		}

//delete_elem
		void				delete_row(int n)
		{
			if (n < 0 || (size_type)n >= _row)
				throw std::length_error("THROW MATRIX delete_row: wrong element");
			
			pointer	tmp = new value_type[_row * _col - _row];
			for (size_type i = 0, j = 0; i < _row * _col; )
			{
				if (i == (size_type)n * _col)
					i += _col;
				tmp[j++] = _matrix[i++];
			}
			delete [] _matrix;
			_matrix = tmp;
			_row--;
		}

		void				delete_col(int n)
		{
			if (n < 0 || (size_type)n >= _row)
				throw std::length_error("THROW MATRIX delete_col: wrong element");
			
			pointer	tmp = new value_type[_row * _col - _col];
			for (size_type i = 0, j = 0; i < _row * _col; i++)
			{
				if (i % _col == (size_type)n)
					continue ;
				tmp[j++] = _matrix[i];
			}
			delete [] _matrix;
			_matrix = tmp;
			_col--;
		}

//overload
		value_type			&operator[](size_type n) { return _matrix[n]; }
		const value_type	&operator[](size_type n) const { return _matrix[n]; }

//ex00
		Matrix	&add(const Matrix<value_type> &mat)
		{
			if (_row != mat.getRow() || _col != mat.getCol())
				throw std::length_error("THROW MATRIX add: wrong size");

			for (size_type i = 0; i < _row * _col; i++)
				(*this)[i] += mat[i];
			return *this;
		}

		Matrix	operator+(const Matrix<value_type> &mat) const
		{ 
			Matrix	tmp(*this);
			return	tmp.add(mat);
		}

		Matrix	&operator+=(const Matrix<value_type> &mat) { return add(mat); }

		Matrix	&sub(const Matrix<value_type> &mat)
		{
			if (_row != mat.getRow() || _col != mat.getCol())
				throw std::length_error("THROW MATRIX sub: wrong size");

			for (size_type i = 0; i < _row * _col; i++)
				(*this)[i] -= mat[i];
			return *this;
		}

		Matrix	operator-(const Matrix<value_type> &mat) const
		{ 
			Matrix	tmp(*this);
			return	tmp.sub(mat);
		}

		Matrix	&operator-=(const Matrix<value_type> &mat) { return sub(mat); }

		Matrix	&scl(const value_type &a)
		{
			for (size_type i = 0; i < _row * _col; i++)
				(*this)[i] *= a;
			return *this;
		}

		Matrix	operator*(const value_type &a) const
		{ 
			Matrix	tmp(*this);
			return	tmp.scl(a);
		}

		Matrix	&operator*=(const value_type &a) { return scl(a); }
};

	template<class T>
	Matrix<T> operator*(const T &a, const Matrix<T> &mat) { return mat * a; }

//Print
	template<class T>
	std::ostream& operator<<(std::ostream& os, const ft::Matrix<T> &mat)
	{
		size_t i = 0;
		for (; i < mat.getRow(); i++) 
		{
			os << "\t[";
			size_t j = 0;
			for (; j < mat.getCol(); j++) 
			{
				os << mat[i * mat.getCol() + j];
				if (j != mat.getCol() - 1)
					os << ", ";
			}
			os << "]";
			if (i != mat.getRow() - 1)
				os << std::endl;
		}
		if (i == 0)
			os << "\t[]";
		return os;
	}
}
