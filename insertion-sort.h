#pragma once

void insertion_sort(int * array, int count) {
	for (int  i = 1; i < count; ++i)
	{
		int key = array[i];

		int j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}
