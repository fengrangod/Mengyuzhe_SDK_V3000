#pragma once
#ifndef USBDeviceDLL_H_
#define USBDeviceDLL_H_
#ifdef USBDEVICEDLL_DECLSPEC
#define USBDEVICEDLL_DECLSPEC extern "C" _declspec(dllimport) 
#else
#define USBDEVICEDLL_DECLSPEC extern "C" _declspec(dllexport) 
#endif
/*
功能：初始化控制移动设备
返回值：true成功 false失败
与ReadDeviceData_Move函数配合使用，获取前后、左右、下蹲的数据
*/
USBDEVICEDLL_DECLSPEC bool InitDevice_Move();
/*
功能：初始化弓箭设备
返回值：true成功 false失败
与ReadDeviceData_Row函数配合使用，获取弓箭数据
*/
USBDEVICEDLL_DECLSPEC bool InitDevice_Row();
/*
说明：使用定时器或线程来调用此函数，实时获取数据
功能：读取控制移动数据，使用之前先执行 InitDevice_Move() 函数
参数：nForward 大于0表示前进，小于0表示后退，根据身体控制设备的角度决定，是一个线性值
参数：nRight 大于0表示向右移动，小于0表示向左移动，根据身体控制设备的角度决定，是一个线性值
参数：nDown 大于0表示蹲下，是一个线性值
*/
USBDEVICEDLL_DECLSPEC void ReadDeviceData_Move(int & nForward, int & nRight, int & nDown);
/*
说明：使用定时器或线程来调用此函数，实时获取数据
功能：读取弓箭数据，使用之前先执行 InitDevice_Row() 函数
参数：cbAction 等于 1 的时候 表示放箭
参数：cbDistence 弓弦的拉动距离 取值范围0~10左右
*/
USBDEVICEDLL_DECLSPEC void ReadDeviceData_Row(int & cbAction, int & cbDistence);
/*
说明：此设备跟控制移动是同一个设备，只需要执行InitDevice_Move()一次
功能：向设备发送震动数据
参数：cbSendData 7组电位器的震动序号，7组电位器以 1、2、4、8、16、32、64表示 ，例如：要使1号、3号、5号震动 传值 1|4|16 的结果
参数：DurationTime 震动持续时间 单位：秒  最短有效时间 0.1 秒
*/
USBDEVICEDLL_DECLSPEC void SendToDevice_Shake(BYTE cbSendData, float DurationTime);
//关闭控制移动设备
USBDEVICEDLL_DECLSPEC void CloseDevice_Move();
//关闭弓箭设备
USBDEVICEDLL_DECLSPEC void CloseDevice_Row();

#endif