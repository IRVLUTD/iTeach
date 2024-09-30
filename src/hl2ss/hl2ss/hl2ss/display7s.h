
#pragma once

#include "types.h"

void DrawDigits(wchar_t const* str, int x, int y, int glyph_width, int glyph_kerning, int glyph_height, int glyph_unit_width, int glyph_unit_height, int image_width, int image_height, u32 color, u32* buffer);
void DrawDigits(char const* str, int x, int y, int glyph_width, int glyph_kerning, int glyph_height, int glyph_unit_width, int glyph_unit_height, int image_width, int image_height, u32 color, u32* buffer);
