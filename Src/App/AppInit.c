/*
 * @Descripttion: 
 * @version: 
 * @Author: yfs
 * @Date: 2019-12-27 09:17:32
 * @LastEditors  : yfs
 * @LastEditTime : 2020-01-18 11:54:03
 */
/*
 * File: AppInit.c
 * File Created: Tuesday, 9th October 2018 2:43:29 pm
 * version:v1.1
 * Description:应用程序初始化配置
 * param:
 * Modified By:yang
 * -----
 * Copyright 2018 - 2018 <<hzzh>>, <<hzzh>>
 */

#include "AppInit.h"
#include "Algorithm.h"

//变量声明  所有app程序的初始变量实例及声明
GlobalDataDef GlobalData = {0}; //定义用户通讯数据库
u8 uart_sendbuf[2][300];        //定义通讯接收和发送缓存
u8 uart_recvbuf[2][300];
u8 eth_txbuf[300];
u8 eth_rxbuf[300];

/****************项目使用结构的实例或声明***************/

/****************end define***************/

/**
 * @author: yfs
 * @Date: 2020-01-14 16:50:27
 * @description: 板卡初次上电flash全-1数据需要初始化
 * @para: 
 * @return: 
 */
void DataInit()
{
	memset(&GSS,0,sizeof(GSS));
	memset(&GUS,0,sizeof(GUS));
	/*
	此处添加初始化存储区数据，保证初次上电没使用的数据安全
	*/
    GSS.SaveCheck.checkflag = 0xea;
    HZ_Data_Write();
}

void initIO(void)
{
    int i;
    for (i = 0; i < 24; i++) //初始化 输出口
        OutPut_SetSta(i, OFF);
    for (i = 0; i < PULS_NUM; i++) //轴口使能,电平和普通输出相反
        EN_SetSta(i, 1);
}

void AppInit()
{
    //配置地址表完成modbus
    init_config(&GlobalData, GSR.ErrorCode, &GlobalData.SpaceType.Save, GLOBALDATALEN, USERWRITELEN, USERREADLEN, USERSAVELEN);

    //通过判断flash上的某个特殊值，来进行全局flash参数初始化
    if (GSS.SaveCheck.checkflag != 0xea)
    {
        DataInit();
    }

    initIO();

    //初始化轴配置
   

    GSR.HardWare_Ver[0] = 2019724;
    GUR.HaveToReset = 1;

    //初始化状态机，将设备状态初始是错误停
    InitFsm(&SysFsm);
}
