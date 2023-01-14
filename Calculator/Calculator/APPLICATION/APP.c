#include "APP.h"
#include<util/delay.h>

/*Global variables*/


u8 Operation_type;
u8 Flag_1=1;
u8 Flag_2=1;
u8 Counter_1=0;
u8 Counter_2=0;
void Calculator_Init(void)
{
	KEYPAD_Init();
}

void Calculator_start(void)
{
	u8 Pressed_key='\0';
	while(Flag_1==1)
	{
		/*Check if the user press On on keypad then start Application*/
		do
			{
				Pressed_key=KPD_u8GetPressedKey();
			}while(Pressed_key=='\0');
			if(Pressed_key=='A')
			{
				CLCD_voidInit();
				CLCD_voidSendString("Calculator ON!");
				//CLCD_voidGoToXY(1,0);
			//	CLCD_SendNumber(123);
				_delay_ms(250);
				CLCD_voidClearDisplay();
				//Application_start();
				Flag_1=0;
			}
	}
}
void Application_start(void)
{
	u8 First_Operand[4]={0};
	u8 Second_Operand[4]={0};
	u16 Result=0;
	u8 Pressed_num_1='\0';
	u8 Pressed_num_2='\0';
	u8 Pressed_command='\0';
	/*Get First Number*/
	while(Flag_2==1)
	{
		do
		{
			Pressed_num_1=KPD_u8GetPressedKey();
		}while(Pressed_num_1=='\0');
		if(Pressed_num_1=='+'|| Pressed_num_1=='-'|| Pressed_num_1=='*'|| Pressed_num_1=='/') //check for operation sign
		{
			Operation_type=Pressed_num_1;
			CLCD_voidSendData(Pressed_num_1);
			break;
		}
		if(Pressed_num_1 == 'A') //check if the user want to restart application
		{
			CLCD_voidClearDisplay();
			Flag_2=0;
			break;
		}
		First_Operand[Counter_1]=Pressed_num_1;
		CLCD_SendNumber(Pressed_num_1);
		Counter_1++;
	}

	/*Get Second Number*/
	while(Flag_2==1)
	{
			do
			{
				Pressed_num_2=KPD_u8GetPressedKey();
			}while(Pressed_num_2=='\0');
			if(Pressed_num_2=='=') //check for equality sign to start calculations
			{
				CLCD_voidSendData(Pressed_num_2);
				break;
			}
			if(Pressed_num_2=='A') //check if the user want to restart application
			{
				CLCD_voidClearDisplay();
				Flag_2=0;
				break;
			}
			Second_Operand[Counter_2]=Pressed_num_2;
			CLCD_SendNumber(Pressed_num_2);
			Counter_2++;
	}

	/*Start the operation*/
	switch(Operation_type)
	{
		case '+':
			Result=Sum_Operation(First_Operand,Second_Operand,Counter_1,Counter_2);
			CLCD_SendNo(Result);
			break;
		case '-':
			Result=Sub_Operation(First_Operand,Second_Operand,Counter_1,Counter_2);
			CLCD_SendNo(Result);
			break;
		case '*':
			Result=Multiply_Operation(First_Operand,Second_Operand,Counter_1,Counter_2);
			CLCD_SendNo(Result);
			break;
		case '/':
			Result=Division_Operation(First_Operand,Second_Operand,Counter_1,Counter_2);
			CLCD_SendNo(Result);
			break;
	}
	/*Clear the used variables to avoid corruption data*/
	Result=0;
	Counter_1=0;
	Counter_2=0;
	/*Press clear button to clear display*/
	while(Flag_2==1)
	{
		do
		{
			Pressed_command=KPD_u8GetPressedKey();
		}while(Pressed_command=='\0');
		if(Pressed_command=='A')
		{
			CLCD_voidClearDisplay();
			break;
		}
	}
	/*when flag 2 = 0 then we are going to restart the Application again*/
	while(Flag_2==0)
	{
		Pressed_num_1=0;
		Pressed_num_2=0;
		Pressed_command=0;
		First_Operand[4]=0;
		Second_Operand[4]=0;
		CLCD_voidClearDisplay();
		Flag_2=1;
	}
}


/*Functions Operations*/
u16 Sum_Operation(u8 No_1[],u8 No_2[],u8 Counter_1,u8 Counter_2)
{
	u16 Number1=No_1[0];
	u16 Number2=No_2[0];
	u16 result=0;
	/*Get First Number*/
	for(u8 Counter=1;Counter<Counter_1;Counter++)
	{
		Number1= Number1*10+No_1[Counter];
	}
	/*Get Second Number*/
	for(u8 Counter=1;Counter<Counter_2;Counter++)
	{
		Number2= Number2*10+No_1[Counter];
	}
	/*Operation*/
	result= Number1+Number2;
	return result;
}
u16 Sub_Operation(u8 No_1[],u8 No_2[],u8 Counter_1,u8 Counter_2)
{
	u16 Number1=No_1[0];
	u16 Number2=No_2[0];
	u16 result=0;
	/*Get First Number*/
	for(u8 Counter=1;Counter<Counter_1;Counter++)
	{
		Number1= Number1*10+No_1[Counter];
	}
	/*Get Second Number*/
	for(u8 Counter=1;Counter<Counter_2;Counter++)
	{
		Number2= Number2*10+No_1[Counter];
	}
	/*Operation*/
	result= Number1-Number2;
	return result;
}
u16 Multiply_Operation(u8 No_1[],u8 No_2[],u8 Counter_1,u8 Counter_2)
{
	u16 Number1=No_1[0];
		u16 Number2=No_2[0];
		u16 result=0;
		/*Get First Number*/
		for(u8 Counter=1;Counter<Counter_1;Counter++)
		{
			Number1= Number1*10+No_1[Counter];
		}
		/*Get Second Number*/
		for(u8 Counter=1;Counter<Counter_2;Counter++)
		{
			Number2= Number2*10+No_1[Counter];
		}
		/*Operation*/
		result= Number1*Number2;
		return result;
}
u16 Division_Operation(u8 No_1[],u8 No_2[],u8 Counter_1,u8 Counter_2)
{
	u16 Number1=No_1[0];
		u16 Number2=No_2[0];
		u16 result=0;
		/*Get First Number*/
		for(u8 Counter=1;Counter<Counter_1;Counter++)
		{
			Number1= Number1*10+No_1[Counter];
		}
		/*Get Second Number*/
		for(u8 Counter=1;Counter<Counter_2;Counter++)
		{
			Number2= Number2*10+No_1[Counter];
		}
		/*Operation*/
		result= Number1/Number2;
		return result;

}

