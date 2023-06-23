#include <iostream>
#include "Matrix.hpp"
#include "Vector.hpp"
#include "Complex.hpp"
#include <initializer_list>

using namespace ft;

void	test_ex00_add_sub_scl_vector()
{
	std::cout << "------ test_ex00_add_sub_scl_vector ------" << std::endl;

	Vector<Complex> u = {Complex(1,1), Complex(3)};
	Vector<Complex> v = {5., Complex(7,4)};

	std::cout << "------ VECTOR add ------" << std::endl;
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;
	std::cout << "u.add(v) = " << std::endl << u.add(v) << std::endl;
	u = {Complex(1,1), Complex(3)};
	std::cout << "u + v = " << std::endl << (u + v) << std::endl;
	u += v;
	std::cout << "u += v" << std::endl << u << std::endl;

	std::cout << "------ VECTOR sub ------" << std::endl;
	u = {Complex(1,1), Complex(3)};
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;
	std::cout << "u.sub(v) = " << std::endl << u.sub(v) << std::endl;
	u = {Complex(1,1), Complex(3)};
	std::cout << "u - v = " << std::endl << (u - v) << std::endl;
	u -= v;
	std::cout << "u -= v" << std::endl << u << std::endl;


	std::cout << "------ VECTOR scl ------" << std::endl;
	u = {Complex(1,1), Complex(3)};
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "u.scl(2) = " << std::endl << u.scl(2) << std::endl;
	u = {Complex(1,1), Complex(3)};
	std::cout << "u * 2 = " << std::endl << (u * 2) << std::endl;
	std::cout << "Complex(2) * u = " << std::endl << (Complex(2) * u) << std::endl;
	u *= 2;
	std::cout << "u *= 2" << std::endl << u << std::endl;

}

void	test_ex00_add_sub_scl_matrix()
{
	std::cout << "------ test_ex00_add_sub_scl_matrix ------" << std::endl;

	Matrix<Complex> u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	Matrix<Complex> v = {{Complex(5), Complex(7,4)}, {Complex(1, 21), Complex(2, 42)}};

	std::cout << "------ MATRIX add ------" << std::endl;
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;
	std::cout << "u.add(v) = " << std::endl << u.add(v) << std::endl;
	u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	std::cout << "u + v = " << std::endl << (u + v) << std::endl;
	u += v;
	std::cout << "u += v" << std::endl << u << std::endl;

	std::cout << "------ MATRIX sub ------" << std::endl;
	u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;
	std::cout << "u.sub(v) = " << std::endl << u.sub(v) << std::endl;
	u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	std::cout << "u - v = " << std::endl << (u - v) << std::endl;
	u -= v;
	std::cout << "u -= v" << std::endl << u << std::endl;

	std::cout << "------ MATRIX scl ------" << std::endl;
	u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "u.scl(2) = " << std::endl << u.scl(2) << std::endl;
	u = {{Complex(1,1), Complex(3)}, {Complex(6), Complex(2, 2)}};
	std::cout << "u * Complex(2) = " << std::endl << (u * Complex(2)) << std::endl;
	std::cout << "Complex(2) * u = " << std::endl << (Complex(2) * u) << std::endl;
	u *= Complex(2, 2);
	std::cout << "u *= Complex(2, 2)" << std::endl << u << std::endl;
}

