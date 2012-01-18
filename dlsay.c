#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
	void *handle;
	char *(*msg)();
	char *error;

	handle = dlopen(argv[1], RTLD_LAZY);
	if(handle == NULL)
	{
		fprintf(stderr, "load error %s: %s\n", argv[1], dlerror());
		return 1;
	}
	dlerror();
	msg = (char *(*)())dlsym(handle, argv[2]);
	if((error = dlerror()) != NULL)
	{
		fprintf(stderr, "dlsym error %s: %s\n", argv[2], error);
		return 1;
	}
	printf("%s\n", (*msg)(argc > 3 ? argv[3] : NULL));
	dlclose(handle);
	return 0;
}
