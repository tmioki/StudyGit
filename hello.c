#include <stdio.h>

char *hello(char *arg)
{
	static char buf[4096];

	snprintf(buf, sizeof(buf), "hello, %s", arg);
	return buf;
}

// dlsym���g�킸�ɂ�����Ăяo���̂�C�ł͈Ӗ�������.
// ��肽�������̂�package�̔ėpAPI��dlsym�Ȃ��Ăяo�����������B
void libFunc(void)
{
	printf("libFunc called.\n");
}
