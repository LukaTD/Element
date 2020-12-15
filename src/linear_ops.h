#pragma once

#include <math.h>

// TODO: SIMD/SSE/AVX

// single precision vectors
/*
 *  2D vector
 */
#define size_vec2 2u
typedef union vec2
{
	struct
	{
		f32 data[size_vec2];
	};

	struct
	{
		f32 x, y;
	};
} vec2;

void print_vec2(const vec2 a)
{
	printf("[%10.3f]\n"
		   "[%10.3f]\n",
		   a.x,a.y);
}

vec2 zeros_vec2(void)
{
	vec2 ret;
	for(u32 i = 0; i < size_vec2;i++)
		ret.data[i] = 0.f;

	return ret;
}

vec2 ones_vec2(void)
{
	vec2 ret;
	for(u32 i = 0; i < size_vec2;i++)
		ret.data[i] = 1.f;

	return ret;
}

vec2 neg_vec2(const vec2 a)
{
	vec2 ret;
	for(u32 i = 0; i < size_vec2;i++)
		ret.data[i] = -a.data[i];

	return ret;
}

f32 scalar_product_vec2(const vec2 a, const vec2 b)
{
	f32 accum = 0.f;
	for(u32 i = 0;i < size_vec2;i++)
		accum += a.data[i] * b.data[i];

	return accum;
}

f32 norm_vec2(const vec2 a)
{
	return sqrtf(scalar_product_vec2(a,a));
}

vec2 scalar_mul_vec2(const f32 scalar, const vec2 a)
{
	vec2 ret;
	for(u32 i = 0; i < size_vec2;i++)
		ret.data[i] = scalar*a.data[i];

	return ret;
}

vec2 normalize_vec2(const vec2 a)
{
	const f32 norm_scalar = norm_vec2(a);

	if(equal_f32(norm_scalar,0.f))
	{
		printf("Zero vector can not be normalized!");
		return a;
	}
	return scalar_mul_vec2(1.f/norm_scalar,a);
}

vec2 add_vec2(const vec2 a, const vec2 b)
{
	vec2 ret;
	for(u32 i = 0; i < size_vec2;i++)
		ret.data[i] = a.data[i] + b.data[i];

	return ret;
}

vec2 sub_vec2(const vec2 a, const vec2 b)
{
	vec2 ret;
	for(u32 i = 0; i < size_vec2;i++)
		ret.data[i] = a.data[i] - b.data[i];

	return ret;
}

/*
 *  3D vector
 */
#define size_vec3 3u
typedef union vec3
{
	struct
	{
		f32 data[size_vec3];
	};

	struct
	{
		f32 x, y, z;
	};
} vec3;

void print_vec3(const vec3 a)
{
	printf("[%10.3f]\n"
		   "[%10.3f]\n"
		   "[%10.3f]\n",
		   a.x,a.y,a.z);
}

vec3 zeros_vec3(void)
{
	vec3 ret;
	for(u32 i = 0;i < size_vec3;i++)
		ret.data[i] = 0.f;

	return ret;
}

vec3 ones_vec3(void)
{
vec3 ret;
	for(u32 i = 0;i < size_vec3;i++)
		ret.data[i] = 1.f;

	return ret;
}

vec3 neg_vec3(const vec3 a)
{
	vec3 ret;
	for(u32 i = 0;i < size_vec3;i++)
		ret.data[i] = -a.data[i];

	return ret;
}

f32 scalar_product_vec3(const vec3 a, const vec3 b)
{
	f32 accum = 0.f;
	for(u32 i = 0;i < size_vec3;i++)
		accum += a.data[i] * b.data[i];

	return accum;
}

f32 norm_vec3(const vec3 a)
{
	return sqrtf(scalar_product_vec3(a,a));
}

vec3 vector_product_vec3(const vec3 a, const vec3 b)
{
	vec3 ret;
	ret.x = a.y*b.z - a.z*b.y;
	ret.y = a.z*b.x - a.x*b.z;
	ret.z = a.x*b.y - a.y*b.x;

	return ret;
}

