#ifndef FILTER_H
#define FILTER_H
#include<stdbool.h>
#include<time.h>
#include <sys/types.h>
#include <string.h>


 typedef enum {
    REGULAR_FILE,
    DIRECTORY,
    ANY

}FileType;
struct filterConfig{
    FileType type;
    off_t minFileSize;
    off_t maxFileSize;
    time_t earlyDate;
    time_t lastDate;
    char* patternName; 
};

struct fileInfo{
    char* fileName;
    FileType type;
    off_t size;  //dosya boyutu off_t olarak alınır 
    time_t mtime;
};

#endif
