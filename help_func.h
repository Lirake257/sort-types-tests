#ifndef HELP_FUNC_H  // Защита от повторного включения
#define HELP_FUNC_H
#include <vector>
#include <string>

void Output(std::vector<int> arr);

void write_arr_to_file(const std::vector<int> &arr, const std::string &filename);

void read_file_to_arr(int arr[], std::string filename, int n);

std::vector<int> generate_arr(size_t n);

void generate_arr_save(size_t n, std::string filename);

void generate_sorted_arr_save(size_t n, std::string filename);

void generate_rev_sorted_arr_save(size_t n, std::string filename);

void generate_e_arr_save(size_t n, std::string filename, size_t m);

std::vector<long long> test10_res(const int* arr, const int &arrlen, void (*sort)(int*, size_t, long long&, long long&, long long&));

bool sort_check(const int* arr, const int& arrlen);

void res_print(int n, std::vector<std::vector<std::vector<long long>>> arr, std::string filename, bool first_call);

void res100000_print(int n, std::vector<std::vector<std::vector<long long>>> arr, std::string filename);

#endif
