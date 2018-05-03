#include <wiringPiSPI.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

using namespace std;

// channel is the wiringPi name for the chip select (or chip enable) pin.
// Set this to 0 or 1, depending on how it's connected.
static const int CHANNEL = 0;

int main(int argc, char **argv){
   //for (int i = 0; i < argc; ++i){
   //   printf("argv[%d]: %s\n", i, argv[i]);
   //}
   if (argc<2){
      printf("declare channel\n");
      return -1;
   }
   if((atoi(argv[1])>1)){
      printf("it was funny\n");
      return -1;
   }
   int fd, result;
   int spiMode=3;
   fd = wiringPiSPISetup(CHANNEL, 50000);
   unsigned char k[3];
   k[0]=1;
   k[1]=(unsigned char)atoi(argv[1]);
   result= wiringPiSPIDataRW(CHANNEL, k, 2);
   k[0]=0;
   k[1]=0;

   while (k[0]!=0xFF){
      k[0]=0;
      result= wiringPiSPIDataRW(CHANNEL, k, 1);
   }
   result= wiringPiSPIDataRW(CHANNEL, k, 1);

   printf("value:%d\n",k[0]);

}
