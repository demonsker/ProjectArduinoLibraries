#include <MicroGear.h>
class NETPIE
{
	public :	
            NETPIE();
            void initialize();
            void connectWIFI();
            void connect();
            void loopConnect();
            MicroGear getMicrogear();
};