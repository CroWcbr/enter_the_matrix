#include "../Matrix.hpp"
#include "../Vector.hpp"

void	test_in_task()
{
	std::cout << "------ lerp in task ------" << std::endl;

	std::cout << "lerp(0., 1., 0.)" << std::endl << ft::lerp(0., 1., 0.) << std::endl;
	std::cout << "lerp(0., 1., 1.)" << std::endl << ft::lerp(0., 1., 1.) << std::endl;
	std::cout << "lerp(0., 1., 0.5)" << std::endl << ft::lerp(0., 1., 0.5) << std::endl;
	std::cout << "lerp(21., 42., 0.3)" << std::endl << ft::lerp(21., 42., 0.3) << std::endl;

	ft::Vector<double>	v1({2., 1.});
	ft::Vector<double>	v2({4., 2.});
	std::cout << "lerp(v1, v2, 0.3)" << std::endl << ft::lerp(v1, v2, 0.3) << std::endl;

	ft::Matrix<double>	u1({{2, 1.}, {3., 4.}});
	ft::Matrix<double>	u2({{20., 10.}, {30., 40.}});
	std::cout << "lerp(u1, u2, 0.5)" << std::endl << ft::lerp(u1, u2, 0.5) << std::endl;
}

int	main()
{
	test_in_task();
}
