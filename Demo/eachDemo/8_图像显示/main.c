

/* 系统头文件 */
#include "stm32f10x.h"
#include "systemconfig.h"
#include "stdio.h"

/* lkdGui驱动相关文件 */
#include "UC1698Driver.h"
#include "lkdmyFont.h"

/* lkdGui库文件 */
#include "lkdGuiBasic.h"
#include "lkdGuiFont.h"
#include "lkdGuiControl.h"

extern uint8_t lkdGuiImage[];
extern uint8_t lkdGuiImage2[];
int main(void)
{
	SystemconfigInit();
	
	LcdInit();/* lcd初始化 */
	defaultFontInit();/* 字库初始化 */
	GuiUpdateDisplayAll();/* 更新屏幕-清屏 */
	
	lkdBitmap tImage;
	tImage.beginx = 0;/* 图像开始显示偏移 */
	tImage.beginy = 0;
	tImage.wide = 144;/* 图像本身的大小 */
	tImage.high = 40;
	tImage.bitmap = lkdGuiImage2;/* 图像 */
	GuiAreaBitMap(&tImage,10, 5, 154, 45, 0);
	GuiUpdateDisplayAll();/* 更新 */
	while(1)
	{
		for(uint8_t i = 0; i < 144; i += 10){
			tImage.beginx = i;
			tImage.beginy = 0;
			GuiAreaBitMap(&tImage,10, 95, 159, 159, 0);
			GuiUpdateDisplayAll();
			Delay_ms(100);
		}
		for(int16_t i = 140; i >= 0; i -= 10){
			tImage.beginx = i;
			tImage.beginy = 0;
			GuiAreaBitMap(&tImage,10, 95, 159, 159, 0);
			GuiUpdateDisplayAll();
			Delay_ms(100);
		}
		for(uint8_t i = 0; i <= 39; i += 10){
			tImage.beginx = 0;
			tImage.beginy = i;
			GuiFillRect(10,45,159,90,backcolor);
			GuiAreaBitMap(&tImage,10, 45, 159, 90, 0);
			GuiUpdateDisplayAll();
			Delay_ms(100);
		}
		for(int8_t i = 30; i >= 0; i -= 10){
			tImage.beginx = 0;
			tImage.beginy = i;
			GuiAreaBitMap(&tImage,10, 45, 159, 90, 0);
			GuiUpdateDisplayAll();
			Delay_ms(100);
		}
	}
}

