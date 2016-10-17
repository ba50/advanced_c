#pragma once

#include <stdio.h>
#include <memory>

struct Test{
	int x, y;
	
	Test():
	x(-1),
	y(-1)
	{}

	Test(int x, int y):
	x(x),
	y(y)
	{}

	void Print(){
		printf("(%d, %d)\n", x, y);
	}
};
