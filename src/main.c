#include <stdio.h>

#include "types.h"
#include "linear_ops.h"

i32 main()
{
	mat3 aa = {
		4,3.54,43.3,
		43.54,54.34,34.54,
		43.54,54.34,34.54,
	};

	print_mat3(transpose_mat3(aa));
	return 0;
}
