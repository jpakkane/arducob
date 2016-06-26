#pragma once

#include<stdlib.h>

/* This is included before system libcob.h. */

/* This is the most minimal Cobol standard library possible to
 * be able to run programs on an Arduino
 */

#define COB_MAX_FIELD_PARAMS 64

typedef struct {
    unsigned char	type;
    unsigned char	digits;
    signed char	scale;
    unsigned char	flags;
    const char	*pic;
} cob_field_attr;

typedef struct {
    size_t size;
    unsigned char *data;
    const cob_field_attr *attr;
} cob_field;

struct cob_module {
    struct cob_module *next;
    const unsigned char *collating_sequence;
    cob_field *crt_status;
    cob_field *cursor_pos;
    cob_field **cob_procedure_parameters;
    const unsigned char display_sign;
    const unsigned char decimal_point;
    const unsigned char currency_symbol;
    const unsigned char numeric_separator;
    const unsigned char flag_filename_mapping;
    const unsigned char flag_binary_truncate;
    const unsigned char flag_pretty_display;
    const unsigned char spare8;
};

#define COB_FERROR_INITIALIZED  0
#define COB_FERROR_CODEGEN  1
#define COB_FERROR_CHAINING 2
#define COB_FERROR_STACK    3

extern struct cob_module *cob_current_module;
extern int cob_initialized;
extern int cob_save_call_params;
extern int cob_call_params;

void cob_fatal_error (const unsigned int);
int unlikely(int f);
void cob_check_version(const char *, const char *, const int);
void cob_set_cancel(const char *, void *, void *);
extern void cob_display (const int, const int, const int, ...);
