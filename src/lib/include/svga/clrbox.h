#pragma once

#include <svga/box.h>
#include <svga/dirtybox.h>
#include <system/adeline_types.h>

// -----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
extern void ClearBox(void *dst, U32 *TabOffDst, T_BOX *box);
extern void SetClearColor(U32 color);

// =============================================================================
#ifdef __cplusplus
}
#endif
