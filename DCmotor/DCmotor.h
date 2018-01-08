class DCmotor
{
	public :	
            DCmotor(int _motorA1, int _motorA2, int _motorB1, int _motoB2);
            void startMotorA(int direction);
            void startMotorB(int direction);
            void stopMotorA();
            void stopMotorB();
            void stopMotor();
};