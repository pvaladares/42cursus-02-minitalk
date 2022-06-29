# 42cursus-02-minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.




https://apple.stackexchange.com/questions/51119/whats-the-maximum-pid-for-mac-os-x/51124#51124
https://opensource.apple.com/source/xnu/xnu-6153.141.1/bsd/sys/proc_internal.h.auto.html



## Value of `PID_MAX`

From [here](https://opensource.apple.com/source/xnu/xnu-6153.141.1/bsd/sys/proc_internal.h.auto.html)
```c
/*
 * We use process IDs <= PID_MAX; PID_MAX + 1 must also fit in a pid_t,
 * as it is used to represent "no process group".
 */
 
#define PID_MAX         99999
```

Testing locally with bash script
```shell
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
Local test had the following output, which confirms the original post
> Min pid: 100
>
> Max pid: 99998




# Resources
- [Sending and Handling Signals in C (kill, signal, sigaction)](https://www.youtube.com/watch?v=83M5-NPDeWs)
- [Communicating between processes using signals](https://www.youtube.com/watch?v=PErrlOx3LYE)
- [Good reading about how to approach the project](https://github.com/mlanca-c/Minitalk/wiki)
- [Checking for Pending Signals](https://www.gnu.org/software/libc/manual/html_node/Checking-for-Pending-Signals.html)
- [Introduction To Unix Signals Programming](http://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html) and [SIGACTION](http://www.cs.kent.edu/~ruttan/sysprog/lectures/signals/sigaction.html)
