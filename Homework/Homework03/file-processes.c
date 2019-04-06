#include <sys/stat.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
static void
//cc file-processes.c && ./a.out
check (int test, const char * message, ...) {
    if (test) {
        va_list args;
        va_start (args, message);
        vfprintf (stderr, message, args);
        va_end (args);
        fprintf (stderr, "\n");
        exit (EXIT_FAILURE);
    }
}

int main () {
    int fd;
    struct stat s;
    int status;
    size_t size;
    const char * file_name = "file-ProcessTester.txt";
    const char * mapped;
    int i;
    fd = open ("file-ProcessTester.txt", O_RDONLY);
    check (fd < 0, "open %s failed: %s", file_name, strerror (errno));
    status = fstat (fd, & s);
    check (status < 0, "stat %s failed: %s", file_name, strerror (errno));
    size = s.st_size;
    mapped = mmap (0, size, PROT_READ, MAP_PRIVATE, fd, 0);
    check (mapped == MAP_FAILED, "mmap %s failed: %s",
           file_name, strerror (errno));
    for (i = 0; i < size; i++) {
        char c;
        c = mapped[i];
        if (! isupper(c)) {
            putchar (toupper(c));
        }
    }
    return 0;
}