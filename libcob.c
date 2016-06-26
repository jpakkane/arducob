#include<libcob.h>
#include<stdio.h>
#include<assert.h>
#include<stdarg.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

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

extern int cob_cmp_u32_binary(const unsigned char *e, const int i) {
    int val= *(const int *)(e);
    if(val < i)
        return -1;
    if(val > i)
        return 1;
    return 0;
}

void sleeping() {
    usleep(500000);
}

void setlcd(const int *index, const int *offset, const char *msg) {
    for(int i=0; i < *offset; i++) {
        printf(" ");
    }
    printf("%s\n", msg);
}

void clearlcd() {
}

void *cob_resolve_1(const char *funcname) {
    if(strcmp(funcname, "sleeping") == 0)
        return (void*) sleeping;
    if(strcmp(funcname, "setlcd") == 0)
        return (void*) setlcd;
    if(strcmp(funcname, "clearlcd") == 0)
        return (void*) clearlcd;
    assert(0);
}
