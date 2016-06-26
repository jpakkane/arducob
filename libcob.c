#include<libcob.h>
#include<stdio.h>
#include<assert.h>

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
    printf("x\n");
}
