#include "../Matrix.hpp"
#include "../Vector.hpp"

using namespace ft;

void	test_in_task()
{
	std::cout << "------ Inverse in task ------" << std::endl;

	ft::Matrix<double> u = {{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}};
	std::cout << "{{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}}" << std::endl;
	std::cout << u.rank() << std::endl;

	u = {{1., 2., 0., 0.}, {2., 4., 0., 0.}, {-1., 2., 1., 1.}};
	std::cout << "{{1., 2., 0., 0.}, {2., 4., 0., 0.}, {-1., 2., 1., 1.}}" << std::endl;
	std::cout << u.rank() << std::endl;

	u = {{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}, {21., 18., 7.}};
	std::cout << "{{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}, {21., 18., 7.}}" << std::endl;
	std::cout << u.rank() << std::endl;
}

int	main()
{
	test_in_task();
}
