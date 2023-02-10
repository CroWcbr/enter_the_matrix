#include "../Matrix.hpp"
#include "../Vector.hpp"

using namespace ft;

void	test_in_task()
{
	std::cout << "------ Trace in task ------" << std::endl;

	Matrix<double> u = {{1., 0.}, {0., 1.}};
	std::cout << "{{1., 0.}, {0., 1.}} & {4., 2.}}" << std::endl;
	std::cout << "\t\t" << u.trace() << std::endl;

	u = {{2., -5., 0.}, {4., 3., 7.}, {-2., 3., 4.}};
	std::cout << "{{2., -5., 0.}, {4., 3., 7.}, {-2., 3., 4.}}\t" << std::endl;
	std::cout << "\t\t" << u.trace() << std::endl;

	u = {{-2., -8., 4.}, {1., -23., 4.}, {0., 6., 4.}};
	std::cout << "{{-2., -8., 4.}, {1., -23., 4.}, {0., 6., 4.}}\t" << std::endl;
	std::cout << "\t\t" << u.trace() << std::endl;
}

int	main()
{
	test_in_task();
}
