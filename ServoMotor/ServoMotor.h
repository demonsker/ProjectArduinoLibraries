class ServoMotor
{
	public :	
			ServoMotor(int Pin1, int Pin2);
			void startLiftUp();
			void startLiftDown();
			void ChangeDegree(int degree);
			void openFood(int servo);
			void closeFood(int servo);
};