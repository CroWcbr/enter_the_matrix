#pragma once

#include <iostream>
#include <memory>
#include "Vector.hpp"

namespace ft
{
	#define EPS 0.0000000001

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

		void	check_init_matrix_col(const std::initializer_list<Vector<T>> &data)
		{
			for (auto row : data)
				if (_col !=  row.getSize())
					throw std::length_error("THROW MATRIX : wrong matrix size");
		}

	public:
	//Construcor and Destructor:
		Matrix()
		{
			// std::cout << "Matrix()" << std::endl;
			_row = 0;
			_col = 0;
			_matrix = new value_type[_row * _col];
		}

		Matrix(size_type row, size_type col)
		{
			// std::cout << "Matrix(size_type row, size_type col)" << std::endl;
			_row = row;
			_col = col;
			_matrix = new value_type[_row * _col];
		}

		Matrix(init_list data): _matrix(NULL)
		{
			// std::cout << "Matrix(init_list data)" << std::endl;
			*this = data;
		}

		Matrix(const std::initializer_list<Vector<T>> &data): _matrix(NULL)
		{
			// std::cout << "Matrix(const std::initializer_list<Vector<T>> &mat_list)" << std::endl;
			*this = data;
		}

		Matrix(const Matrix& copy): _matrix(NULL)
		{
			// std::cout << "Matrix(const Matrix& copy)" << std::endl;
			*this = copy;
		}

		Matrix	&operator=(const Matrix &copy)
		{
			// std::cout << "Matrix &operator=(const Matrix& copy)" << std::endl;
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
			// std::cout << "Matrix& operator= (const init_list init)" << std::endl;
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

		Matrix	&operator=(const std::initializer_list<Vector<T>> &data)
		{
			// std::cout << "Matrix &operator=(const std::initializer_list<Vector<T>> &data)" << std::endl;
			delete [] _matrix;
			_row = data.size();
			_col = (*data.begin()).getSize();
			check_init_matrix_col(data);
			_matrix = new value_type[_row * _col];
			size_type	r = 0;
			for (auto row : data)
			{
				for (size_type c = 0; c < row.getSize(); c++)
					_matrix[r * _col + c] = row[c];
				r++;
			}
			return *this;
		}

		~Matrix() 
		{	
			// std::cout << "~Matrix()" << std::endl;
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

//ex07
		Vector<value_type>	mul_vec(const Vector<value_type> &vec) const
		{
			if (_col != vec.getSize())
				throw std::length_error("THROW MATRIX mul_vec: _col != vec.getSize()");
			
			Vector<value_type> tmp(_row);
			
			for (size_type r = 0; r < _row; r++)
			{
				tmp[r] = 0;
				for (size_type c = 0; c < _col; c++)
					tmp[r] += _matrix[r * _col + c] * vec[c];
			}
			return tmp;
		}

		Vector<value_type>	operator*(const Vector<value_type> &vec) const { return mul_vec(vec); }

		Matrix				&operator*=(const Vector<value_type> &vec)
		{
			Vector<value_type>	tmp = mul_vec(vec);
			*this = tmp.reshape_vector_to_matrix(tmp.getSize(), 1);
			return *this;
		}

		Matrix				&operator*=(const Matrix<value_type> &mat)
		{
			if (_col != mat.getRow())
				throw std::length_error("THROW MATRIX mul_mat: _col != mat.getRow()");
			
			Matrix	tmp(_row, mat.getCol());
			for (size_type r1 = 0; r1 < tmp.getRow(); r1++)
			{
				for (size_type c2 = 0; c2 < tmp.getCol(); c2++)
				{
					tmp[r1 * tmp.getCol() + c2] = 0;
					for (size_type cr = 0; cr < _col; cr++)
						tmp[r1 * tmp.getCol() + c2] += _matrix[r1 * _col + cr] * mat[cr * mat.getCol() + c2];
				}
			}
			*this = tmp;
			return *this;
		}

		Matrix				mul_mat(const Matrix<value_type> &mat) const
		{
			Matrix	tmp(*this);
			return tmp *= mat;
		}

		Matrix				operator*(const Matrix<value_type> &mat) const { return mul_mat(mat); }

//ex08
		value_type	trace() const
		{
			if (!is_square())
				throw std::length_error("THROW MATRIX trace: !is_square");
			value_type	tmp = value_type();
			for (size_type i = 0; i < _row; i++)
				tmp += _matrix[i * _col + i];
			return tmp;
		}

//ex09
		Matrix	transpose() const
		{
			Matrix<value_type>	tmp(_col, _row);
			for (size_type r = 0; r < _row; r++)
				for (size_type c = 0; c < _col; c++)
					tmp[c * _row + r] = _matrix[r * _col + c];
			return tmp;
		}

//ex10 O(n^3) Gaussian elimination method
		Matrix	row_echelon() const
		{
			Matrix<value_type>	tmp(*this);
			value_type			scale_tmp;
			size_type			r_tmp;

			for (size_type r = 0, c = 0; r < _row && c < _col; c++)
			{
				r_tmp = r;
				for (size_type i = r + 1; i < _row; i++)			//find max
					if (ft_abs(tmp[i * _col + c]) > ft_abs(tmp[r_tmp * _col + c]))
						r_tmp = i;
				if (ft_abs(tmp[r_tmp * _col + c]) > EPS)
				{
					if (r_tmp != r)
						for (size_type i = 0; i < _col; i++)		//swap
						{
							value_type	ttt = tmp[r * _col + i];
							tmp[r * _col + i] = tmp[r_tmp * _col + i];
							tmp[r_tmp * _col + i] = ttt;
						}
					scale_tmp = tmp[r * _col + c];
					for (size_type i = 0; i < _col; i++)			//scale
						tmp[r * _col + i] /= scale_tmp;
					for (size_type i = 0; i < _row; i++)			//addRows
					{
						scale_tmp = tmp[i * _col + c];
						if (i != r)
							for (size_type j = 0; j < _col; j++)
								tmp[i * _col + j] -= scale_tmp * tmp[r * _col + j];
					}
					r++;
				}
			}
			return tmp;
		}
};

//ex00
	template<class T>
	Matrix<T> operator*(const T &a, const Matrix<T> &mat) { return mat * a; }

//Print
	template<class T>
	std::ostream& operator<<(std::ostream& os, const ft::Matrix<T> &mat)
	{
		size_t i = 0;
		os << "\t[";
		for (; i < mat.getRow(); i++) 
		{
			if (i != 0)
				os << "\t";
			os << "[";
			size_t j = 0;
			for (; j < mat.getCol(); j++) 
			{
				if (ft_abs(mat[i * mat.getCol() + j]) < EPS)
					os << 0;
				else
					os << mat[i * mat.getCol() + j];
				if (j != mat.getCol() - 1)
					os << ", ";
			}
			os << "]";
			if (i != mat.getRow() - 1)
				os << std::endl;
		}
		os << "]";
		return os;
	}
}
