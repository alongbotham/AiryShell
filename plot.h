#ifndef PLOT_H
#define PLOT_H

#include <GLFW/glfw3.h>

typedef enum {
        PLOT_STATE_INIT,
        PLOT_STATE_RUNNING,
        PLOT_STATE_PAUSED,
        PLOT_STATE_CLOSED
} plotState;

void initPlotWindow(int width, int height);
void shutdownPlot(void);
plotState getPlotState(void);
void renderShellFrame(void);
void plotStresses(void);
void visualizeShell(void);

#endif
