//
//  main.c
//  myuuid
//
//  Created by mac on 2017/7/6.
//  Copyright © 2017年 zhengbensuyuan. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <uuid/uuid.h>



#define UUID128 unsigned __int128

static char DIGITS_64[64] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
    '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
    'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
    'Z', '_', '-'};

// hex 转 94 进制对应表
static char DIGITS_94[94] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
    '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
    'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
    'Z', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',',
    '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', ']', '\\',
    '^', '_', '`', '{', '|', '}', '~'};

static char chars[] = {
    'a','b','c','d','e','f','g','h',
    'i','j','k','l','m','n','o','p',
    'q','r','s','t','u','v','w','x',
    'y','z','0','1','2','3','4','5',
    '6','7','8','9','A','B','C','D',
    'E','F','G','H','I','J','K','L',
    'M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z'
};

void uuid(char *result, int len)
{
    unsigned char uuid[16];
    char output[24];
    const char *p = (const char*)uuid;
    
    uuid_generate(uuid);
    memset(output, 0, sizeof(output));
    
    int i, j;
    for (j = 0; j < 2; j++)
    {
        unsigned long long v = *(unsigned long long*)(p + j*8);
        int begin = j * 10;
        int end =  begin + 10;
        
        for (i = begin; i < end; i++)
        {
            int idx = 0X3D & v;
            output[i] = chars[idx];
            v = v >> 6;
        }
    }
    //printf("%s\n", output);
    len = (len > sizeof(output)) ? sizeof(output) :  len;
    memcpy(result, output, len);
}

void uuid8(char *result)
{
    uuid(result, 8);
    result[8] = '\0';
}

void uuid20(char *result)
{
    uuid(result, 20);
    result[20] = '\0';
}




void uuid94hex(char* uuidRes)
{
    unsigned __int128 uuid_num;
    int strIndex = 0;
    int index = 0;
    
    uuid_t uu;
    uuid_generate( uu );
    memcpy(&uuid_num,&uu,sizeof(uuid_num));
    while (uuid_num > 0)
    {
        index = uuid_num % 94 ; uuid_num /= 94;
        uuidRes[strIndex] = DIGITS_94[index];
        ++strIndex;
    }uuidRes[strIndex] = '\0';
}

void uuid64hex(char* uuidRes)
{
    unsigned __int128 uuid_num;
    int strIndex = 0;
    int index = 0;
    
    uuid_t uu;
    uuid_generate( uu );
    memcpy(&uuid_num,&uu,sizeof(uuid_num));
    
    while (uuid_num > 0)
    {
        index = uuid_num % 64 ; uuid_num = uuid_num >> 6;
        uuidRes[strIndex] = DIGITS_64[index];
        ++strIndex;
    }uuidRes[strIndex] = '\0';
}


void uuid94hexbyuuid(char* uuidRes,char* uuid)
{
    unsigned __int128 uuid_num;
    int strIndex = 0;
    int index = 0;
    uuid_t uu;
    uuid_parse(uuid,uu);
    memcpy(&uuid_num,&uu,sizeof(uuid_num));
    
    while (uuid_num > 0)
    {
        index = uuid_num % 94 ; uuid_num = uuid_num / 94;
        uuidRes[strIndex] = DIGITS_94[index];
        ++strIndex;
    }uuidRes[strIndex] = '\0';
}

void uuid64hexbyuuid(char* uuidRes,char* uuid)
{
    unsigned __int128 uuid_num;
    int strIndex = 0;
    int index = 0;
    uuid_t uu;
    uuid_parse(uuid,uu);
    memcpy(&uuid_num,&uu,sizeof(uuid_num));
    
    while (uuid_num > 0)
    {
        index = uuid_num % 64 ; uuid_num = uuid_num >> 6;
        uuidRes[strIndex] = DIGITS_64[index];
        ++strIndex;
    }uuidRes[strIndex] = '\0';
    
}


//
int main(int argc, const char * argv[]) {
    // insert code here...
    char* testuuid = "4384fde6-4e2a-59d4-b935-a9ea9c989b68";
    char bufres[32] = {0};
    uuid64hexbyuuid(bufres,testuuid);
    printf("64 %s\n",bufres);
    
    uuid94hexbyuuid(bufres,testuuid);
    printf("94 %s\n",bufres);

    
    return 0;
}





