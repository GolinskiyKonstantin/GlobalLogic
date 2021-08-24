
#ifndef _MY_ARR_H
#define _MY_ARR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>


int* ar_push(int* p_arr, int value);
void ar_print_all(const int* p_arr);
int ar_find_first(const int* p_arr, int value);
int* ar_remove(int* p_arr, int index);


#ifdef __cplusplus
}
#endif

#endif	/*	_MY_ARR_H */