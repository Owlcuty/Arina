#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

double function(double x, size_t n);
ssize_t calc_func(double *sum, double x, double eps, double (*func)(double x, size_t n));

double Yfunc(double x);

int main()
{
	double eps = 0;

	std::cout << "Функция суммы cos(nx) / n\n";

	std::cout << "Введите точность eps: ";
	std::cin >> eps;

	for (double x = M_PI / 5; x <= 9 * M_PI / 5; x += M_PI / 5)
	{

	double sum = 0;
	ssize_t num = calc_func(&sum, x, eps, function);
	if (num == -1)
	{
		std::cout << "Error from calc_func\n";
		return -1;
	}

	std::cout << "X = " << x << "\n";
	std::cout << "Sum of " << num << " elemets = " << sum << "\n";

	std::cout << "Y = -ln|2 * sin(" << x << " / 2)| = ";
	double res = Yfunc(x);
	std::cout << res << std::endl;
	}
	return 0;
}

double function(double x, size_t n)
{
	return cos(n * x) / n;
}

double Yfunc(double x)
{
	return -log(fabs(2 * sin(x / 2)));
}

ssize_t calc_func(double *sum, double x, double eps, double (*func)(double x, size_t n))
{
	if (sum == nullptr)
	{
		return 0;
	}

	*sum = 0;
	size_t n = 1;
	double cur = func(x, n++);

	while (fabs(cur) > eps)
	{
		(*sum) += cur;
		cur = func(x, n++);
		
	}

	return n - 1;
}
