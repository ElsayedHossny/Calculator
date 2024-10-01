#include "MemMap.h"
#include "StdTypes.h"

#include "MCAL/DIO_int.h"
#include "MCAL/DIO_private.h"

#include "MCAL/ADC_int.h"

#include "Motor_int.h"
#include "LCD_int.h"

#include "Keypad_int.h"

#include "Function.h"

#define  F_CPU 16000000
#include "util/delay.h"


int main(void)
{

DIO_Init();
LCD_Init();
KEYPAD_Init();
u8 k,flag=0,flag2=0,FBEqu=1,FBSig=1,FBSig2=1,op='+';
s32 num=0 ,num1=0,res=0 ,num2=0;;

while(1)
{

k=KEYPAD_GetKey();
if(k!=No_KEY){
if(k>='0' && k<='9')
	{
		FBSig=0;
		FBEqu=0;
		if(flag==1)
		{
			restart_again();
			flag=0;
			flag2=0;
		}
		LCD_WriteChar(k);
		num=num*10+k - '0';

	}
		
else if(k=='+' || k=='-' || k=='*' || k=='/')
		{	
			if(FBSig==0 && FBSig2==1)
			{
			           if(flag2==1)
						{
			                num1=res;
						    op=k;
                            restart_again();
							LCD_WriteNumber(res);
							LCD_WriteChar(op);
							flag=0;
							flag2=0;
			            }
					   else
					   {
							op=k;
							LCD_WriteChar(op);
							num1=num;
			           }
			                num=0;
			                FBSig=1;
							FBSig2=0;
			}
		}
		
else if(k=='=' && flag==0 )
	{
		FBSig2=1;
		FBSig=0;
		if(FBEqu==0)
		{
					num2=num;
					LCD_SetCursor(line_2,0);
					LCD_WriteString((u8*)"       ");
					LCD_SetCursor(line_2,0);
					res=Result(num1,op,num2);
					flag=1;
					flag2=1;
					num=0;
		}
		FBEqu=1;
	}
else if(k=='c')
	{
		LCD_Clear();
		flag=0;
		flag2=0;
		FBSig=1;
		FBSig2=1;
		FBEqu=1;
		num=0;
	}
	else{}
}




}
}
