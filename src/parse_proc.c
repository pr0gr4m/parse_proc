#include "parse_proc.h"
#include "mmap.h"

static DIR * open_proc(void)
{
	DIR *dp = NULL;

	if ((dp = opendir(TARGET)) == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	return dp;
}

static char * cpy_delim_space(char *src, char *dst)
{
	char *s;
	for (s = src; *s && *s != 0x20; s++, dst++)
	{
		*dst = *s;
	}
	return ++s;
}

static char * pass_delim_space(char *s)
{
	char *n;
	for (n = s; *n && *n != 0x20; n++)
	{
		// do nothing
	}
	if (*n)
	{
		return ++n;
	}
	else
	{
		return NULL;
	}
}

static int parse_stat(const char *filename, char *pname)
{
	char *p;
	char buf[BUF_LEN] = { 0, };
	char PID[BUF_LEN] = { 0, };
	char PPID[BUF_LEN] = { 0, };
	int fd;

	fd = open(filename, O_RDONLY);
	read(fd, buf, BUF_LEN);

	p = cpy_delim_space(buf, PID);
	p = cpy_delim_space(p, pname);
	p = pass_delim_space(p);
	p = cpy_delim_space(p, PPID);
	printf("%10s%10s\t", PID, PPID);

	close(fd);
	return RET_SUC;
}

static int parse_cmd(const char *filename, const char *pname)
{
	char CMD[BUF_LEN] = { 0, };
	int fd;
	size_t ret_read;
	fd = open(filename, O_RDONLY);
	ret_read = read(fd, CMD, BUF_LEN);
	if (ret_read == 0)
	{
		printf("%s", pname);
	}
	printf("%s", CMD);
	close(fd);
	return RET_SUC;
}

static int print_proc(const char *dname)
{
	char file_stat[BUF_LEN] = { 0, };
	char file_cmd[BUF_LEN] = { 0, };
	char pname[BUF_LEN] = { 0, };

	sprintf(file_stat, "%s/%s/%s", TARGET, dname, "stat");
	sprintf(file_cmd, "%s/%s/%s", TARGET, dname, "cmdline");

	parse_stat(file_stat, pname);
	parse_cmd(file_cmd, pname);
	putchar('\n');

	return RET_SUC;
}

static int read_proc(DIR *dp)
{
	struct dirent *entry = NULL;
	struct stat buf;

	printf("%10s%10s\t%s\n",
			"PID", "PPID", "CMD");

	while ((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &buf);

		if (S_ISDIR(buf.st_mode))
		{	// if directory
			if (*(entry->d_name) >= '0' &&
					*(entry->d_name) <= '9')
			{	// PID directory
				print_proc(entry->d_name);
			}
		}
	}

	return RET_SUC;
}

int parse_proc(void)
{
	DIR *dp = NULL;

	dp = open_proc();
	read_proc(dp);
	closedir(dp);
	return RET_SUC;
}
