#pragma once

#include <iostream>
#include <memory>
#include "Vector.hpp"

namespace ft
{
	#define EPS 0.0000000001

	template <class T>
	class Vector;

	template <class T = double>
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
		void				setMat(pointer mat) { delete [] _matrix; _matrix = mat; }
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
		void				delete_row(const size_type &n)
		{
			if (n < 0 || n >= _row)
				throw std::length_error("THROW MATRIX delete_row: wrong element");
			
			pointer	tmp = new value_type[_row * _col - _col];
			for (size_type i = 0, j = 0; i < _row * _col; )
			{
				if (i == n * _col)
					i += _col;
				else
					tmp[j++] = _matrix[i++];
			}
			setMat(tmp);
			_row--;
		}

		void				delete_col(const size_type &n)
		{
			if (n < 0 || n >= _col)
				throw std::length_error("THROW MATRIX delete_col: wrong element");
			
			pointer	tmp = new value_type[_row * _col - _row];
			for (size_type i = 0, j = 0; i < _row * _col; i++)
			{
				if (i % _col == n)
					continue ;
				tmp[j++] = _matrix[i];
			}
			setMat(tmp);
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
			std::cout << a << std::endl;
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

//ex11 Gaussian elimination for all matrix
		Matrix		upper_triangular_matrix_change_znak_when_swap_row(Matrix<value_type> tmp) const
		{
			for (size_type r = 0, c = 0; r < _row && c < _col; c++) //make upper triangular matrix
			{
				if (ft_abs(tmp[r * _col + c]) < EPS)
					for (size_type i = r + 1; i < _row; i++)			//check and change row
						if (ft_abs(tmp[i * _col + c]) > ft_abs(tmp[r * _col + c]))
						{
							for (size_type j = 0; j < _col; j++)
							{
								value_type	ttt = tmp[r * _col + j];
								tmp[r * _col + j] = tmp[i * _col + j];
								tmp[i * _col + j] = -ttt;
							}
							break;
						}
				if (ft_abs(tmp[r * _col + c]) > EPS)
				{
					
					for (size_type i = r + 1; i < _row; i++)			//make rows zero
					{
						value_type	scale_tmp = tmp[i * _col + c] / tmp[r * _col + c];
						for (size_type j = 0; j < _col; j++)
							tmp[i * _col + j] -= scale_tmp * tmp[r * _col + j];
					}
					r++;
				}
			}
			return tmp;
		}

		value_type	determinant() const
		{
			if (!is_square())
				throw std::length_error("THROW MATRIX determinant: !is_square");
			if (_row == 0 || _col == 0 )
				throw std::length_error("THROW MATRIX determinant: An empty matrix cannot have a determinant");

			Matrix<value_type>	tmp(upper_triangular_matrix_change_znak_when_swap_row(*this));
			value_type			det = 1;

			for (size_type i = 0; i < _row; i++)
				det *= tmp[i * _col + i];
			return det;
		}

		value_type	determinant_for_4() const
		{
			if (!is_square())
				throw std::length_error("THROW MATRIX determinant_for_4: !is_square");
			if (_row == 0 || _col == 0 )
				throw std::length_error("THROW MATRIX determinant: An empty matrix cannot have a determinant");

			if (_row * _col == 1)
				return _matrix[0];
			if (_row * _col == 4)
				return _matrix[0] * _matrix[3] - _matrix[1] * _matrix[2];
			
			value_type			det = 0;

			for (size_type i = 0; i < _row; i++) 
			{
				Matrix<value_type>	tmp(*this);
				tmp.delete_row(i);
				tmp.delete_col(0);
				det += _matrix[i * _col + 0] * std::pow(-1, i) * tmp.determinant_for_4();
			}
			return det;
		}

//ex12
		Matrix	cofactor_matrix_T(void) {
			Matrix tmp;
			Matrix com(_row, _col);
			for (size_type r = 0; r < _row; r++) 
			{
				for (size_type c = 0; c < _col; c++) 
				{
					tmp = *this;
					for (size_type k = 0; k < this->_row; k++) 
					{
						if (k != r)
							tmp[k * _col + c] = 0;
						else
							tmp[k * _col + c] = 1;
					}
					com[r * _col + c] = tmp.determinant();
				}
			}
			return com.transpose();
		}

		Matrix	inverse()
		{
			if (!is_square())
				throw std::length_error("THROW MATRIX inverse: !is_square");
			value_type det = determinant();
			if (det == 0)
				throw std::length_error("THROW MATRIX inverse: det == 0");
			Matrix com = cofactor_matrix_T().scl(1 / det);
			return com;
		}

//ex13
		size_type	rank()
		{
			Matrix		tmp(upper_triangular_matrix_change_znak_when_swap_row(*this));
			size_type	tmp_rank = 0;

			for (size_type r = 0; r < _row; r++)
			{
				size_type	c = r;
				for (; c < _col; c++)
					if (tmp[r * _col + c] != 0)
					{
						tmp_rank++;
						break;
					}
				if (c == _col)
					break;
			}
			return tmp_rank;
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
