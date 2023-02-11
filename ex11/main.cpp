#include "../Matrix.hpp"
#include "../Vector.hpp"

using namespace ft;

void	test_in_task()
{
	std::cout << "------ Determinant in task ------" << std::endl;

	ft::Matrix<double> u = {{1., -1.}, {-1., 1.}};
	std::cout << "{{1., -1.}, {-1., 1.}}" << std::endl;
	std::cout << u.determinant_for_4() << std::endl;

	u = {{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}};
	std::cout << "{{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}}" << std::endl;
	std::cout << u.determinant_for_4() << std::endl;

	u = {{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}};
	std::cout << "{{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}}" << std::endl;
	std::cout << u.determinant_for_4() << std::endl;

	u = {{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}};
	std::cout << "{{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}}" << std::endl;
	std::cout << u.determinant_for_4() << std::endl;
	
}

void	test_additional_any_matrix()
{
	std::cout << "------ Determinant for any matrix Gaussian elimination ------" << std::endl;

	ft::Matrix<double> u = {{1., -1.}, {-1., 1.}};
	std::cout << "{{1., -1.}, {-1., 1.}}" << std::endl;
	std::cout << u.determinant() << std::endl;

	u = {{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}};
	std::cout << "{{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}}" << std::endl;
	std::cout << u.determinant() << std::endl;

	u = {{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}};
	std::cout << "{{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}}" << std::endl;
	std::cout << u.determinant() << std::endl;

	u = {{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}};
	std::cout << "{{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}}" << std::endl;
	std::cout << u.determinant() << std::endl;
}

void	test_additional_error()
{
	std::cout << "------ Determinant error ------" << std::endl;

	ft::Matrix<double> u = {};
	std::cout << "{}" << std::endl;
	try
	{
		std::cout << u.determinant_for_4() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << u.determinant() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	u = {{}};
	std::cout << "{{}}" << std::endl;
	try
	{
		std::cout << u.determinant_for_4() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << u.determinant() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	u = {{1., 2.}, {4., 5.}, {2., 4.}};
	std::cout << "{{1., 2.}, {4., 5.}, {2., 4.}}" << std::endl;
	try
	{
		std::cout << u.determinant_for_4() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << u.determinant() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main()
{
	test_in_task();
	test_additional_any_matrix();
	test_additional_error();
}
