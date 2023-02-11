#include "../Matrix.hpp"
#include "../Vector.hpp"

using namespace ft;

void	test_in_task()
{
	std::cout << "------ Reduced row-echelon form in task ------" << std::endl;

	Matrix<double> u = {{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}};
	std::cout << "{{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}}" << std::endl;
	std::cout << u.row_echelon() << std::endl;

	u = {{1., 2.}, {3., 4.}};
	std::cout << "{{1., 2.}, {3., 4.}}" << std::endl;
	std::cout << u.row_echelon() << std::endl;

	u = {{1., 2.}, {2., 4.}};
	std::cout << "{{1., 2.}, {2., 4.}}" << std::endl;
	std::cout << u.row_echelon() << std::endl;

	u = {{8., 5., -2., 4., 28.}, {4., 2.5, 20., 4., -4.}, {8., 5., 1., 4., 17.}};
	std::cout << "{{8., 5., -2., 4., 28.}, {4., 2.5, 20., 4., -4.}, {8., 5., 1., 4., 17.}}" << std::endl;
	std::cout << u.row_echelon() << std::endl;
}

int	main()
{
	test_in_task();
}