uint8_t lkdGuiImage2[] = {
/*--  lkdGui = 144 x 40  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0xFF,0xE7,0xFE,0x00,0x00,
0x00,0x3F,0xF0,0x00,0x1F,0xFE,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0xFF,0xE7,0xFE,
0x00,0x00,0x00,0x3F,0xF0,0x00,0x7F,0xFE,0x00,0x00,0x00,0x7F,0xC0,0x00,0x00,0xFF,
0xE7,0xFE,0x00,0x00,0x00,0x3F,0xF0,0x01,0xFF,0xFE,0x00,0x00,0x00,0x7F,0xC0,0x00,
0x00,0xFF,0xE7,0xFE,0x00,0x00,0x00,0x3F,0xF0,0x03,0xFF,0xFE,0x00,0x00,0x00,0x7F,
0xC0,0x00,0x00,0xFF,0xE7,0xFE,0x00,0x00,0x00,0x3F,0xF0,0x07,0xFF,0xFE,0x00,0x00,
0x00,0x7F,0xC0,0x00,0x00,0xFF,0xE7,0xFE,0x00,0x00,0x00,0x3F,0xF0,0x0F,0xFF,0xFE,
0x00,0x00,0x00,0x7F,0xC0,0x00,0x00,0xFF,0xE7,0xFE,0x00,0x00,0x00,0x3F,0xF0,0x1F,
0xFF,0xFE,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0xFF,0xE7,0xFE,0x00,0x00,0x00,0x3F,
0xF0,0x1F,0xFF,0xFE,0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0xFF,0xE7,0xFE,0x3F,0xF0,
0x1F,0xFF,0xF0,0x3F,0xFF,0xFE,0x7F,0xCF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFE,
0x7F,0xF0,0x7F,0xFF,0xF0,0x3F,0xFF,0xFE,0x7F,0xCF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,
0xE7,0xFE,0xFF,0xE0,0xFF,0xFF,0xF0,0x7F,0xFF,0xFE,0x7F,0xCF,0xFC,0xFF,0xE0,0x00,
0x00,0xFF,0xE7,0xFE,0xFF,0xE1,0xFF,0xFF,0xF0,0x7F,0xFC,0x00,0x7F,0xCF,0xFC,0xFF,
0xE0,0x00,0x00,0xFF,0xE7,0xFF,0xFF,0xC3,0xFF,0xFF,0xF0,0x7F,0xF8,0x00,0x7F,0xCF,
0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFF,0xFF,0xC7,0xFF,0xFF,0xF0,0x7F,0xF1,0xFF,
0xFF,0xCF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFF,0xFF,0x87,0xFF,0xFF,0xF0,0x7F,
0xF1,0xFF,0xFF,0xCF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFF,0xFF,0x8F,0xFF,0xFF,
0xF0,0x7F,0xE1,0xFF,0xFF,0xCF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFF,0xFF,0x0F,
0xFF,0xFF,0xF0,0x7F,0xE1,0xFF,0xFF,0xCF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFF,
0xFF,0x0F,0xFF,0xFF,0xF0,0x7F,0xE1,0xFF,0xFF,0xCF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,
0xE7,0xFF,0xFF,0x0F,0xFC,0x3F,0xF0,0x7F,0xF1,0xFF,0xFF,0xCF,0xFC,0xFF,0xE0,0x00,
0x00,0xFF,0xE7,0xFF,0xFF,0x8F,0xFC,0x3F,0xF0,0x7F,0xF1,0xFF,0xFF,0xCF,0xFC,0xFF,
0xE0,0x00,0x00,0xFF,0xE7,0xFF,0xFF,0x8F,0xFC,0x3F,0xF0,0x7F,0xF9,0xFF,0xFF,0xCF,
0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFF,0xFF,0xCF,0xFC,0x3F,0xF0,0x3F,0xFF,0xFF,
0xFF,0xCF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFE,0xFF,0xCF,0xFF,0xFF,0xF0,0x3F,
0xFF,0xFF,0xFF,0xFF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFE,0xFF,0xCF,0xFF,0xFF,
0xF0,0x1F,0xFF,0xFF,0xFF,0xFF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFE,0xFF,0xE7,
0xFF,0xFF,0xE0,0x0F,0xFF,0xFF,0xFF,0xFF,0xFC,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFE,
0x7F,0xE7,0xFF,0xFF,0xE0,0x0F,0xFF,0xFF,0xFF,0xFF,0xF8,0xFF,0xE0,0x00,0x00,0xFF,
0xE7,0xFE,0x7F,0xF3,0xFF,0xFF,0xC0,0x07,0xFF,0xFF,0xFF,0xFF,0xF8,0xFF,0xE0,0x00,
0x00,0xFF,0xE7,0xFE,0x7F,0xF1,0xFF,0xFF,0xC0,0x03,0xFF,0xFF,0xDF,0xFF,0xF0,0xFF,
0xE0,0x00,0x00,0xFF,0xE7,0xFE,0x3F,0xF8,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0x8F,0xFF,
0xF0,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFE,0x3F,0xF8,0xFF,0xFF,0x00,0x01,0xFF,0xFF,
0x0F,0xFF,0xE0,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFE,0x1F,0xF8,0x7F,0xFE,0x00,0x00,
0x7F,0xFE,0x07,0xFF,0xC0,0xFF,0xE0,0x00,0x00,0xFF,0xE7,0xFE,0x1F,0xF8,0x3F,0xF8,
0x00,0x00,0x1F,0xF8,0x03,0xFF,0x00,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/* END */
