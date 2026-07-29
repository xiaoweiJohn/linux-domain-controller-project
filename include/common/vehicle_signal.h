#ifndef VEHICLE_SIGNAL_H_
#define VEHICLE_SIGNAL_H_

/*创建汽车各类信号*/

/*信号形式：start bit + length + scale + data + Unit*/
/*例如：速度800km/h，start bit: 0x00, length: 16bit, scale: 0.1, data: 800, unit: km/h
    解析后就是：800*0.1 = 80.0km/h*/

/*速度*/
struct VehicleSpeed {
    uint16_t speed;
};

/*温度*/
struct Temperature {
    uint8_t temperature;
};

/*电池电压*/
struct Battery {
    float voltage;
};




#endif 