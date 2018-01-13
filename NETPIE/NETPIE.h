#include <MicroGear.h>
class NETPIE
{
	public :	
            NETPIE(char* _APPID, char* _KEY, char* _SECRET);
            void connectWIFI();
            void connect();
            void loopConnect();
            void setAlias(char* alias);
            void setWIFI(char* _ssid, char* _pwd);
            MicroGear getMicrogear();           
};