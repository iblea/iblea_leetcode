#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool unsigned char
#define true 1
#define false 0

#define	ifree(_p) (((_p) != NULL) ? (free((_p)), (_p) = NULL) : ((void *)0))
#define is_not_null(_ptr) ((_ptr) != NULL ? true : false)
#define is_null(_ptr) ((_ptr) == NULL ? true : false)
#define if_null_return(_ptr, _ret) if ((_ptr) == NULL) { return ret; }

#define is_true(_c) (_c == true ? true : false)
#define is_false(_c) (_c == true ? false : true)



void solution()
{
	printf("Hello World\n");
}



int main()
{
	solution();
	return 0;
}
