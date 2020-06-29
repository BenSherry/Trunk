#include "Error.hpp"

int main()
{
    doSomething();
	return 0;
}

// 1. run : a. gdb <binary file> b .run
// 2. show source code: list 1
// 3. add break point, break <line number>
// 4. check break point： info break
// 5. list parameter : print <parameter name>
// 6. create core dump file : ulimit -c unlimited 
// 7. list core file size :  ulimit -a
