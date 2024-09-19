#include "stm32f10x_usart.h"
#include "stm32f10x.h"
#include "Serial3.h"  


uint8_t USART3_Serial_RxFlag;					//定义接收数据包标志位
char USART3_Serial_RxPacket[100];				//定义接收数据包数组
  
  void USART3_Init(u32 baud)   
  {  
      USART_InitTypeDef USART_InitStructure;  
      NVIC_InitTypeDef NVIC_InitStructure;   
      GPIO_InitTypeDef GPIO_InitStructure;    //声明一个结构体变量，用来初始化GPIO  
      //使能串口的RCC时钟  
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE); //使能UART3所在GPIOB的时钟  
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);  
  
      //串口使用的GPIO口配置  
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;  
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
      GPIO_Init(GPIOB, &GPIO_InitStructure);  
  
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;  
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
      GPIO_Init(GPIOB, &GPIO_InitStructure);  
  
      //配置串口  
      USART_InitStructure.USART_BaudRate = baud;  
      USART_InitStructure.USART_WordLength = USART_WordLength_8b;  
      USART_InitStructure.USART_StopBits = USART_StopBits_1;  
      USART_InitStructure.USART_Parity = USART_Parity_No;  
      USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
      USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;  
  
  
      // Configure USART3   
      USART_Init(USART3, &USART_InitStructure);//配置串口3 
      // Enable USART3 Receive interrupts 使能串口接收中断  
      USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);  
      // Enable the USART3   
      USART_Cmd(USART3, ENABLE);//使能串口3  
  
      //串口中断配置  
      //Configure the NVIC Preemption Priority Bits     
      NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
  
      // Enable the USART3 Interrupt   
      NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;   
      NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2 ;//抢占优先级3
      NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;        //子优先级3
      NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
      NVIC_Init(&NVIC_InitStructure);       
        
  } 
  
  void USART3_Sned_Char(u8 temp)        
  {  
      USART_SendData(USART3,(u8)temp);      
      while(USART_GetFlagStatus(USART3,USART_FLAG_TXE)==RESET);  
        
  }
  
  void USART3_Sned_Char_Buff(u8 buf[],u32 len)  
  {  
      u32 i;  
      for(i=0;i<len;i++)  
      USART3_Sned_Char(buf[i]);  
            
  }
 

void USART3_Serial_SendString(char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i ++)//遍历字符数组（字符串），遇到字符串结束标志位后停止
	{
		USART3_Sned_Char(String[i]);		//依次调用Serial_SendByte发送每个字节数据
	}
}
	
 
void USART3_IRQHandler(void)
{
	static uint8_t USART3_RxState = 0;		//定义表示当前状态机状态的静态变量
	static uint8_t USART3_pRxPacket = 0;	//定义表示当前接收数据位置的静态变量
	if (USART_GetITStatus(USART3, USART_IT_RXNE) == SET)	//判断是否是USART1的接收事件触发的中断
	{
		uint8_t USART3_RxData = USART_ReceiveData(USART3);			//读取数据寄存器，存放在接收的数据变量
		
		/*使用状态机的思路，依次处理数据包的不同部分*/
		
		/*当前状态为0，接收数据包包头*/
		if (USART3_RxState == 0)
		{
			if (USART3_RxData == '@' && USART3_Serial_RxFlag == 0)		//如果数据确实是包头，并且上一个数据包已处理完毕
			{
				USART3_RxState = 1;			//置下一个状态
				USART3_pRxPacket = 0;			//数据包的位置归零
			}
		}
		/*当前状态为1，接收数据包数据，同时判断是否接收到了第一个包尾*/
		else if (USART3_RxState == 1)
		{
			if (USART3_RxData == '\r')			//如果收到第一个包尾
			{
				USART3_RxState = 2;			//置下一个状态
			}
			else						//接收到了正常的数据
			{
				USART3_Serial_RxPacket[USART3_pRxPacket] = USART3_RxData;		//将数据存入数据包数组的指定位置
				USART3_pRxPacket ++;			//数据包的位置自增
			}
		}
		/*当前状态为2，接收数据包第二个包尾*/
		else if (USART3_RxState == 2)
		{
			if (USART3_RxData == '\n')			//如果收到第二个包尾
			{
				USART3_RxState = 0;			//状态归0
				USART3_Serial_RxPacket[USART3_pRxPacket] = '\0';			//将收到的字符数据包添加一个字符串结束标志
				USART3_Serial_RxFlag = 1;		//接收数据包标志位置1，成功接收一个数据包
			}
		}
		
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);		//清除标志位
	}
}
