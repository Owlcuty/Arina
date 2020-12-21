#include <iostream>
#include <cstdlib>

void print_array(double *arr, size_t size);
void print_mtrx(double *arr, size_t height, size_t width);
void set_sum_array(double *dest, double *src, size_t height, size_t width);
void bubble_sort(double *arr, size_t size);
void gen_array(double *arr, size_t height, int width);

int main()
{
	size_t n = 0;
	std::cout << "Enter n: ";
	std::cin >> n;

	double A[n] = { 0 };
	double *C = (double*)calloc(n * n, sizeof(*C));

	gen_array(C, n, n);

	set_sum_array(A, C, n, n);

	bubble_sort(A, n);

	std::cout << __LINE__ << ":: Array A:\n";
	print_array(A, n);
	std::cout << "\n" << __LINE__ << ":: Array C:\n";
	print_mtrx(C, n, n);

	free(C);

	return 0;
}

void print_array(double *arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void print_mtrx(double *arr, size_t height, size_t width)
{
	for (size_t y = 0; y < height; ++y)
	{
		print_array(arr + y * width, width);
	}
}

void set_sum_array(double *dst, double *src, size_t height, size_t width)
{
	for (size_t y = 0; y < height; ++y)
	{
		double sum = 0;
		for (size_t x = 0; x < width; ++x)
		{
			sum += src[y * width + x];
		}
		dst[y] = sum;
	}
}

void bubble_sort(double *arr, size_t size)
{
	for (size_t y = 0; y < size; ++y)
	{
		for (size_t x = 0; x < size; ++x)
		{
			if (arr[y] < arr[x])
			{
				std::swap(arr[x], arr[y]);
			}
		}
	}
}

void gen_array(double *arr, size_t height, int width)
{
	for (size_t y = 0; y < height; ++y)
	{
		for (size_t x = 0; x < width; ++x)
		{
			arr[y * width + x] = rand() % 32000;
		}
	}
}

