#ifndef __OSDEP_H
#define __OSDEP_H
// OSDEP includes
// should be good for most SDL ports

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#define cprintf printf

#define _MAX_PATH PATH_MAX
#define _MAX_DRIVE 26
#define _MAX_DIR 2048
#define _MAX_FNAME 256
#define _MAX_EXT 64

#include <SDL.h>


#define far /*far*/
#define __far /*__far*/
#define __interrupt /* __interrupt */
#define __loadds /* __loadds */
#define _HARDERR_FAIL 0
#define __stdcall /* __stdcall */

///////////////////////////////////////////////////
// DEFINED IN osdep.cpp
///////////////////////////////////////////////////

extern char * strupr(char *string);
extern char * strlwr(char *string);

extern void _dos_setdrive( unsigned __drivenum, unsigned *__drives );
char * itoa(long n, char *buf, int len);

#define ltoa itoa 
#define stdprn stdout
#define stricmp strcasecmp


extern void _splitpath (
   const char *path,  // Path Input
   char *drive,       // Drive     : Output
   char *dir,         // Directory : Output
   char *fname,       // Filename  : Output
   char *ext          // Extension : Output
);

extern char *_fullpath(char *_FullPath,const char *_Path,size_t _SizeInBytes);


// dos directory stuff

#include <dirent.h>

struct find_t {
  char reserved[21];
  unsigned char attrib;
  unsigned short wr_time;
  unsigned short wr_date;
  unsigned long size;
  char name[256];
};

#define _A_NORMAL (0x00)
//Normal file (no read/write restrictions)

#define _A_RDONLY (0x01)
//Read only file

#define _A_HIDDEN (0x02)
//Hidden file

#define _A_SYSTEM (0x04)
//System file

#define _A_VOLID (0x08)
//Volume ID file

#define _A_SUBDIR (0x10)
//Subdirectory

#define _A_ARCH (0x20)
//Archive file

unsigned int _dos_findfirst(char *name, unsigned int attr, 
                            struct find_t *result);
unsigned int _dos_findnext(struct find_t *result);

unsigned int _dos_setfileattr(const char *filename, unsigned int attr);



#endif // __OSDEP_H
