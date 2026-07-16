# Minitalk

## executable :
- client
- server

- one global variable per program (1 client, 1 server)

## function allowed
```
write #include "unistd.h"
ft_printf or any equivalent YOU coded
malloc
free
#include <stdlib.h>

---

signal
#include <signal.h>
void (*signal(int sig, void (*func)(int)))(int);
Quand je recoit tel signal, je veux executer telle function
signal(SIGTRUC, handle_truc);

---

sigaction
#include <signal.h> int sigaction(int signum, const struct sigaction *_Nullable restrict act,
                     struct sigaction *_Nullable restrict oldact);
Quand ce signal arrive, exécute ce handler, mais avec des options précises et un comportement garanti.

---

sygemptyset
#include <signal.h> int sigemptyset(sigset_t *set);
initializes the signal set pointed to by set

---

sigaddset
#include <signal.h>
int sigaddset(sigset_t *set, int signo);
adds the individual signo specified by signo to the set pointed to by set

---

kill
#include <signal.h>  system call can be used to send any signla to any process group or process
int kill(pid_t pid, int sig)

---

getpid
#include <unistd.h> pid_t getpid(void);
return the process ID of the calling  process

---

pause
#include <unistd.h> int pause(void);
suspend the calling thread until delibery of a signal whose action is
either to execute a signal-catching function or to terminate the process.

---

sleep
#include <unistd.h> unsigned int sleep(unsigned int seconds);
causes the calling thread to sleep either until the number
of real-time seconds specified in seconds have elapsed or until a
signal arrives which is not ignored.

---

usleep
#include <unistd.h> int usleep(useconds_t usec);
function suspends execution of the calling thread for
(at least) usec microseconds

---

exit
#include <stdlib.h> void exit(int status);
normal process termination and the least significant byte of status is returned to the parent
```


## Mandatory
Create a communication program in the form of a client and a server

The server must be started first, print its PID in launch

The client takes two params (server PID, string to send)
./client PID "Hello"

The client must send the specified string to the server.
Once received, the server must print it.

The server must display the string without delay. If it seems slow, it is likely too
slow.
Your server should be able to receive strings from several clients in a row without
needing to restart

Communication between the client and server must exclusively use UNIX signals.
You can only use these two signals: SIGUSR1 and SIGUSR2.
SIGUSR1      P1990      Term    User-defined signal 1      10
SIGUSR2      P1990      Term    User-defined signal 2      12

## Bonus
The server must acknowledge each received message by sending a signal to the
client.
Unicode characters support