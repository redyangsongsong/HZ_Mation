#ifndef _USBH_H_
#define	_USBH_H_
#include "sys.h"


extern void USB_OTG_Init(void);
extern void USB_Process(void);



//获取U盘状态
//返回值:0,U盘未就绪
//      1,就绪
extern u8 USBH_UDISK_Status(void);

//读U盘
//buf:读数据缓存区
//sector:扇区地址
//cnt:扇区个数	
//返回值:错误状态;0,正常;其他,错误代码;		 
extern u8 USBH_UDISK_Read(u8* buf,u32 sector,u32 cnt);

//写U盘
//buf:写数据缓存区
//sector:扇区地址
//cnt:扇区个数	
//返回值:错误状态;0,正常;其他,错误代码;		 
extern u8 USBH_UDISK_Write(u8* buf,u32 sector,u32 cnt);



               
#endif


