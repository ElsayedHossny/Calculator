#include "MemMap.h"
#include "StdTypes.h"

#include "LCD_int.h"
#include "Function.h"


s32 AddNum(s32 n1,s32 n2){	
	
	s32 sum = n1+n2;
	LCD_WriteNumber(sum);
	return sum;
}

s32 SubNum(s32 n1,s32 n2){
	s32 sub= n1-n2;
	LCD_WriteNumber(sub);
	return sub;
}

s32 MulNum(s32 n1,s32 n2){
    s32 mul=n1*n2;
	LCD_WriteNumber(mul);
	return mul;
}

s32 DivNum(s32 n1,s32 n2){
	s32 res=0 , div=0;
	
	if(n2==0)
	{
		LCD_WriteString((u8*)"Error No div 0");
	}
	else
	{
		if(n2>n1)
		{
			if(n1>0)
			{
				res=((n1*100)/n2);
				LCD_WriteString((u8*)"0,");
				LCD_WriteNumber(res);				
			}
			else
			{
				res=n1/n2;
				div=n1 % n2;	
	            if(div!=0)
				{
					LCD_WriteNumber(res);
					LCD_WriteString((u8*)",");
					div=(-div*100)/n2;
					LCD_WriteNumber(div);			
				}
				else
			    {
		            LCD_WriteNumber(res);
				}

			}
          }
		  else
		  {
				res=n1/n2;
				div=n1 % n2;
				if(div!=0)
				{
					LCD_WriteNumber(res);
					LCD_WriteString((u8*)",");
					div=((div*100)/n2);
					LCD_WriteNumber(div);
				}
				else
				{
					LCD_WriteNumber(res);
				}
		  }
	  }		
return res;
}

s32 Result(s32 num1,u8 op, s32 num2){
	s32 res=0;
	switch (op){
		case '+':res=AddNum(num1,num2);
		break;
		case '-':res=SubNum(num1,num2);
		break;
		case '*':res=MulNum(num1,num2);
		break;
		case '/':res=DivNum(num1,num2);
		break;
	}
	return res;
}

void restart_again(void){
				LCD_SetCursor(line_1,0);
				LCD_WriteString((u8 *)"                  ");
				LCD_SetCursor(line_2,0);
				LCD_WriteString((u8 *)"                  ");
				LCD_SetCursor(line_1,0);
}


