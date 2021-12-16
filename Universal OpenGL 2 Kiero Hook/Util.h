#pragma once
#include <stdarg.h>
namespace UTIL {
	// ex:
	// get_health(4,0x400000,0x1880C4,0,0x408)
	// 用于获取offset指针
	int* get_offset_pointer(int n, ...)
	{
		int val;
		va_list vl;
		va_start(vl, n);
		int base_address = va_arg(vl, int);
		int ret_address = base_address + va_arg(vl, int);
		for (int i = 2; i < n; i++)
		{
			ret_address = *((int*)ret_address) + va_arg(vl, int);
		}
		return (int*)(ret_address);
	}
}