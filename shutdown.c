// Shuts down the system by using the halt() system call
// to send a special signal to QEMU.
// Added by Bill Katsak
// Copied from: http://pdos.csail.mit.edu/6.828/2012/homework/xv6-syscall.html

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
	halt();
	exit();
}