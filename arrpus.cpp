#include <iostream>
#include <cstdlib>

void print_array(double *arr, size_t size);
void set_sum_array(double *arr1, double *arr2, double *arr3, size_t size);
void bubble_sort(double *arr, size_t size);
void gen_array(double *arr, size_t size);
void gen_uniq_array(double *arr, size_t size);

int main()
{
	size_t n = 0;
	std::cin >> n;

	double A[n] = { 0 };
	double B[n] = { 0 };
	double C[n] = { 0 };

	gen_array(A, n);
	gen_uniq_array(B, n);

	set_sum_array(A, B, C, n);

	bubble_sort(C, n);

	std::cout << __LINE__ << ":: Array A: ";
	print_array(A, n);
	std::cout << __LINE__ << ":: Array B: ";
	print_array(B, n);
	std::cout << __LINE__ << ":: Array C: ";
	print_array(C, n);

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

void set_sum_array(double *arr1, double *arr2, double *arr3, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		arr3[i] = arr1[i] + arr2[i];
	}
}

void bubble_sort(double *arr, size_t size)
{
	for (size_t y = 0; y < size; ++y)
	{
		for (size_t x = 1; x < size; ++x)
		{
			if (arr[x] < arr[x - 1])
			{
				std::swap(arr[x], arr[x - 1]);
			}
		}
	}
}

void gen_array(double *arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		arr[i] = rand() % 32000;
	}
}

void gen_uniq_array(double *arr, size_t size)
{
	bool is_uniq = true;
	for (size_t i = 0; i < size; ++i)
	{
		is_uniq = true;
		arr[i] = rand() % 32000;
		for (size_t x = 0; x < i; ++x)
		{
			if (arr[i] == arr[x])
			{
				--i;
				break;
			}
		}
	}
}
