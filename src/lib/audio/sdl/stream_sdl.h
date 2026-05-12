#pragma once

// This header contains declarations private to SDL

#include <ail/stream.h>

#ifdef __cplusplus
extern "C" {
#endif

extern S32 streamVolume;

void MusicLogEnable(int enable);
int MusicLogIsEnabled(void);

#ifdef __cplusplus
}
#endif
