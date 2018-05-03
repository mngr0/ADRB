#include <wiringPiSPI.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cstring>
static const int CHANNEL = 0;
typedef struct conf_t{
   char name[16];
   uint32_t overtime;
   uint32_t undertime;
   uint32_t times[64];
   uint32_t len;
} conf;
int main(int argc, char **argv){
   if (argc<2){
      printf("declare conf\n");
      return -1;
   }
   if((atoi(argv[1])>7)){
      printf("it was funny\n");
      return -1;
   }
   int fd, result;
   fd = wiringPiSPISetup(CHANNEL, 50000);
   unsigned char k[sizeof(conf)];
   k[0]=4;
   k[1]=(unsigned char)atoi(argv[1]);

   conf setV;
   setV.name[0]='m';
   setV.name[1]='o';
   setV.name[2]='d';
   setV.overtime=100;
   setV.undertime=1500;
   setV.times[0]=2000;
   setV.times[1]=1500;
   setV.times[2]=1000;
   setV.times[3]=500;
   setV.times[4]=200;
   setV.len=5;
   memcpy(&k[2],&setV,sizeof(conf));

   result= wiringPiSPIDataRW(CHANNEL, k, sizeof(conf)+2);
}
