#include "minishell.h"

//fichier de test pour les types de fichier avec stat()

int main(int argc, char **argv)
{
	struct stat statbuff;

	ft_memset(&statbuff, 0, sizeof(statbuff));
	printf("%d    return\n", stat(argv[1], &statbuff));
	printf("%ld   ID of device containing file\n", statbuff.st_dev);
	printf("%ld   Inode number\n", statbuff.st_ino);
	printf("%u   File type and mode\n", statbuff.st_mode);
	printf("%ld   Number of hard links\n", statbuff.st_nlink);
	printf("%u   User ID of owner\n", statbuff.st_uid);
	printf("%u   Group ID of owner\n", statbuff.st_gid);
	printf("%ld   Device ID (if special file)\n", statbuff.st_rdev);
	printf("%ld   Total size, in bytes\n", statbuff.st_size);
	printf("%ld   Block size for filesystem I/O\n", statbuff.st_blksize);
	printf("%ld   Number of 512B blocks allocated\n", statbuff.st_blocks);
	printf("\n\n%d", S_ISDIR(statbuff.st_mode));
}