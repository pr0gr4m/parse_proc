#ifndef __MMAP_H__
#define __MMAP_H__

#include "common.h"
#include <sys/mman.h>

char *mapped_file(const char *filename, size_t *psize);

#endif
