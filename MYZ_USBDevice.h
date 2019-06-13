#pragma once
#ifndef USBDeviceDLL_H_
#define USBDeviceDLL_H_
#ifdef USBDEVICEDLL_DECLSPEC
#define USBDEVICEDLL_DECLSPEC extern "C" _declspec(dllimport) 
#else
#define USBDEVICEDLL_DECLSPEC extern "C" _declspec(dllexport) 
#endif
/*
���ܣ���ʼ�������ƶ��豸
����ֵ��true�ɹ� falseʧ��
��ReadDeviceData_Move�������ʹ�ã���ȡǰ�����ҡ��¶׵�����
*/
USBDEVICEDLL_DECLSPEC bool InitDevice_Move();
/*
���ܣ���ʼ�������豸
����ֵ��true�ɹ� falseʧ��
��ReadDeviceData_Row�������ʹ�ã���ȡ��������
*/
USBDEVICEDLL_DECLSPEC bool InitDevice_Row();
/*
˵����ʹ�ö�ʱ�����߳������ô˺�����ʵʱ��ȡ����
���ܣ���ȡ�����ƶ����ݣ�ʹ��֮ǰ��ִ�� InitDevice_Move() ����
������nForward ����0��ʾǰ����С��0��ʾ���ˣ�������������豸�ĽǶȾ�������һ������ֵ
������nRight ����0��ʾ�����ƶ���С��0��ʾ�����ƶ���������������豸�ĽǶȾ�������һ������ֵ
������nDown ����0��ʾ���£���һ������ֵ
*/
USBDEVICEDLL_DECLSPEC void ReadDeviceData_Move(int & nForward, int & nRight, int & nDown);
/*
˵����ʹ�ö�ʱ�����߳������ô˺�����ʵʱ��ȡ����
���ܣ���ȡ�������ݣ�ʹ��֮ǰ��ִ�� InitDevice_Row() ����
������cbAction ���� 1 ��ʱ�� ��ʾ�ż�
������cbDistence ���ҵ��������� ȡֵ��Χ0~10����
*/
USBDEVICEDLL_DECLSPEC void ReadDeviceData_Row(int & cbAction, int & cbDistence);
/*
˵�������豸�������ƶ���ͬһ���豸��ֻ��Ҫִ��InitDevice_Move()һ��
���ܣ����豸����������
������cbSendData 7���λ��������ţ�7���λ���� 1��2��4��8��16��32��64��ʾ �����磺Ҫʹ1�š�3�š�5���� ��ֵ 1|4|16 �Ľ��
������DurationTime �𶯳���ʱ�� ��λ����  �����Чʱ�� 0.1 ��
*/
USBDEVICEDLL_DECLSPEC void SendToDevice_Shake(BYTE cbSendData, float DurationTime);
//�رտ����ƶ��豸
USBDEVICEDLL_DECLSPEC void CloseDevice_Move();
//�رչ����豸
USBDEVICEDLL_DECLSPEC void CloseDevice_Row();

#endif