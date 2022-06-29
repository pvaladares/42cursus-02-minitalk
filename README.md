# 42cursus-02-minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.

# Allowed libraries

The subject states that [libft](https://github.com/pvaladares/42cursus-00-Libft) library can be used.
> You can definitely use your libft.

Reading the subject it can be understood what functions may be the most useful to fulfill the requirements, as shown below:
> The server must be started first. After its launch, it has to print its PID.
> - The client takes two parameters:
>     - The server PID.
>     - The string to send.
- `ft_atoi()`, to convert the PID argument received from command line to integer type

To be noted that that as per the subject, it cannot be displayed char-by-char on the server-side, it must be displayed the string instead:
> Once the string has been received, the server must print it.

Therefore, it must be known in advance the length of the message so the server can allocate in memory as required
- `ft_strlen()`, to know the length of the message to be sent from client to server, and send it to server in advance for proper memory allocation
- `ft_calloc()`, in order to save the chars being received till the string is completed received on server side, so it can be then displayed as mentioned by the subject:

ft_putchar


# Allowed functions

> In order to complete the mandatory part, you are allowed to use the following functions:
> - write
> - [ft_printf](https://github.com/pvaladares/42cursus-01-ft_printf) and any equivalent YOU coded 
> - signal
```c
sig_t signal(int sig, sig_t func);
```
```man
This signal() facility is a simplified interface to the more general sigaction(2) facility.
(...)
some signals instead cause the process receiving them to be stopped, or are simply discarded
if the process has not requested otherwise.  
Except for the SIGKILL and SIGSTOP signals, the signal() function allows for a signal to be 
caught, to be ignored, or to generate an interrupt.
These signals are defined in the file <signal.h>:

           Name             Default Action       Description
     1     SIGHUP           terminate process    terminal line hangup
     2     SIGINT           terminate process    interrupt program 
(...)
     30    SIGUSR1          terminate process    User defined signal 1
     31    SIGUSR2          terminate process    User defined signal 2  

The sig argument specifies which signal was received.  
The func procedure allows a user to choose the action upon receipt of a signal.

The handled signal is unblocked when the function returns and the process continues 
from where it left off when the signal occurred.

For some system calls, if a signal is caught while the call is executing and the call is 
prematurely terminated, the call is automatically restarted.  
Any handler installed with signal(3) will have the SA_RESTART flag set, 
meaning that any restartable system call will not return on receipt of a signal.  

The affected system calls include read(2), write(2), sendto(2), recvfrom(2), sendmsg(2), 
and recvmsg(2) on a communications channel or a low speed device and during a ioctl(2) or wait(2).
However, calls that have already committed are not restarted, but instead return a partial success
(for example, a short read count).  
These semantics could be changed with siginterrupt(3).
     
See sigaction(2) for a list of functions that are considered safe for use in signal handlers.

The previous action is returned on a successful call.  
Otherwise, SIG_ERR is returned and the global variable errno is set to indicate the error.
     
macOS 12.4                      June 7, 2004                      macOS 12.4
```


> - sigemptyset
> - sigaddset
```c
int sigemptyset(sigset_t *set);
int sigaddset(sigset_t *set, int signo);
```
```man
These functions manipulate signal sets, stored in a sigset_t.
sigemptyset() must be called for every object of type sigset_t before any other use of the object.

The sigemptyset() function initializes a signal set to be empty.

The sigaddset() function adds the specified signal signo to the signal set.

These functions are provided as macros in the include file <signal.h>.
Actual functions are available if their names are undefined (with #undef name).

Functions return 0.

macOS 12.4          June 4, 1993          macOS 12.4
```

```man

```
> - sigaction
> - kill
> - getpid
> - malloc
> - free
> - pause
> - sleep
> - usleep
> - exit



# Considerations about the [subject](pdf/42cursus_Minitalk_v2.pdf)


https://apple.stackexchange.com/questions/51119/whats-the-maximum-pid-for-mac-os-x/51124#51124
https://opensource.apple.com/source/xnu/xnu-6153.141.1/bsd/sys/proc_internal.h.auto.html




## Using `kill()` to check the PID server input

```man
DESCRIPTION
     The kill() function sends the signal specified by sig to pid, a process or
     a group of processes.  Typically, Sig will be one of the signals specified
     in sigaction(2).  A value of 0, however, will cause error checking to be
     performed (with no signal being sent).  This can be used to check the
     validity of pid.
````
  
This is a nice finding to check the validity of the PID in a robust way, rather than just checking if all the chars are digits.
```c
if (kill(atoi(argv[1]), 0) < 0)
{
 ft_printf("client error: PID is invalid\n");
 exit(EXIT_FAILURE);
}
```
  
```man
     If pid is greater than zero:
             Sig is sent to the process whose ID is equal to pid.

     If pid is zero:
             Sig is sent to all processes whose group ID is equal to the process
             group ID of the sender, and for which the process has permission;
             this is a variant of killpg(2).

     If pid is -1:
             If the user has super-user privileges, the signal is sent to all
             processes excluding system processes and the process sending the
             signal.  If the user is not the super user, the signal is sent to
             all processes with the same uid as the user, excluding the process
             sending the signal.  No error is returned if any process could be
             signaled.
```         
             

## `PID_MAX`

From subject it can be read the following:
> Your server should be able to receive strings from several clients in a row without needing to restart.

It may be interpretated a row means that it should be sequential, meaning a new client should only start sending a message, after the current client had finished.
Something like the following:

- server is started and shows its PID
- client #1 is started and sends a message to server
- after server displays the message, client #2 is started and sends a message to server

From [here](https://opensource.apple.com/source/xnu/xnu-6153.141.1/bsd/sys/proc_internal.h.auto.html)
```c
/*
 * We use process IDs <= PID_MAX; PID_MAX + 1 must also fit in a pid_t,
 * as it is used to represent "no process group".
 */
 
#define PID_MAX         99999
```

Testing locally with bash script
```bash
#!/bin/bash

pid=0
for i in {1..100000}; do
  : &
  if [ $! -lt $pid ]; then
    echo "Min pid: $!"
    echo "Max pid: $pid"
    break
  fi
  pid=$!
done
```
The resulting confirms the [original post](https://apple.stackexchange.com/questions/51119/whats-the-maximum-pid-for-mac-os-x/51124#51124))
> Min pid: 100
>
> Max pid: 99998




# Resources
- [Sending and Handling Signals in C (kill, signal, sigaction)](https://www.youtube.com/watch?v=83M5-NPDeWs)
- [Communicating between processes using signals](https://www.youtube.com/watch?v=PErrlOx3LYE)
- [Good reading about how to approach the project](https://github.com/mlanca-c/Minitalk/wiki)
- [Checking for Pending Signals](https://www.gnu.org/software/libc/manual/html_node/Checking-for-Pending-Signals.html)
- [Introduction To Unix Signals Programming](http://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html) and [SIGACTION](http://www.cs.kent.edu/~ruttan/sysprog/lectures/signals/sigaction.html)
