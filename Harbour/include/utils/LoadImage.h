//Copied from https://github.com/ocornut/imgui/wiki/image-loading-and-displaying-examples, for OpenGL users
//Modified to work with current setup

#pragma once
#include <glad/glad.h>
#include "imgui.h"

#define _CRT_SECURE_NO_WARNINGS
#include "stb/stb_image.h"

bool LoadTextureFromMemory(const void* data, size_t data_size, GLuint* out_texture, int* out_width, int* out_height);
bool LoadTextureFromFile(const char* file_name, GLuint* out_texture, int* out_width, int* out_height);
