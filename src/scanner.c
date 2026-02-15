#include"include/scanner.h"
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio.h>
#include<linux/limits.h>
 
void scanner(const char* Path,struct filterConfig* fc){
    int counter =0;
    if(!Path || ! fc){
        return;
    }
    DIR* dir = opendir(Path);
    if(!dir){
        return ;
    }
    struct dirent* entry ; //dizindeki her bir girdiyi temsil eden değişken
    while((entry=readdir(dir))!=NULL){
        if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0){ //strcmp boolen döndürmez eşitse 0 döner
            continue;
        }
        char fullPath[PATH_MAX];
        snprintf(fullPath,PATH_MAX,"%s/%s",Path,entry->d_name);//bu fonksiyon bir char dizisinin içine yazar ekrana basmaz.belirtilen buffer içine taşma olmadan yazar
        struct stat st;
        if(stat(fullPath,&st)==-1){
            continue;//hata varsa bu entryi atlar
        }
        
        if(S_ISDIR(st.st_mode)){
            scanner(fullPath,fc);
        }else{
            struct fileInfo fi;
            fi.fileName = entry->d_name;
            fi.size = st.st_size;
            fi.mtime=st.st_mtime;
            fi.type= REGULAR_FILE;
            if(filterMatch(fc,&fi)){
                printf("%s\n",fullPath);
                counter++;
            }
            
        }

    }
    closedir(dir);
    printf("[%s] in this directory found %d results.\n",Path,counter);
    return;
    
}