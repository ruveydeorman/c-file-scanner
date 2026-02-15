#include"include/filter.h"
#include<stdbool.h>
#include<string.h>
bool matchType(struct filterConfig* fc,struct fileInfo* fi){
    if(!fc || !fi){  //pointerlarda ! ile null olup olmdığına bakıyoruz
        return false;
    }
    else if(fc->type == ANY){
        return true;
    }
    else if(fc->type == fi->type){
        return true;
    }
    
    return false;
 }
 bool matchSize(struct filterConfig* fc,struct fileInfo* fi){
    if(!fc || !fi){
        return false;
    }
    if(fc->minFileSize >= 0){
        if(fi->size < fc->minFileSize){
            return false;
        }
    }
    if(fc->maxFileSize >=0){
        if(fi->size > fc->maxFileSize){
            return false;
        }
    }
    return true;
 }
 bool matchDate(struct filterConfig* fc,struct fileInfo* fi){
    if(!fc || !fi){
        return false;
    }
    if(fc->earlyDate > 0){
        if(fi->mtime < fc->earlyDate){
            return false;
        }
    }
    if(fc->lastDate > 0 ){
        if(fi->mtime > fc->lastDate){
            return false;
        }
    }
    return true;
 }
 bool matchPattern(struct filterConfig* fc,struct fileInfo* fi){
    if(!fc || !fi){
        return false;
    }
   if(fc->patternName == NULL){
        return true;
   }
   if(strstr(fi->fileName,fc->patternName)==NULL){
        return false;
   }
   return true;
 }
 bool filterMatch(struct filterConfig* fc, struct fileInfo* fi){
    if(!fc || !fi){
        return false;
    }
    if(! matchType(fc,fi)){
        return false;
    }
    if(! matchSize(fc,fi)){
        return false;
    }
    if( ! matchDate(fc,fi)){
        return false;
    }
    if(! matchPattern(fc,fi)){
        return false;
    }
    return true;

 