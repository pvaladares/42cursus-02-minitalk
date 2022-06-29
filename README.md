# 42cursus-02-minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.


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
