#include "form.h"
#include "plot.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[argc+1])
{
        if (argc < 2)
        {
                fprintf(stderr, "Usage: %s <number_of_particles>\n", argv[0]);
                return EXIT_FAILURE;
        }

        double r = 0.5;
    
        double timeStep = 0.01;

        unsigned long parsedNum = strtoul(argv[1], nullptr, 10);

        if (parsedNum == 0 || parsedNum > UINT32_MAX)
        {
                fprintf(stderr, "Error: Invalid number of particles. Must be between 1 and %u\n", UINT32_MAX);
                return EXIT_FAILURE;
        }

        uint32_t n = (uint32_t)parsedNum;

        FormInstance *f = createForm(r);

        if (!f)
        {
                fprintf(stderr, "Failed to allocate FormInstance.\n");
                return EXIT_FAILURE;
        }

        if (!allocatePhysicsBuffers(f, n))
        {
                fprintf(stderr, "Failed to allocate form buffers.\n");
                destroyForm(f); 
                return EXIT_FAILURE;
        }

	readParticles(f);

	/* Map 2-manifold to a planar region */

	/* Find equilibrium flow on region */

	/* Use flow at final time to map to 2-manifold */

	/* Increase normal extent of shell to get thickness */

	/* Decompose shell into a set of elements; pipe these into
	 * a .txt file for permanent storage */

        destroyForm(f);

        return EXIT_SUCCESS;
}
