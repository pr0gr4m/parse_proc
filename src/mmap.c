#include "mmap.h"

/*
 * param is char * type filename
 * return is file mapping address
 * it should be munmap
 */
char * mapped_file(const char *filename, size_t *psize)
{
	int fd;
	char *mapped;

	fd = open(filename, O_RDONLY);
	*psize = lseek(fd, 0, SEEK_END);

	mapped = mmap(NULL, *psize, PROT_READ, MAP_PRIVATE, fd, 0);

	if (mapped == MAP_FAILED)
		return NULL;

	return mapped;
}


