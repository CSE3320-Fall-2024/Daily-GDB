# Finding a segfault with ``` where ```

1. Compile the code with the -g flag

```
$ gcc main.c -g -o main
```

2. Start gdb

```
$ gdb main
```

3. Run your application by typing ```run```.

```
GNU gdb (GDB) Red Hat Enterprise Linux 10.2-6.el7
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from main...
(gdb) run
```

4. gdb will execute your program and display the segmentation fault.

```
Starting program: /home/tbakker/code/Daily-GDB/Day 1/main 
Missing separate debuginfos, use: debuginfo-install glibc-2.17-326.el7_9.x86_64

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7876f30 in feof () from /lib64/libc.so.6
(gdb)
```

5. Type ```where``` to display the backtrace.

```
(gdb) where
#0  0x00007ffff7876f30 in feof () from /lib64/libc.so.6
#1  0x00000000004011d9 in main (argc=1, argv=0x7fffffffded8) at main.c:17
(gdb)
```
Here you can see we segfaulted on line 17 of main.c

6. Type frame # to change to that stack frame.

```
(gdb) frame 1
#1  0x00000000004011d9 in main (argc=1, argv=0x7fffffffded8) at main.c:17
17	    while (!feof(fd)) 
(gdb)
```

7. Use p to print the values of any variable

```
(gdb) frame 1
#1  0x00000000004011d9 in main (argc=1, argv=0x7fffffffded8) at main.c:17
17	    while (!feof(fd)) 
(gdb) p fd
$1 = (FILE *) 0x0
(gdb)
```

We can see in this example that fd was a NULL pointer