vec3 scalar_mul_vec3(const f32 scalar, const vec3 a)
{
	vec3 ret;
	for(u32 i = 0;i < size_vec3;i++)
		ret.data[i] = scalar*a.data[i];

	return ret;
}

vec3 normalize_vec3(const vec3 a)
{
	const f32 norm_scalar = norm_vec3(a);

	if(equal_f32(norm_scalar,0.f))
	{
		printf("Zero vector can not be normalized!");
		return a;
	}
	return scalar_mul_vec3(1.f/norm_scalar,a);
}

vec3 add_vec3(const vec3 a, const vec3 b)
{
	vec3 ret;
	for(u32 i = 0;i < size_vec3;i++)
		ret.data[i] = a.data[i] + b.data[i];

	return ret;
}

vec3 sub_vec3(const vec3 a, const vec3 b)
{
	vec3 ret;
	for(u32 i = 0;i < size_vec3;i++)
		ret.data[i] = a.data[i] - b.data[i];

	return ret;
}

/*
 *  4D vector
 */
#define size_vec4 4u
typedef union vec4
{
	struct
	{
		f32 data[size_vec4];
	};

	struct
	{
		f32 x, y, z, w;
	};
} vec4;

void print_vec4(const vec4 a)
{
	printf("[%10.3f]\n"
		   "[%10.3f]\n"
		   "[%10.3f]\n"
		   "[%10.3f]\n",
		   a.x,a.y,a.z,a.w);
}

vec4 zeros_vec4(void)
{
	vec4 ret;
	for(u32 i = 0;i < size_vec4;i++)
		ret.data[i] = 0.f;

	return ret;
}

vec4 ones_vec4(void)
{
vec4 ret;
	for(u32 i = 0;i < size_vec4;i++)
		ret.data[i] = 1.f;

	return ret;
}

vec4 neg_vec4(const vec4 a)
{
	vec4 ret;
	for(u32 i = 0;i < size_vec4;i++)
		ret.data[i] = -a.data[i];

	return ret;
}

f32 scalar_product_vec4(const vec4 a, const vec4 b)
{
	f32 accum = 0.f;
	for(u32 i = 0;i < size_vec3;i++)
		accum += a.data[i] * b.data[i];

	return accum;
}

f32 norm_vec4(const vec4 a)
{
	return sqrtf(scalar_product_vec4(a,a));
}

vec4 scalar_mul_vec4(const f32 scalar, const vec4 a)
{
	vec4 ret;
	for(u32 i = 0;i < size_vec4;i++)
		ret.data[i] = scalar*a.data[i];

	return ret;
}

vec4 normalize_vec4(const vec4 a)
{
	const f32 norm_scalar = norm_vec4(a);

	if(equal_f32(norm_scalar,0.f))
	{
		printf("Zero vector can not be normalized!");
		return a;
	}
	return scalar_mul_vec4(1.f/norm_scalar,a);
}

vec4 add_vec4(const vec4 a, const vec4 b)
{
	vec4 ret;

	for(u32 i = 0;i < size_vec4;i++)
		ret.data[i] = a.data[i] + b.data[i];

	return ret;
}

vec4 sub_vec4(const vec4 a, const vec4 b)
{
	vec4 ret;

	for(u32 i = 0;i < size_vec4;i++)
		ret.data[i] = a.data[i] - b.data[i];

	return ret;
}

// single precision matrices
/*
 *  2x2 matrix
 */
#define size_mat2 2u
typedef union mat2
{	
	struct 
	{
		f32 data[size_mat2][size_mat2];
	};

	struct
	{
		f32 xx, xy,
			yx, yy;
	};
} mat2;

void print_mat2(const mat2 a)
{
	printf("[%10.3f %10.3f]\n"
		   "[%10.3f %10.3f]\n",
		   a.xx, a.xy,
		   a.yx, a.yy);
}

mat2 zeros_mat2(void)
{
	mat2 ret;
	for(u32 i = 0;i < size_mat2;i++)
		for(u32 j = 0;j < size_mat2;j++)
			ret.data[i][j] = 0.f;

	return ret;
}

