/*
 *Copyright (C) 2016 Jussi Pakkanen
 *
 *This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include<libcob.h>
#include<stdio.h>
#include<assert.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

#include<ardulib.h>

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

void *cob_resolve_1(const char *funcname) {
    if(strcmp(funcname, "sleeping") == 0)
        return (void*) sleeping;
    if(strcmp(funcname, "setlcd") == 0)
        return (void*) setlcd;
    if(strcmp(funcname, "clearlcd") == 0)
        return (void*) clearlcd;
    assert(0);
    return 0;
}
