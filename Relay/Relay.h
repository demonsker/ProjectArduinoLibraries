class Relay
{
	public :	
			Relay(int _downTemperature, int _cleaning);
			void startDownTemperature();
			void startCleaning();
			void stopTemperature();
			void stopCleaning();
			void stopAllPin();
};
