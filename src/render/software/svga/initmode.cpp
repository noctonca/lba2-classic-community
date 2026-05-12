#include <svga/initmode.h>

#include <svga/clip.h>
#include <svga/screen.h>
#include <svga/video.h>
#include <system/limits.h>
#include <system/logprint.h>
#include <system/window.h>

// -----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// --- Initialization ----------------------------------------------------------
bool InitGraphics(U32 resX, U32 resY) {
    if (resY > ADELINE_MAX_Y_RES) {
        return false;
    }

    LogPrintf("\nDesired resolution: %i*%i\n", resX, resY);

    if (!CreateWindowSurface(resX, resY)) {
        return false;
    }

    if (!CreateVideoSurface(resX, resY)) {
        return false;
    }

    if (!CreateScreenMemory(resX, resY)) {
        return false;
    }

    SetClipWindow(0, 0, resX - 1, resY - 1);
    SetClip(0, 0, resX - 1, resY - 1);

    return true;
}

void EndGraphics() {
    // Empty
}

// =============================================================================
#ifdef __cplusplus
}
#endif
