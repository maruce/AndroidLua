#ifndef __LUA_FILE_IO_H__
#define __LUA_FILE_IO_H__

extern int file_util_internal_exists(const char * filepath);
extern int file_util_external_exists(const char * filepath);
extern void * file_util_internal_read(const char * filepath, long &readlen);
extern void * file_util_external_read(const char * filepath, long &readlen);

#endif // __LUA_FILE_IO_H__
