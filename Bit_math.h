#ifndef BIT_MATH_H // header guard
#define BIT_MATH_H
#define SET_BIT(Reg,BIT_number) Reg|=(1<<BIT_number)
#define GET_BIT(Reg,BIT_number) ((Reg>>BIT_number)&1)
#define CLR_BIT(Reg,BIT_number) Reg&=~(1<<BIT_number)
#define TOGGLE_BIT(Reg,BIT_number) Reg^=(1<<BIT_number)
#define SET_REG(Reg) Reg=0xFF
#define GET_REG(Reg) Reg
#define CLR_REG(Reg) Reg=0x00
#define TOGGLE_REG(Reg) Reg^=255
#define ASSIGN_REG(Reg,Value) ((Reg)=(Value))
#define GET_LOW_NIB(Reg) Reg&0x0F
#define SET_LOW_NIB(Reg) Reg|0x0F
#define CLR_LOW_NIB(Reg) Reg&0xF0
#define GET_HIGH_NIB(Reg) (Reg>>4)&0x0F
#define SET_HIGH_NIB(Reg) Reg|0xF0
#define CLR_HIGH_NIB(Reg) Reg&0x0F
#define TOGGLE_LOW_NIB(Reg) Reg^0x0F
#define TOGGLE_HIGH_NIB(Reg) Reg^0xF0
#define ASSIGN_LOW_NIB(Reg,Value) ((Reg)=(((Reg)&(0xF0))|((Value)&(0x0F))))
#define ASSIGN_HIGH_NIB(Reg,Value) ((Reg)=(Value<<4))
#endif   
