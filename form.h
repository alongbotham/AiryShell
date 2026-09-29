#ifndef FORM_H
#define FORM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define SIMD_ALIGNMENT 64

typedef struct ParticleSystem
{
        double *buffer;
	    double *positionX;
	    double *positionY;
	    double *positionZ;
	    double *velocityX; 
	    double *velocityY; 
	    double *velocityZ;
	    double *accelerationX; 
	    double *accelerationY; 
	    double *accelerationZ;
	    double *normalX; 
	    double *normalY; 
	    double *normalZ;
	    double *mass;
	    double *weight;
	    uint32_t count;   
	    uint32_t paddedCapacity;
} ParticleSystem;

typedef struct FormInstance
{
        ParticleSystem system;
} FormInstance;

FormInstance* createForm(double r);
bool allocatePhysicsBuffers(FormInstance *f, uint32_t n);
void readParticles(FormInstance *f);
void destroyForm(FormInstance *f);

#endif
