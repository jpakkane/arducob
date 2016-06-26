#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void libsetup();

void sleeping();

void setlcd(const int *index, const int *offset, const char *msg);

void clearlcd();

#ifdef __cplusplus
}
#endif
