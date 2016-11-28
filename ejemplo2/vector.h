#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct TVector{
	int x;
	int y;
	int z;
} Vector;

#ifndef __cplusplus
extern "C"{
#endif
	extern Vector cross(Vector op1, Vector op2);
}
