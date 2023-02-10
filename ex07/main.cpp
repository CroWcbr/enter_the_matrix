#include "../Matrix.hpp"
#include "../Vector.hpp"

using namespace ft;

void	test_in_task_vec()
{
	std::cout << "------ Matrix multiplication Vector ------" << std::endl;

	Matrix<double> u = {{1., 0.}, {0., 1.}};
	Vector<double> v = {4., 2.};
	std::cout << "{{1., 0.}, {0., 1.}} & {4., 2.}\t" << std::endl;
	std::cout << u.mul_vec(v) << std::endl;

	u = {{2., 0.}, {0., 2.}};
	std::cout << "{{2., 0.}, {0., 2.}} & {4., 2.}\t" << std::endl;
	std::cout << u.mul_vec(v) << std::endl;

	u = {{2., -2.}, {-2., 2.}};
	std::cout << "{{2., -2.}, {-2., 2.}} & {4., 2.}\t" << std::endl;
	std::cout << u.mul_vec(v) << std::endl;
}

void	test_in_task_mat()
{
	std::cout << "------ Matrix multiplication Matrix ------" << std::endl;

	Matrix<double> u = {{1., 0.}, {0., 1.}};
	Matrix<double> v = u;

	std::cout << "{{1., 0.}, {0., 1.}} & {{1., 0.}, {0., 1.}}\t" << std::endl;
	std::cout << u.mul_mat(v) << std::endl;

	v = {{2., 1.}, {4., 2.}};
	std::cout << "{{1., 0.}, {0., 1.}} & {{2., 1.}, {4., 2.}}\t" << std::endl;
	std::cout << u.mul_mat(v) << std::endl;

	u = {{3., -5.}, {6., 8.}};
	std::cout << "{{3., -5.}, {6., 8.}} & {{2., 1.}, {4., 2.}}\t" << std::endl;
	std::cout << u.mul_mat(v) << std::endl;
}

void	test_additional_matrix()
{
	std::cout << "------ Matrix multiplication Matrix additional ------" << std::endl;

	Matrix<double> u = {{1,2,3,4,5,6,7}, {8,9,10,11,12,13,14}};
	Matrix<double> v = {{11,12,13}, {14,15,16}, {17,18,19}, {20,21,22}, {23,24,25}, {26,27,28}, {29,30,31}};

	std::cout << "u.mul_mat(v)\t" << std::endl;
	std::cout << u.mul_mat(v) << std::endl;

	std::cout << "u * v\t" << std::endl;
	std::cout << u * v << std::endl;

	u *= v;
	std::cout << "u *= v\t" << std::endl;
	std::cout << u << std::endl;
}

void	test_additional_vector()
{
	std::cout << "------ Matrix multiplication Vector additional ------" << std::endl;

	Matrix<double> u = {{1,2,3,4,5,6,7}, {8,9,10,11,12,13,14}};
	Vector<double> v = {11,12,13,14,15,16,17};

	std::cout << "u.mul_vec(v)\t" << std::endl;
	std::cout << u.mul_vec(v) << std::endl;

	std::cout << "u * v\t" << std::endl;
	std::cout << u * v << std::endl;

	u *= v;
	std::cout << "u *= v\t" << std::endl;
	std::cout << u << std::endl;
}

int	main()
{
	test_in_task_vec();
	test_in_task_mat();
	test_additional_matrix();
	test_additional_vector();
}
