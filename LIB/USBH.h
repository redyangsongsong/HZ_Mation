#ifndef _USBH_H_
#define	_USBH_H_
#include "sys.h"


extern void USB_OTG_Init(void);
extern void USB_Process(void);



//��ȡU��״̬
//����ֵ:0,U��δ����
//      1,����
extern u8 USBH_UDISK_Status(void);

//��U��
//buf:�����ݻ�����
//sector:������ַ
//cnt:��������	
//����ֵ:����״̬;0,����;����,�������;		 
extern u8 USBH_UDISK_Read(u8* buf,u32 sector,u32 cnt);

//дU��
//buf:д���ݻ�����
//sector:������ַ
//cnt:��������	
//����ֵ:����״̬;0,����;����,�������;		 
extern u8 USBH_UDISK_Write(u8* buf,u32 sector,u32 cnt);



               
#endif


