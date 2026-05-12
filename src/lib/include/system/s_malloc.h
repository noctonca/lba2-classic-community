#pragma once

#include <system/adeline_types.h>

// -----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
void SafeErrorMallocMsg();
void SafeFree(void *ptr, char *file, U32 line);
void *SafeMshrink(void *ptr, U32 taille, char *file, U32 line);

// =============================================================================
#ifdef __cplusplus
}
#endif
