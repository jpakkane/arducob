#include<libcob.h>
#include<stdio.h>
#include<assert.h>
#include<stdarg.h>
#include<stdlib.h>

struct cob_module *cob_current_module;
int cob_initialized = 1;
int cob_save_call_params;
int cob_call_params;

int unlikely(int f) {
    return f;
}

void cob_fatal_error (const unsigned int i) {
    printf("Cobol errored: %d\n", i);
    assert(0);
}

void cob_check_version(const char *a, const char *b, const int c) {
}

void cob_set_cancel(const char *a, void *b, void *c) {
}

void cob_display(const int a, const int b, const int c, ...) {
    va_list arguments;
    cob_field *cf;

    va_start(arguments, c);
    cf = va_arg ( arguments, cob_field* );
    va_end (arguments);
    printf("%s\n", cf->data);
}

void *cob_malloc (const size_t i) {
    printf("Cob_malloc called.\n");
    return malloc(i);
}

extern int cob_cmp_u32_binary(const unsigned char *e, const int i) {
    int val= *(const int *)(e);
    if(val < i)
        return -1;
    if(val > i)
        return 1;
    return 0;
}
