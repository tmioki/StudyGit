#include <stdio.h>

char *hello(char *arg)
{
	static char buf[4096];

	snprintf(buf, sizeof(buf), "hello, %s", arg);
	return buf;
}

// dlsymを使わずにこれを呼び出すのはCでは意味が無い.
// やりたかったのはpackageの汎用APIをdlsymなく呼び出したかった。
void libFunc(void)
{
	printf("libFunc called.\n");
}
