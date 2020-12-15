#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float  f32;
typedef double f64;

f32 abs_f32(const f32 x)
{
	return (x < 0.f) ? -x : x;
}

f64 abs_f64(const f64 x)
{
	return (x < 0.) ? -x : x; 
}

bool equal_f32(const f32 x, const f32 y)
{
	return abs_f32(x - y) < 1e-6f; 
}

bool equal_f64(const f64 x, const f64 y)
{
	return abs_f64(x - y) < 1e-16; 
}