mat2 identity_mat2(void)
{
	mat2 ret;
	for(u32 i = 0;i < size_mat2;i++)
		ret.data[i][i] = 1.f;

	return ret;
}

mat2 neg_mat2(const mat2 a)
{
	mat2 ret;
	for(u32 i = 0;i < size_mat2;i++)
		ret.data[i][i] = -a.data[i][i];
	return ret;
}

mat2 transpose_mat2(const mat2 a)
{
	mat2 ret;
	for(u32 i = 0;i < size_mat2;i++)
		for(u32 j = 0;j < size_mat2;j++)
			ret.data[i][j] = a.data[j][i];
	return ret;
}

mat2 scalar_mul_mat2(const f32 scalar, const mat2 a)
{
	mat2 ret;
	for(u32 i = 0;i < size_mat2;i++)
		for(u32 j = 0;j < size_mat2;j++)
			ret.data[i][j] = scalar*a.data[i][j];

	return ret;
}

mat2 add_mat2(const mat2 a, const mat2 b)
{
	mat2 ret;
	for(u32 i = 0;i < size_mat2;i++)
		for(u32 j = 0;j < size_mat2;j++)
			ret.data[i][j] = a.data[i][j] + b.data[i][j];

	return ret;
}

mat2 sub_mat2(const mat2 a, const mat2 b)
{
	mat2 ret;
	for(u32 i = 0;i < size_mat2;i++)
		for(u32 j = 0;j < size_mat2;j++)
			ret.data[i][j] = a.data[i][j] - b.data[i][j];

	return ret;
}

mat2 matrix_mul_mat2(const mat2 a, const mat2 b)
{
	mat2 ret;
	for(u32 i = 0;i < size_mat2;i++)
		for(u32 j = 0;j < size_mat2;j++)
		{
			f32 accum = 0.f;
			for(u32 k = 0;k < size_mat2;k++)
				accum += a.data[k][j]*b.data[i][k];

			ret.data[i][j] = accum;
		}

	return ret;
}

/*
 *  3x3 matrix
 */
#define size_mat3 3u
typedef union mat3
{
	struct
	{
		f32 data[size_mat3][size_mat3];
	};

	struct
	{
		f32 xx, xy, xz,
			yx, yy, yz,
			zx, zy, zz;
	};
} mat3;

void print_mat3(const mat3 a)
{
	printf("[%10.3f %10.3f %10.3f]\n"
		   "[%10.3f %10.3f %10.3f]\n"
		   "[%10.3f %10.3f %10.3f]\n",
			a.xx, a.xy, a.xz,
			a.yx, a.yy, a.yz,
			a.zx, a.zy, a.zz);
}

mat3 zeros_mat3(void)
{
	mat3 ret;
	for(u32 i = 0;i < size_mat3;i++)
		for(u32 j = 0;j < size_mat3;j++)
			ret.data[i][j] = 0.f;

	return ret;
}

mat3 identity_mat3(void)
{
	mat3 ret;
	for(u32 i = 0;i < size_mat3;i++)
		ret.data[i][i] = 1.f;

	return ret;
}

mat3 neg_mat3(const mat2 a)
{
	mat3 ret;
	for(u32 i = 0;i < size_mat3;i++)
		ret.data[i][i] = -a.data[i][i];
	return ret;
}

mat3 transpose_mat3(const mat3 a)
{
	mat3 ret;
	for(u32 i = 0;i < size_mat3;i++)
		for(u32 j = 0;j < size_mat3;j++)
			ret.data[i][j] = a.data[j][i];
	return ret;
}

mat3 scalar_mul_mat3(const f32 scalar, const mat3 a)
{
	mat3 ret;
	for(u32 i = 0;i < size_mat3;i++)
		for(u32 j = 0;j < size_mat3;j++)
			ret.data[i][j] = scalar*a.data[i][j];

	return ret;
}

mat3 add_mat3(const mat3 a, const mat3 b)
{
	mat3 ret;
	for(u32 i = 0;i < size_mat3;i++)
		for(u32 j = 0;j < size_mat3;j++)
			ret.data[i][j] = a.data[i][j] + b.data[i][j];

	return ret;
}

