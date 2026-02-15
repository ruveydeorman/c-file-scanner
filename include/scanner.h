#ifndef SCANNER_H
#define SCANNER_H
#include"filter.h"
//verilen dizinden başlayarak tüm dosyaları recurive olarak dolaşır ve filtre uygular
void scanner(const char* Path, struct filterConfig* fc) ;
#endif