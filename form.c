#include "form.h"
#include <float.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

FormInstance* createForm(double r)
{
        FormInstance* f = malloc(sizeof(*f));
        if (!f) return NULL;

        return f;
}

void destroyForm(FormInstance *f)
{
        if (!f) return;

        if (f->system.buffer) 
	{
                free(f->system.buffer);
        }

        free(f);
}	

bool allocatePhysicsBuffers(FormInstance *f, uint32_t n)
{
        if (!f || !n) return false;

	f->system.count = n;

	uint32_t simdElements = SIMD_ALIGNMENT / sizeof(double);
        f->system.paddedCapacity = (n + (simdElements - 1)) & ~(simdElements - 1);

	uint32_t cap = f->system.paddedCapacity;
        size_t arraySize = cap * sizeof(double);
        size_t totalArrays = 14; 
        size_t totalBytes = totalArrays * arraySize;
        
        size_t remainder = totalBytes % SIMD_ALIGNMENT;
        if (remainder) totalBytes += (SIMD_ALIGNMENT - remainder);

        f->system.buffer = aligned_alloc(SIMD_ALIGNMENT, totalBytes);
        if (!f->system.buffer) return false;

	memset(f->system.buffer, 0, totalBytes);

        f->system.positionX     = f->system.buffer + (0 * cap);
        f->system.positionY     = f->system.buffer + (1 * cap);
        f->system.positionZ     = f->system.buffer + (2 * cap);

        f->system.velocityX     = f->system.buffer + (3 * cap);
        f->system.velocityY     = f->system.buffer + (4 * cap);
        f->system.velocityZ     = f->system.buffer + (5 * cap);

        f->system.accelerationX = f->system.buffer + (6 * cap);
        f->system.accelerationY = f->system.buffer + (7 * cap);
        f->system.accelerationZ = f->system.buffer + (8 * cap);

        f->system.normalX       = f->system.buffer + (9 * cap);
        f->system.normalY       = f->system.buffer + (10 * cap);
        f->system.normalZ       = f->system.buffer + (11 * cap);

        f->system.mass          = f->system.buffer + (12 * cap);
        f->system.weight        = f->system.buffer + (13 * cap);

	f->sh.particleOrder = NULL; 
        f->sh.hashKeys = NULL;

        return true;
}

void readParticles(FormInstance *f)
{
	if (!f || !f->system.count) return;

        uint32_t n = f->system.count;	
	uint32_t i = 0;
	double x, y, z;
	bool hasData = false;

	while (i < n && scanf("%lf %lf %lf", &x, &y, &z) == 3)
	{
		f->system.positionX[i] = x;
		f->system.positionY[i] = y;
		f->system.positionZ[i] = z;

		hasData = true;
		i++;
	}

	f->system.count = i;

	if (!hasData)
	{
		fprintf(stderr, "Warning: no particles read.\n");
		return;
	}
}