void	test_ex00_reshape()
{
	std::cout << "------ VECTOR reshape ------" << std::endl;
	{
		Vector<Complex> u2({1., 2, 3., 4., 5., 6., 7, 8, 9});
		std::cout << "reshape_vector_to_matrix" << std::endl << u2.reshape_vector_to_matrix(3, 3) << std::endl;
		u2.delete_element(0);
		std::cout << "u2.delete_element(0)" << std::endl << u2 << std::endl;
		u2.delete_element(5);
		std::cout << "u2.delete_element(5)" << std::endl << u2 << std::endl;
		try
		{
			std::cout << "u2.delete_element(10)" << std::endl;
			u2.delete_element(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "------ MATRIX reshape------" << std::endl;
	{
		Matrix<Complex> u2({{Complex(1,1), Complex(2,2), Complex(3,3)}, \
								{Complex(4,4), Complex(5,5), Complex(6,6)}, \
								{Complex(7,7), Complex(8,8), Complex(9,9)}});
		std::cout << "u2" << std::endl << u2 << std::endl;
	
		std::cout << "reshape_matrix_to_vector" << std::endl << u2.reshape_matrix_to_vector() << std::endl;
		u2.delete_row(1);
		std::cout << "u2.delete_row(1)" << std::endl << u2 << std::endl;
		u2.delete_col(2);
		std::cout << "u2.delete_col(2)" << std::endl << u2 << std::endl;
		try
		{
			std::cout << "u2.delete_row(10)" << std::endl;
			u2.delete_row(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

}

void	test_ex01_linear_combination()
{
	std::cout << "------ linear_combination ------" << std::endl;

	Matrix<Complex>	u({{Complex(1, 1), Complex(2, 2), Complex(3, 3)}, {Complex(0, 10), Complex(10, 1), Complex(-100, 3)}});
	Vector<Complex>	v({Complex(10, 1), Complex(-2, 10)});
	std::cout << "u = " << std::endl << u << std::endl;
	std::cout << "v = " << std::endl << v << std::endl;

	std::cout << "linear_combination(u, v)" << std::endl;
	std::cout << linear_combination(u, v) << std::endl;

	std::cout << "linear_combination(u, {10., -2.})" << std::endl;
	std::cout << linear_combination(u, {10., -2.}) << std::endl;

	Matrix<Complex>	u2({{Complex(1,2), Complex(3,4)}, {Complex(5,6), Complex(7,8)}});
	Vector<Complex>	v2({Complex(9, 10), Complex(11, 12)});
	std::cout << "u2 = " << std::endl << u2 << std::endl;
	std::cout << "v2 = " << std::endl << v2 << std::endl;
	std::cout << "linear_combination(u2, v2)" << std::endl;
	std::cout << linear_combination(u2, v2) << std::endl;
}

void	test_ex02_lerp()
{
	std::cout << "------ lerp ------" << std::endl;

	std::cout << "lerp(0., 1., 0.)" << std::endl << lerp(Complex(0), Complex(1), 0) << std::endl;
	std::cout << "lerp(0., 1., 1.)" << std::endl << lerp(Complex(0), Complex(1), 1.) << std::endl;
	std::cout << "lerp(0., 1., 0.5)" << std::endl << lerp(Complex(0), Complex(1), 0.5) << std::endl;
	std::cout << "lerp(21., 42., 0.3)" << std::endl << lerp(Complex(21), Complex(42), 0.3) << std::endl;

	Vector<Complex>	v1({2., 1.});
	Vector<Complex>	v2({4., 2.});
	std::cout << "lerp(v1, v2, 0.3)" << std::endl << lerp(v1, v2, 0.3) << std::endl;

	Matrix<Complex>	u1({{Complex(2), Complex(1)}, {Complex(3), Complex(4)}});
	Matrix<Complex>	u2({{Complex(20), Complex(10)}, {Complex(30), Complex(40)}});
	std::cout << "lerp(u1, u2, 0.5)" << std::endl << lerp(u1, u2, 0.5) << std::endl;

	std::cout << "------ lerp complex ------" << std::endl;

	Vector<Complex>	v11({Complex(2, 3), Complex(1,5)});
	Vector<Complex>	v22({Complex(5, 2), Complex(2,10)});
	std::cout << "lerp(v11, v22, 0.3)" << std::endl << lerp(v11, v22, 0.3) << std::endl;

	Matrix<Complex>	u11({{Complex(2, 6), Complex(1, -5)}, {Complex(3, -10), Complex(4, 10)}});
	Matrix<Complex>	u22({{Complex(20,2), Complex(10,1)}, {Complex(30,-3), Complex(40,-4)}});
	std::cout << "lerp(u11, u22, 0.5)" << std::endl << lerp(u11, u22, 0.5) << std::endl;
}

void	test_ex03_dot()
{
	std::cout << "------ dot ------" << std::endl;

	Vector<Complex>	u({Complex(2, 3), Complex(1,5)});
	Vector<Complex>	v({Complex(5, 2), Complex(2,10)});
	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;
	std::cout << "u.dot(v) = " << u.dot(v) << std::endl;

	u = {Complex(1, 1), Complex(1,1)};
	v = {Complex(1, 1), Complex(1,1)};
	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;
	std::cout << "u.dot(v) = " << u.dot(v) << std::endl;

	u = {Complex(-1, 10), Complex(6,11)};
	v = {Complex(3, -10), Complex(2,16)};
	std::cout << "u = " << u << std::endl;
	std::cout << "v = " << v << std::endl;
	std::cout << "u.dot(v) = " << u.dot(v) << std::endl;
}

void	test_ex04_norm()
{
	std::cout << "------ norm in task ------" << std::endl;

	Vector<Complex>	u = {Complex(0), Complex(0), Complex(0)};
	std::cout << u << std::endl;
	std::cout << "u1" << "\t" << u.norm_1() << "\t";
	std::cout << u.norm() << "\t" << u.norm_inf() << std::endl;
	
	u = {Complex(1,1), Complex(2,2), Complex(3,3)};
	std::cout << u << std::endl;
	std::cout << "u2" << "\t" << u.norm_1() << "\t";
	std::cout << u.norm() << "\t" << u.norm_inf() << std::endl;
	
	u = {Complex(3,4), Complex(1,2), Complex(-2,-1)};
	std::cout << u << std::endl;
	std::cout << "u3" << "\t" << u.norm_1() << "\t";
	std::cout << u.norm() << "\t" << u.norm_inf() << std::endl;
}

void	test_ex05_cos()
{
	std::cout << "------ cosine ------" << std::endl;

	try
	{
		Vector<Complex>	u = {Complex(0), Complex(0)};
		Vector<Complex>	v = {Complex(0), Complex(0)};
		std::cout << "1" << "\t" << angle_cos(u, v) << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << "1" << "\t" << e.what() << std::endl;	
	}
	
	Vector<Complex>	u = {Complex(1,1), Complex(0,0)};
	Vector<Complex>	v = {Complex(2,2), Complex(1,1)};
	std::cout << "2" << "\t" << angle_cos(u, v) << std::endl;
	
	u = {Complex(-1,1), Complex(0,0)};
	v = {Complex(1,1), Complex(-1,0)};
	std::cout << "3" << "\t" << angle_cos(u, v) << std::endl;

	u = {Complex(-10,14), Complex(60,0)};
	v = {Complex(14,11), Complex(-1,30)};
	std::cout << "4" << "\t" << angle_cos(u, v) << std::endl;
}

void	test_ex06_cross_product()
{
	std::cout << "------ Cross product ------" << std::endl;
	try
	{
		Vector<Complex>	u({Complex(10, 1), Complex(-2, 10), Complex(-2, -1)});
		Vector<Complex> v({Complex(10, 1), Complex(-2, 3), Complex(-2, 7)});
		std::cout   << "1\t" << std::endl << cross_product(u, v) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cross product" << "\t" << e.what() << std::endl;	
	}
}

void	test_ex07_mult()
{
	std::cout << "------ Matrix multiplication Vector ------" << std::endl;
	{
		Matrix<Complex> u = {{Complex(1., 2), Complex(0., 4)}, {Complex(0., 4), Complex(1.,1)}};
		Vector<Complex> v = {4., 2.};
		std::cout << "1\t" << std::endl;
		std::cout << u.mul_vec(v) << std::endl;

		u = {{Complex(14., 2), Complex(0., 4)}, {Complex(50., 4), Complex(11.,1)}};
		std::cout << "2\t" << std::endl;
		std::cout << u.mul_vec(v) << std::endl;

		u = {{Complex(11., 2), Complex(7., 4)}, {Complex(4., 4), Complex(13.,1)}};
		std::cout << "3\t" << std::endl;
		std::cout << u.mul_vec(v) << std::endl;
	}
	std::cout << "------ Matrix multiplication Matrix ------" << std::endl;
	{
		Matrix<Complex> u =  {{Complex(1., 2), Complex(0., 4)}, {Complex(0., 4), Complex(1.,1)}};
		Matrix<Complex> v = u;

		std::cout << "1\t" << std::endl;
		std::cout << u.mul_mat(v) << std::endl;

		v =  {{Complex(14., 2), Complex(5., 4)}, {Complex(124., 4), Complex(41.,1)}};
		std::cout << "2\t" << std::endl;
		std::cout << u.mul_mat(v) << std::endl;

		u = {{Complex(3.,5), Complex(-5.,1)}, {Complex(6,-5), Complex(8.,4)}};
		std::cout << "3\t" << std::endl;
		std::cout << u.mul_mat(v) << std::endl;
	}
}

void	test_ex08_trace()
{
	std::cout << "------ Trace  ------" << std::endl;

	Matrix<Complex> u = {{Complex(1.), Complex(0.)}, {Complex(0.), Complex(1.)}};
	std::cout << "1" << std::endl;
	std::cout << "\t\t" << u.trace() << std::endl;

	u = {{Complex(1., 3), Complex(1.,3), Complex(1.,3)}, \
		{Complex(2.,6), Complex(2.,3), Complex(2.,3)}, \
		{Complex(3.,4), Complex(3.,4), Complex(3.,10)},};
	std::cout << "2" << std::endl;
	std::cout << "\t\t" << u.trace() << std::endl;

	u = {{Complex(-2.,-2), Complex(-8.), Complex(4.)}, 
		{Complex(1.), Complex(-23.,-23), Complex(4.)}, 
		{Complex(0.), Complex(6.), Complex(4.,1)}};
	std::cout << "3" << std::endl;
	std::cout << "\t\t" << u.trace() << std::endl;
}

void	test_ex09_transpose()
{
	std::cout << "------ Transpose ------" << std::endl;

	Matrix<Complex> u = {{Complex(1.), Complex(2.)}, \
						{Complex(3.), Complex(4.)}, \
						{Complex(5.), Complex(6)}};
	std::cout << "1" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.transpose() << std::endl;

	u = {{Complex(1., 3), Complex(1.,3), Complex(1.,3)}, \
		{Complex(2.,6), Complex(2.,3), Complex(2.,3)}, \
		{Complex(3.,4), Complex(3.,4), Complex(3.,10)},};
	std::cout << "2" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.transpose() << std::endl;

	u = {{Complex(1.)}};
	std::cout << "3\t" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.transpose() << std::endl;

	u = {{}};
	std::cout << "4\t" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.transpose() << std::endl;
}

void	test_ex10_RREF()
{
	std::cout << "------ Reduced row-echelon form in task ------" << std::endl;

	Matrix<Complex> u = {{Complex(1.), Complex(0.), Complex(0.)}, \
						{Complex(0.), Complex(1.), Complex(0.)}, \
						{Complex(0.), Complex(0.), Complex(1.)},};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.row_echelon() << std::endl;

	u = {{Complex(8.), Complex(5.), Complex(-2.), Complex(4.), Complex(28.)}, \
		{Complex(4.), Complex(2.5), Complex(20.), Complex(4.), Complex(-4.)}, \
		{Complex(8.), Complex(5.), Complex(1.), Complex(4.), Complex(17.)}};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.row_echelon() << std::endl;

	u = {{Complex(8.,3), Complex(5.,2), Complex(-2.,1), Complex(4.,3), Complex(28.,4)}, \
		{Complex(4.,5), Complex(2.5,8), Complex(20.,1), Complex(4.,-3), Complex(-4.,-5)}, \
		{Complex(8., 4), Complex(5.,2), Complex(1.,3), Complex(4., 1), Complex(17., 0)}};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.row_echelon() << std::endl;
}

void	test_ex11_determinant()
{
	std::cout << "------ Determinant in task ------" << std::endl;

	Matrix<Complex> u = {{Complex(1), Complex(-1)}, {Complex(-1), Complex(1)}};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.determinant_for_4() << std::endl;

	u = {{Complex(1., 3), Complex(1.,3), Complex(1.,3)}, \
		{Complex(2.,6), Complex(2.,3), Complex(2.,3)}, \
		{Complex(3.,4), Complex(3.,4), Complex(3.,10)},};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.determinant_for_4() << std::endl;

	u = {{Complex(14., 3), Complex(1.,32), Complex(11.,3)}, \
		{Complex(2.,65), Complex(2.,3), Complex(32.,3)}, \
		{Complex(43.,4), Complex(3.,43), Complex(33.,10)},};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.determinant_for_4() << std::endl;

	u = {{Complex(8.), Complex(5.), Complex(-2.), Complex(4.)}, \
		{Complex(4.), Complex(2.5), Complex(20.), Complex(4.)}, \
		{Complex(8.), Complex(5.), Complex(1.), Complex(4.)}, \
		{Complex(28.), Complex(-4.), Complex(17.), Complex(1.)}};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.determinant_for_4() << std::endl;
}

void	test_ex12_inverse()
{
	std::cout << "------ Inverse in task ------" << std::endl;

	Matrix<Complex>	u = {{Complex(1., 3), Complex(1.,3), Complex(1.,3)}, \
						{Complex(2.,6), Complex(2.,3), Complex(2.,3)}, \
						{Complex(3.,4), Complex(3.,4), Complex(3.,10)},};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.inverse() << std::endl;

	u = {{Complex(14., 3), Complex(1.,32), Complex(11.,3)}, \
		{Complex(2.,65), Complex(2.,3), Complex(32.,3)}, \
		{Complex(43.,4), Complex(3.,43), Complex(33.,10)},};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.inverse() << std::endl;
}

void	test_ex13_rank()
{
	std::cout << "------ Rank in task ------" << std::endl;

	Matrix<Complex>	u = {{Complex(1., 3), Complex(1.,3), Complex(1.,3)}, \
						{Complex(2.,6), Complex(2.,3), Complex(2.,3)}, \
						{Complex(3.,4), Complex(3.,4), Complex(3.,10)},};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.rank() << std::endl;

	u = {{Complex(14., 3), Complex(1.,32), Complex(11.,3)}, \
		{Complex(2.,65), Complex(2.,3), Complex(32.,3)}, \
		{Complex(43.,4), Complex(3.,43), Complex(33.,10)},};
	std::cout << "u" << std::endl;
	std::cout << u << std::endl;
	std::cout << "after" << std::endl;
	std::cout << u.rank() << std::endl;
}
