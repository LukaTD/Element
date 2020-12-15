#pragma once

#include <math.h>

// TODO: SIMD/SSE/AVX

// single precision vectors
/*
 *  2D vector
 */
typedef struct vec2
{
	f32 data[2];
} vec2;

vec2 zeros_vec2()
{
	vec2 ret;
	ret.data[0] = 0.f;
	ret.data[1] = 0.f;

	return ret;
}

vec2 ones_vec2()
{
	vec2 ret;
	ret.data[0] = 1.f;
	ret.data[1] = 1.f;

	return ret;
}

f32 norm_vec2(const vec2 a)
{
	return sqrtf(a.data[0]*a.data[0] + a.data[1]*a.data[1]);
}

vec2 neg_vec2(const vec2 a)
{
	vec2 ret;
	ret.data[0] = -a.data[0];
	ret.data[1] = -a.data[1];

	return ret;
}

vec2 scalar_mul_vec2(const f32 scalar, const vec2 a)
{
	vec2 ret;
	ret.data[0] = scalar*a.data[0];
	ret.data[1] = scalar*a.data[1];

	return ret;
}

vec2 normalize_vec2(const vec2 a)
{
	const f32 norm_scalar = norm_vec2(a);

	if(equal_f32(norm_scalar,0.f))
	{
		printf("Can not normalize vector: (%f, %f)",a.data[0],a.data[1]);
		return a;
	}
	return scalar_mul_vec2(1.f/norm_scalar,a);
}

vec2 add_vec2(const vec2 a, const vec2 b)
{
	vec2 ret;
	ret.data[0] = a.data[0] + b.data[0];
	ret.data[1] = a.data[1] + b.data[1];

	return ret;
}

vec2 sub_vec2(const vec2 a, const vec2 b)
{
	vec2 ret;
	ret.data[0] = a.data[0] - b.data[0];
	ret.data[1] = a.data[1] - b.data[1];

	return ret;
}

/*
 *  3D vector
 */
typedef struct vec3
{
	f32 data[3];
} vec3;

vec3 zeros_vec3()
{
	vec3 ret;
	ret.data[0] = 0.f;
	ret.data[1] = 0.f;
	ret.data[2] = 0.f;

	return ret;
}

vec3 ones_vec3()
{
	vec3 ret;
	ret.data[0] = 1.f;
	ret.data[1] = 1.f;
	ret.data[2] = 1.f;

	return ret;
}

f32 norm_vec3(const vec3 a)
{
	return sqrtf(a.data[0]*a.data[0] + a.data[1]*a.data[1] + 
				 a.data[2]*a.data[2]);
}

vec3 neg_vec3(const vec3 a)
{
	vec3 ret;
	ret.data[0] = -a.data[0];
	ret.data[1] = -a.data[1];
	ret.data[2] = -a.data[2];

	return ret;
}

vec3 scalar_mul_vec3(const f32 scalar, const vec3 a)
{
	vec3 ret;
	ret.data[0] = scalar*a.data[0];
	ret.data[1] = scalar*a.data[1];
	ret.data[2] = scalar*a.data[2];

	return ret;
}

vec3 normalize_vec3(const vec3 a)
{
	const f32 norm_scalar = norm_vec3(a);

	if(equal_f32(norm_scalar,0.f))
	{
		printf("Can not normalize vector: (%f, %f, %f)",a.data[0],a.data[1],a.data[1]);
		return a;
	}
	return scalar_mul_vec3(1.f/norm_scalar,a);
}

vec3 add_vec3(const vec3 a, const vec3 b)
{
	vec3 ret;
	ret.data[0] = a.data[0] + b.data[0];
	ret.data[1] = a.data[1] + b.data[1];
	ret.data[2] = a.data[2] + b.data[2];

	return ret;
}

vec3 sub_vec3(const vec3 a, const vec3 b)
{
	vec3 ret;
	ret.data[0] = a.data[0] - b.data[0];
	ret.data[1] = a.data[1] - b.data[1];
	ret.data[2] = a.data[2] - b.data[2];

	return ret;
}

/*
 *  4D vector
 */
typedef struct vec4
{
	f32 data[4];
} vec4;

vec4 zeros_vec4()
{
	vec4 ret;
	ret.data[0] = 0.f;
	ret.data[1] = 0.f;
	ret.data[2] = 0.f;
	ret.data[3] = 0.f;

	return ret;
}

vec4 ones_vec4()
{
	vec4 ret;
	ret.data[0] = 1.f;
	ret.data[1] = 1.f;
	ret.data[2] = 1.f;
	ret.data[3] = 1.f;

	return ret;
}

f32 norm_vec4(const vec4 a)
{
	return sqrtf(a.data[0]*a.data[0] + a.data[1]*a.data[1] + 
				 a.data[2]*a.data[2] + a.data[3]*a.data[3]);
}

vec4 neg_vec4(const vec4 a)
{
	vec4 ret;
	ret.data[0] = -a.data[0];
	ret.data[1] = -a.data[1];
	ret.data[2] = -a.data[2];
	ret.data[3] = -a.data[3];

	return ret;
}

vec4 scalar_mul_vec4(const f32 scalar, const vec4 a)
{
	vec4 ret;
	ret.data[0] = scalar*a.data[0];
	ret.data[1] = scalar*a.data[1];
	ret.data[2] = scalar*a.data[2];
	ret.data[3] = scalar*a.data[3];

	return ret;
}

vec4 normalize_vec4(const vec4 a)
{
	const f32 norm_scalar = norm_vec4(a);

	if(equal_f32(norm_scalar,0.f))
	{
		printf("Can not normalize vector: (%f, %f, %f, %f)",a.data[0],a.data[1],a.data[2],a.data[3]);
		return a;
	}
	return scalar_mul_vec4(1.f/norm_scalar,a);
}

vec4 add_vec4(const vec4 a, const vec4 b)
{
	vec4 ret;
	ret.data[0] = a.data[0] + b.data[0];
	ret.data[1] = a.data[1] + b.data[1];
	ret.data[2] = a.data[2] + b.data[2];
	ret.data[3] = a.data[3] + b.data[3];

	return ret;
}

vec4 sub_vec4(const vec4 a, const vec4 b)
{
	vec4 ret;
	ret.data[0] = a.data[0] - b.data[0]; 
	ret.data[1] = a.data[1] - b.data[1]; 
	ret.data[2] = a.data[2] - b.data[2]; 
	ret.data[3] = a.data[3] - b.data[3]; 

	return ret;
}

// single precision matrices
/*
 *  3x3 matrix
 */
typedef struct mat3
{
	f32 data[3][3];
} mat3;

/*
 *  4x4 matrix
 */
typedef struct mat4
{
	f32 data[4][4];
} mat4;

