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
   k[0]=2;
   k[1]=(unsigned char)atoi(argv[1]);
   result= wiringPiSPIDataRW(CHANNEL, k, 2);
   k[0]=0;
   conf readV;
   while (k[0]!=0xFF){
      k[0]=0;
      result= wiringPiSPIDataRW(CHANNEL, k, 1);
   }
   result= wiringPiSPIDataRW(CHANNEL, k, sizeof(conf));
   memcpy(&readV,k,sizeof(conf));

   printf("name:%s\n",readV.name);
   printf("overtime:%d\n",readV.overtime);
   printf("undertime:%d\n",readV.undertime);
   printf("len:%d\n",readV.len);

}