mat3 sub_mat3(const mat3 a, const mat3 b)
{
	mat3 ret;
	for(u32 i = 0;i < size_mat3;i++)
		for(u32 j = 0;j < size_mat3;j++)
			ret.data[i][j] = a.data[i][j] - b.data[i][j];

	return ret;
}

mat3 matrix_mul_mat3(const mat3 a, const mat3 b)
{
	mat3 ret;
	for(u32 i = 0;i < size_mat3;i++)
		for(u32 j = 0;j < size_mat3;j++)
		{
			f32 accum = 0.f;
			for(u32 k = 0;k < size_mat3;k++)
				accum += a.data[k][j]*b.data[i][k];

			ret.data[i][j] = accum;
		}

	return ret;
}

/*
 *  4x4 matrix
 */
#define size_mat4 4u
typedef union mat4
{
	struct
	{
		f32 data[size_mat4][size_mat4];
	};

	struct
	{
		f32 xx, xy, xz, xw,
			yx, yy, yz, yw,
			zx, zy, zz, zw,
			wx, wy, wz, ww;
	};
} mat4;

void print_mat4(const mat4 a)
{
	printf("[%10.3f %10.3f %10.3f %10.3f]\n"
		   "[%10.3f %10.3f %10.3f %10.3f]\n"
		   "[%10.3f %10.3f %10.3f %10.3f]\n"
		   "[%10.3f %10.3f %10.3f %10.3f]\n",
			a.xx, a.xy, a.xz, a.xw,
			a.yx, a.yy, a.yz, a.yw,
			a.zx, a.zy, a.zz, a.zw,
			a.wx, a.wy, a.wz, a.ww);
}

mat4 zeros_mat4(void)
{
	mat4 ret;
	for(u32 i = 0;i < size_mat4;i++)
		for(u32 j = 0;j < size_mat4;j++)
			ret.data[i][j] = 0.f;

	return ret;
}

mat4 identity_mat4(void)
{
	mat4 ret;
	for(u32 i = 0;i < size_mat4;i++)
		ret.data[i][i] = 1.f;

	return ret;
}

mat4 neg_mat4(const mat4 a)
{
	mat4 ret;
	for(u32 i = 0;i < size_mat4;i++)
		ret.data[i][i] = -a.data[i][i];
	return ret;
}

mat4 transpose_mat4(const mat4 a)
{
	mat4 ret;
	for(u32 i = 0;i < size_mat4;i++)
		for(u32 j = 0;j < size_mat4;j++)
			ret.data[i][j] = a.data[j][i];
	return ret;
}

mat4 scalar_mul_mat4(const f32 scalar, const mat4 a)
{
	mat4 ret;
	for(u32 i = 0;i < size_mat4;i++)
		for(u32 j = 0;j < size_mat4;j++)
			ret.data[i][j] = scalar*a.data[i][j];

	return ret;
}

mat4 add_mat4(const mat4 a, const mat4 b)
{
	mat4 ret;
	for(u32 i = 0;i < size_mat4;i++)
		for(u32 j = 0;j < size_mat4;j++)
			ret.data[i][j] = a.data[i][j] + b.data[i][j];

	return ret;
}

mat4 sub_mat4(const mat4 a, const mat4 b)
{
	mat4 ret;
	for(u32 i = 0;i < size_mat4;i++)
		for(u32 j = 0;j < size_mat4;j++)
			ret.data[i][j] = a.data[i][j] - b.data[i][j];

	return ret;
}

mat4 matrix_mul_mat4(const mat4 a, const mat4 b)
{
	mat4 ret;
	for(u32 i = 0;i < size_mat4;i++)
		for(u32 j = 0;j < size_mat4;j++)
		{
			f32 accum = 0.f;
			for(u32 k = 0;k < size_mat4;k++)
				accum += a.data[k][j]*b.data[i][k];

			ret.data[i][j] = accum;
		}

	return ret;
}