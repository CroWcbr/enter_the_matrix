#include "../Matrix.hpp"
#include "../Vector.hpp"

using namespace ft;

void	test_in_task()
{
	std::cout << "------ Transpose in task ------" << std::endl;

	Matrix<double> u = {{1., 2.}, {3., 4.}, {5., 6.}};
	std::cout << "{{1., 2.}, {3., 4.}, {5., 6.}}" << std::endl;
	std::cout << u.transpose() << std::endl;

	u = {{1., 1., 1.}, {2., 2., 2.}, {3., 3., 3.}};
	std::cout << "{{1., 1., 1.}, {2., 2., 2.}, {3., 3., 3.}}" << std::endl;
	std::cout << u.transpose() << std::endl;

	u = {{1.}};
	std::cout << "{{1.}}\t" << std::endl;
	std::cout << u.transpose() << std::endl;

	u = {{}};
	std::cout << "{{}}\t" << std::endl;
	std::cout << u.transpose() << std::endl;
}

int	main()
{
	test_in_task();
}
