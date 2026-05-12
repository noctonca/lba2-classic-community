#pragma once

// This header contains declarations private to SDL

#include <ail/sample.h>

#ifdef __cplusplus
extern "C" {
#endif

extern S32 sampleVolume;

void SfxLogEnable(int enable);
int SfxLogIsEnabled(void);

#ifdef __cplusplus
}
#endif
