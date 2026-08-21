#ifndef SORT_FUNC_H  // Защита от повторного включения
#define SORT_FUNC_H
#include <vector>

void selection_sort(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count);

void insertion_sort(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count);

void bubble_sort(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count);

void merge_sort_ob(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count);

void Shell_sort(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count);

void quick_sort_ob(int* arr, size_t arrlen, long long &sort_time, long long &if_count, long long &swap_count);
#endif
