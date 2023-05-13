/*
 * small calculator.c
 * 
 * Created: 24/09/2021 4:51:33 PM
 * Author : kamar salah
 */ 

#include <avr/io.h>
#include "LCD driver.h"
#include "Keybad driver.h"
#define  F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    label: LCD_vinit ();
    Keybad_vinit ();
	
	unsigned char arr[6]={NOTBRESSED,NOTBRESSED,NOTBRESSED,NOTBRESSED,NOTBRESSED,NOTBRESSED};
	unsigned short result;
	unsigned counter=0;
	
	
	
    while (1) 
    {
	   // set frist digit in frist number 
	   do 
	   {
		   arr[counter]=Keybad_u8check_press ();
	   } while (arr[counter]=NOTBRESSED);
	   
	   if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	   {
		   LCD_vclear_screen ();
		   goto label;
	   }
	   else 
	   {
		   LCD_vsend_char (arr[counter]);
	   }
	   counter++;
	   _delay_ms (300);
	   
	   // set seconed digit in frisr number
	   do 
	   {
		   arr[counter]=Keybad_u8check_press ();
	   } while (arr[counter]=NOTBRESSED);
	   
	   if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	   {
		   LCD_vclear_screen ();
		   goto label;
	   }
	   else 
	   {
		   LCD_vsend_char (arr[counter]);
	   }
	   counter++;
	   _delay_ms (300);
	   
	   // set operation 
	   do 
	   {
		   arr[counter]=Keybad_u8check_press ();
	   } while (arr[counter]=NOTBRESSED);
	   
	   if(arr[counter]=='A'||arr[counter]=='=')
	   {
		   LCD_vclear_screen ();
		   goto label;
	   }
	   else 
	   {
		   LCD_vsend_char (arr[counter]);
	   }
	   counter++;
	   _delay_ms (300);
	   
	   // set frist digit in seconed number
	   do 
	   {
		   arr[counter]=Keybad_u8check_press ();
	   } while (arr[counter]=NOTBRESSED);
	   
	   if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	   {
		   LCD_vclear_screen ();
		   goto label;
	   }
	   else 
	   {
		   LCD_vsend_char (arr[counter]);
	   }
	   counter++;
	   _delay_ms (300);
	   
	   // set seconed digit in secnoed number
	   do 
	   {
		   arr[counter]=Keybad_u8check_press ();
	   } while (arr[counter]=NOTBRESSED);
	   
	   if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
	   {
		   LCD_vclear_screen ();
		   goto label;
	   }
	   else 
	   {
		   LCD_vsend_char (arr[counter]);
	   }
	   counter++;
	   _delay_ms (300);
	   
	   // calculate the result 
	   do 
	   {
		   arr[counter]=Keybad_u8check_press ();
	   } while (arr[counter]=NOTBRESSED);
	   
	   if (arr[counter]=='=')
	   {
		   LCD_vsend_char (arr[counter]);
		   
		   switch(arr[counter-3])
		   {
			   case'+':
			     result =(arr[counter-4]-48)+((arr[counter-5]-48)*10)+((arr[counter-2]-48)*10)+(arr[counter-1]-48);
			if(result>=100 && result<1000)                                    
			{
				LCD_vSend_char((result/100)+48);                             // print the number in hundreds digit
				LCD_vSend_char(((result/10)%10)+48);                         // print the number in tens  digit
				LCD_vSend_char((result%10)+48);                              // print the number in ones digit
			}
			else if (result>=10 && result<100)
			{
				LCD_vSend_char((result/10)+48);                             // print the number in tens  digit
				LCD_vSend_char((result%10)+48);                             // print the number in ones digit
			}
			else if(result<10)
			{
				LCD_vSend_char(result+48);                                  // print the number in ones digit
			}
			break;
			
			   case'-':
			     result =((arr[counter-4]-48)+((arr[counter-5]-48)*10))-(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(result>=100 && result<1000)                                    
			{
				LCD_vSend_char((result/100)+48);                             // print the number in hundreds digit
				LCD_vSend_char(((result/10)%10)+48);                         // print the number in tens  digit
				LCD_vSend_char((result%10)+48);                              // print the number in ones digit
			}
			else if (result>=10 && result<100)
			{
				LCD_vSend_char((result/10)+48);                             // print the number in tens  digit
				LCD_vSend_char((result%10)+48);                             // print the number in ones digit
			}
			else if(result<10)
			{
				LCD_vSend_char(result+48);                                  // print the number in ones digit
			}
			break;
			
			   case'*':
			     result =((arr[counter-4]-48)+((arr[counter-5]-48)*10))*(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(result>=100 && result<1000)                                    
			{
				LCD_vSend_char((result/100)+48);                             // print the number in hundreds digit
				LCD_vSend_char(((result/10)%10)+48);                         // print the number in tens  digit
				LCD_vSend_char((result%10)+48);                              // print the number in ones digit
			}
			else if (result>=10 && result<100)
			{
				LCD_vSend_char((result/10)+48);                             // print the number in tens  digit
				LCD_vSend_char((result%10)+48);                             // print the number in ones digit
			}
			else if(result<10)
			{
				LCD_vSend_char(result+48);                                  // print the number in ones digit
			}
			break;
			
			   case'/':
			     result =((arr[counter-4]-48)+((arr[counter-5]-48)*10))/(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
			if(result>=100 && result<1000)                                    
			{
				LCD_vSend_char((result/100)+48);                             // print the number in hundreds digit
				LCD_vSend_char(((result/10)%10)+48);                         // print the number in tens  digit
				LCD_vSend_char((result%10)+48);                              // print the number in ones digit
			}
			else if (result>=10 && result<100)
			{
				LCD_vSend_char((result/10)+48);                             // print the number in tens  digit
				LCD_vSend_char((result%10)+48);                             // print the number in ones digit
			}
			else if(result<10)
			{
				LCD_vSend_char(result+48);                                  // print the number in ones digit
			}
			break;
			
			default : 
			break;
		   }
	   }
	   else                                                              // pressed any button in the keybad
	   {
		   LCD_clearscreen();
		goto label ;
	}
	_delay_ms(200);
			
		   
			 
    }
}

