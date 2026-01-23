# pipex

handle multiple pipes
support << and >> first params "here_doc"
```
./pipex file1 cmd1 cmd2 cmd3 ... file2

versin shell cmd
 < file1 cmd1 | cmd2 > file2

#exe: 
./pipex infile "ls -l" "wc -l" outfile
< infile ls -l | wc -l > outfile

./pipex infile "grep a1" "wc -w" outfile
< infile grep a1 | wc -w > outfile


./pipex here_doc LIMITER cmd cmd1 file
cmd << LIMITER | cmd1 >> file

```

## External func

**open()** : system call opens the file specified by path
return file descriptor non negative integer
on error -1 is returned and errno is set to indicate the error
```c
#include <fcntl.h>
int open(const char *path, int flags, .../* mode_t mode */ ); 

// flags
// O_CREAT if file does not  exist
// O_RDONLY, O_WRONLY, or O_RDWR.  These request opening the file
//  read-only, write-only, or read/write, respectively.
```

**close()** : close a file descriptor
return 0 on sucess
on error -1 is returned and errno

```c
#include <unistd.h>

int close(int fd);
```

**read()** : read from a file descriptor, attempts to read up to 
count bytes from fd into the buffer starting at buf
return non negative integer indicating the nb of bytes actually read
if nbyte == 0, return -1, errors 
read keep the offset when you open the file
end of file, return 0;
on errors, return -1 and set errno


```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t nbyte);
```


**write()** : write on a file, attemps to write nbyte bytes from the
buffer pointed to by buf to the file associated with fd
return nb of bytes actually written to the file associated with fd
this nb shall never be greater than nbyte
if nbyte == 0, return -1, errors
on errors, return -1 and errno

```c
#include <unistd.h>

ssize_t write(int fildes, const void *buf, size_t nbyte);
```

**malloc()** : allocates size bytes and returns a pointer to the allocated
memory
if size is 0, return a unique pointer value that can later be free
return pointer to the allocated memory
on error, return NULL and set errno  (more than PTRDIFF_MAX bytes -> error)

```c
#include <stdlib.h>

void *malloc(size_t size);
```

**free()** : frees the memory space pointed to by p
if p has already been freed, undefined behavior occurs
if p is NULL, no operation is performed
return no value and preserves errno

```c
#include <stdlib.h>

void free(void *_Nullable p);
```

**perror()** : print a system error message on standard error
       describing the last error encountered during a call to a system or
       library function.
 To be of most use, the argument string should include the name of
       the function that incurred the error.

```c
#include <stdio.h>

void perror(const char *s);
```

**strerror()** : returns a pointer to a string that decribes the error
code poased in the arg errnum.
return the appropriate error description string or an "Unknown error nnn"
if the error nb is unknown.

```c
#include <string.h>

char *strerror(int errnum);
```

**access()** : determine accessibility of a file descriptor
check the file named by the pathname pointed to by the path argument for
accessibility according to the bit pattern contained in amode
The value of amode is either the bitwise-inclusive OR of the
access permissions to be checked (R_OK, W_OK, X_OK) or the
existence test (F_OK)
return 0;
otherwise

```c
#include <unistd.h>

int access(const char *path, int amode);
```

**dup()** : duplicate an open fd
system choice df and branch to same source of fildes

```c
#include <unistd.h>

int dup(int fildes);
```

**dup2()** : shall cause the fd fildes2 to refer to the same open fd
You pick fd and if already exist, the system debranch before branch to source of fildes
as the fd fildes and to share any locks. and shall return fildes2
if fildes2 is already a valid open fd it shall be closed first,
unless fildes is equal to fildes2 in which case dup2() shall return fildes2
without closing it;
if the close operation fails to close fildes2, dup2 shall return -1 and shall
not close fildes2
if fildes < 0 or >= OPEN_MAX return -1 with errno set to EBADF
Upon successful completion a non-negative integer, namely the file
descriptor, shall be returned; otherwise, -1 shall be returned and
errno set to indicate the error.
```c
#include <unistd.h>

 int dup2(int fildes, int fildes2);
```

**execve()** : execute program referred to by path (binary executable)
or script start with #!interpreter
on success not return
on error return -1 and errno set

```c
#include <unistd.h>

int execve(const char *path, char *const _Nullable argv[],
           char *const _Nullable envp[]);
```

**exit()** : cause normal process termination
no return 
```c
#include <stdlib.h>

[[noreturn]] void exit(int status);
```

**fork()** : create a child process
by duplicating the calling process. the new process is referred to as
the child process. the calling process is referred to as the parent process
Le PPID (Parent Process ID) du fils est identique au PID du parent.
on success, return PID of the child process in parent and 0 in the child.
on failure, return -1 to parent, no child process is created and errno is set

```c
#include <unistd.h>

pid_t fork(void);
```

**pipe()** : create pipe, a unidirectional data channel that can be used
for interprocess communication.
The array pipefd is used to return two file descriptors referring to the
ends of the pipe.
on success return 0
on error return -1 and set errno and pipefd is left unchanged

```c
#include <unistd.h>

int pipe(int pipefd[2]);
```

**unlink()** : delete a name and possibly the file it refers
If that name was the last link to a file and no processes have the file open, the file
is deleted and the space it was using is made available for reuse.
 On success, zero is returned.  
On error, -1 is returned, and errno is set to indicate the error.

```c
#include <unistd.h>

int unlink(const char *path);
```

**wait(), waitpid()** : wait for process to change state
used to wait for state changes in a child of the calling process, 
and obtain information about the child whose state has changed
A state change is considered to
be: the child terminated; the child was stopped by a signal; 
or the child was resumed by a signal.
wait(): on success, returns the process ID of the terminated
       child; on failure, -1 is returned.
```c
#include <sys/wait.h>

pid_t wait(int *_Nullable wstatus);
pid_t waitpid(pid_t pid, int *_Nullable wstatus, int options);
```
The waitpid() system call suspends execution of the calling thread
until a child specified by pid argument has changed state.  By
default, waitpid() waits only for terminated children, but this
behavior is modifiable via the options argument

waitpid(): on success, returns the process ID of the child whose
       state has changed; if WNOHANG was specified and one or more
       child(ren) specified by pid exist, but have not yet changed state,
       then 0 is returned.  On failure, -1 is returned.
