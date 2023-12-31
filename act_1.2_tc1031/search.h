// =================================================================
//
// File: search.h
// Author: Pedro Perez
// Description: This file contains the implementations of the
//				sequential and binary search algorithms.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef SEARCH_H
#define SEARCH_H

#include "header.h"
#include <vector>

// =================================================================
// Performs a sequential search for an element within a vector.
//
// @param A, a vector of T elements.
// @param key, the element to search.
// @return the index of the searched element, -1 in case the element
//		   is not found in the vector.
// =================================================================
template <class T>
int *sequentialSearch(const std::vector<T> &v, T key)
{
	static int arr[2];
	int comps = 0;
	arr[0] = -1;
	for (int i = 0; i < v.size(); i++)
	{
		comps++;
		if (v[i] == key)
		{
			arr[0] = i;
			break;
		}
	}
	arr[1] = comps;
	return arr;
}

// =================================================================
// Performs a binary search for an element within a vector
//
// @param A, a vector of T elements.
// @param key, the element to search.
// @return the index of the searched element, -1 in case the element
//		   is not found in the vector.
// =================================================================
template <class T>
int *binarySearch(const std::vector<T> &v, T key)
{
	int low, high, mid, comps = 0;
	static int arr[2];
	arr[0] = -1;

	low = 0;
	high = v.size() - 1;
	while (low <= high)
	{
		mid = low + ((high - low) / 2); // mid = (high + low) / 2;
		comps++;
		if (key == v[mid])
		{
			arr[0] = mid;
			break;
		}
		else if (key < v[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	arr[1] = comps;
	return arr;
}

// =================================================================
// Performs a binary search for an element within a vector
//
// @param A, a vector of T elements.
// @param low, lower limit of the search.
// @param high, upper limit of the search.
// @param key, the element to search.
// @return the index of the searched element, -1 in case the element
//		   is not found in the vector.
// =================================================================
template <class T>
int binaryRSearch(const std::vector<T> &v, int low, int high, T key)
{
	int mid;

	if (low > high)
	{
		return -1;
	}
	else
	{
		mid = low + ((high - low) / 2); // mid = (high + low) / 2;
		if (key == v[mid])
		{
			return mid;
		}
		else if (key < v[mid])
		{
			return binaryRSearch(v, low, mid - 1, key);
		}
		else
		{
			return binaryRSearch(v, mid + 1, high, key);
		}
	}
}

#endif /* SEARCH_H */
