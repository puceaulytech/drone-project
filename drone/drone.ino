#include "Simple_MPU6050.h"
#define MPU6050_DEFAULT_ADDRESS     0x68


Simple_MPU6050 mpu;

void setup() {
 setupMPU();

}

void loop() {
   static unsigned long FIFO_DelayTimer;
  if ((millis() - FIFO_DelayTimer) >= (99)) {
    if( mpu.dmp_read_fifo(false)) FIFO_DelayTimer= millis() ; 
  }







}
void setupMPU(){
    mpu.begin();
  mpu.Set_DMP_Output_Rate_Hz(10);          
  mpu.CalibrateMPU();                      
  mpu.load_DMP_Image();                    
  mpu.on_FIFO(updateMPU);     
}
void updateMPU(int16_t *gyro, int16_t *accel, int32_t *quat){
  Quaternion q;
  VectorFloat gravity;
  float ypr[3] = { 0, 0, 0 };
  float xyz[3] = { 0, 0, 0 };
  mpu.GetQuaternion(&q, quat);
  mpu.GetGravity(&gravity, &q);
  mpu.GetYawPitchRoll(ypr, &q, &gravity);
  mpu.ConvertToDegrees(ypr, xyz);
}