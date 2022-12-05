#ifndef COMMON_H
#define COMMON_H

#include "raylib.h"
#include "raymath.h"

#ifdef DEBUG
	#include "stdio.h"
#endif

/// 1<<8 == 256 just for fun
static const int screen_width = 1<<8;
static const int screen_height= 1<<8;

/// Colors
#define COLOR_BACKGROUND	(Color) {40, 40, 40, 255}
#define COLOR_PLAYER		(Color) {0, 228, 48, 255}
#define COLOR_STAR			(Color) {0xeb, 0xdb, 0xb2, 255}

#endif // COMMON_H
