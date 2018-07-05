 /**********************************************************************
         ___   ___
 Vp   1 |*  \_/   | 22  A0
 I2   2 |         | 21  AF
 I1   3 |         | 20  CB
 NC   4 |         | 19  NC
 TP3  5 | Votrax  | 18  Vg
 TP2  6 | SC-01 A | 17  TP1
 STB  7 |         | 16  MCRC
 A/R  8 |         | 15  MCX
 P5   9 |         | 14  P0
 P4  10 |         | 13  P1
 P3  11 |_________| 12  P2
  
 **********************************************************************
 */
#define PIN_DATA 11
#define PIN_CLOCK 13
#define PIN_LATCH 10
#define PIN_ENABLE 4
#define PIN_CLEAR 5
#define PIN_STB 2  // Strobe need to go high to latch data (was D2)
#define PIN_AR 3  // Acknowledge/Request goes high when ready (was D3)
int PIN_I1 = 0;   // Inflection bit1 (votrax pin 3 via buffer) (was D5)
int PIN_I2 = 0;   // Inflection bit2 (votrax pin 2 via buffer) (was D4)
 
// define all the phonemes
 
#define _EH3 0x00 // 59 MS ;JACKET
#define _EH2 0x01 // 71 MS ;ENLIST
#define _EH1 0x02 // 121MS ;HEAVY
#define _PA0 0x03 // 47 MS ;NO SOUND
#define _DT 0x04 // 47 MS ;BUTTER
#define _A2 0x05 // 71 MS ;MADE
#define _A1 0x06 // 103MS ;MADE
#define _ZH  0x07 // 90 MS ;AZURE
#define _AH2 0x08 // 71 MS ;HONEST -
#define _I3  0x09 // 55 MS ;INHIBIT
#define _I2  0x0A // 80 MS ;INHIBIT
#define _I1  0x0B // 121MS ;INHIBIT
#define _M  0x0C // 103MS ;MAT
#define _N  0x0D // 80 MS ;SUN
#define _B  0x0E // 71 MS ;BAG
#define _V  0x0F // 71 MS ;VAN
#define _CH  0x10 // 71 MS ;CHIP
#define _SH  0x11 // 121MS ;SHOP
#define _Z  0x12 // 71 MS ;ZOO
#define _AW1 0x13 // 146MS ;LAWFUL
#define _NG  0x14 // 121MS ;THING
#define _AH1 0x15 // 146MS ;FATHER
#define _OO1 0x16 // 103MS ;LOOKING
#define _OO  0x17 // 185MS ;BOOK
#define _L  0x18 // 103MS ;LAND
#define _K  0x19 // 80 MS ;TRICK
#define _J  0x1A // 47 MS ;JUDGE
#define _H  0x1B // 71 MS ;HELLO
#define _G  0x1C // 71 MS ;GET
#define _F  0x1D // 103MS ;FAST
#define _D  0x1E // 55 MS ;PAID
#define _S  0x1F // 90 MS ;PASS
#define _A  0x20 // 185MS ;DAY
#define _AY  0x21 // 65 MS ;DAY
#define _Y1  0x22 // 80 MS ;YARD
#define _UH3 0x23 // 47 MS ;MISSION
#define _AH  0x24 // 250MS ;MOP
#define _P  0x25 // 103MS ;PAST
#define _O  0x26 // 185MS ;COLD
#define _I  0x27 // 185MS ;PIN
#define _U  0x28 // 185MS ;MOVE
#define _Y  0x29 // 103MS ;ANY
#define _T  0x2A // 71 MS ;TAP
#define _R  0x2B // 90 MS ;RED
#define _E  0x2C // 185MS ;MEET
#define _W  0x2D // 80 MS ;WIN
#define _AE  0x2E // 185MS ;DAD
#define _AE1 0x2F // 103MS ;AFTER
#define _AW2 0x30 // 90 MS ;SALTY
#define _UH2 0x31 // 71 MS ;ABOUT
#define _UH1 0x32 // 103MS ;UNCLE
#define _UH  0x33 // 185MS ;CUP
#define _O2  0x34 // 80 MS ;FOR
#define _O1  0x35 // 121MS ;ABOARD
#define _IU  0x36 // 59 MS ;YOU
#define _U1  0x37 // 90 MS ;YOU
#define _THV 0x38 // 80 MS ;THE
#define _TH  0x39 // 71 MS ;THIN
#define _ER  0x3A // 146MS ;BIRD
#define _EH  0x3B // 185MS ;GET
#define _E1  0x3C // 121MS ;BE
#define _AW  0x3D // 250MS ;CALL
#define _PA1 0x3E // 185MS ;NO SOUND
#define _STOP 0x3F // 47 MS ;NO SOUND
 
#define _END 99  // End of phrase
 
#define _INFL0 100 // Inflection 0 (default mode)
#define _INFL1 101 // Inflection 1
#define _INFL2 102 // Inflection 2
#define _INFL3 103 // Inflection 3
#define _HOLD1 200 // wait 300 ms
#define _HOLD2 201 // wait 600 ms
 
void setup()
{
  Serial.begin(115200);
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);
  pinMode(PIN_ENABLE, OUTPUT);
  pinMode(PIN_CLEAR, OUTPUT);
  
  pinMode(PIN_STB, OUTPUT);
  pinMode(PIN_AR, INPUT);
  
  digitalWrite(PIN_ENABLE, LOW);
  digitalWrite(PIN_CLEAR, HIGH);
  digitalWrite(PIN_STB, LOW);   // must stay low
}

void loop()
{
 
  byte radioactive[]={
    _INFL2,
    _T,_CH,_ER,_HOLD1,_N,_O,_HOLD1,_B,_INFL3,_I,_HOLD1,_L,_PA1,_HOLD1,_INFL1,       // Tchernobyl
    _H,_A1,_HOLD1,_R,_E,_HOLD1,_S,_B,_ER,_HOLD1,_G,_HOLD1,                          // Harrisburg
    _S,_EH1,_HOLD1,_L,_AH2,_HOLD1,_F,_INFL2,_E,_HOLD1,_L,_D,_PA1,_INFL2,_HOLD1,     // Sellafield
    _F,_U,_HOLD2,_K,_U,_HOLD2,_SH,_E,_HOLD2,_M,_INFL0,_AW2,_HOLD2,                  // Fukushima
    _STOP  };
 
    //speak (radioactive);
 
  byte votrax[]={
 
    _INFL0,
    _V,_O,_T,_R,_UH,_K,_S,_PA1,                       // Votrax
    _INFL1,_EH1, _EH2, _S,_PA0,                       // S
    _S, _E1, _Y,_PA0,                                 // C
    _Z,_AY,_I1,_R,_O1,_U1,_PA0,                       // Zero
    _W,_UH1,_UH2,_N,_PA0,                             // One
    _A,_AY,_Y,_PA1,_INFL2,                            // A
    _S,_P,_E1,_Y,_T,_CH,_PA0,                         // Speech
    _S,_I,_N,_T,_EH2,_S, _AH1,_E1,_Z,_ER,_PA0,_INFL3, // Synthesizer
    _R, _EH1, _EH3, _D, _Y,_STOP  };                  // Ready
 
   //speak (votrax);
 
  byte inflection[]={
    _INFL0,_V,_O,_T,_R,_UH,_K,_S,_PA1,          // Votrax
    _INFL1,_V,_O,_T,_R,_UH,_K,_S,_PA1,
    _INFL2,_V,_O,_T,_R,_UH,_K,_S,_PA1,
    _INFL3,_V,_O,_T,_R,_UH,_K,_S,_PA1,
    _STOP  };
 
    //speak (inflection);
   
   byte alicia[]={
     _INFL0,_AH,_L,_E,_SH,_I,_A,_PA1,
     _INFL1,_AH,_I,_E,_L,_U,_V,_Y,_OO,_PA0,
     _STOP };
   
   //speak(alicia);
   
   byte homer[]={
      _INFL0,_H,_AH1,_HOLD1,_O2,_HOLD1,_M,_AH,_HOLD1,_EH1,_HOLD1,_ER,_HOLD1,
     _STOP }; 
   //speak(homer);

   byte cody[]={
    _INFL0,_H,_EH1,_Y,_PA1,_K,_O2,_D,_Y,_PA1,_U,_Z,_PA0,_M,_E,_PA0,_T,_OO,_PA0,_M,_A2,_K,_PA0,_M,_Y,_U,_Z,_I,_K,_STOP
   };
   speak(cody);
 // for (int i = 0; i < 0xFF; i++)
// { 
  //   byte randomByte = random(byte(0x3F));
//     say(i);
  //   Serial.print("Saying: ");
 //    Serial.println(i);
  //   delay(100); // delay 2 sec between repetition
  // }
}

unsigned char Bit_Reverse( unsigned char x ) 
{ 
   x = ((x >> 1) & 0x55) | ((x << 1) & 0xaa); 
   x = ((x >> 2) & 0x33) | ((x << 2) & 0xcc); 
   x = ((x >> 4) & 0x0f) | ((x << 4) & 0xf0); 
   return x;    
}
 
void speak (byte* message){
 
  int i=0;
  do
  {
    say(message[i]);
    i++;
 
  }
  while (message[i-1]!=_STOP);
 
}
 
 
void say(byte phoneme) {
  while (digitalRead(PIN_AR) == 0);
  switch (phoneme) {
    case _INFL0:
      PIN_I1 =  0;
      PIN_I2 =  0;
      break;
   
    case _INFL1:
      PIN_I1 =  1;
      PIN_I2 =  0;
      break;
   
    case _INFL2:
      PIN_I1 =  0;
      PIN_I2 =  1;
      break;
   
    case _INFL3:
      PIN_I1 =  1;
      PIN_I2 =  1;
      break;
   
    case _HOLD1:
      delay (75);
      break;
   
    case _HOLD2:
      delay (200);
      break;
   
   
    default:
      digitalWrite(PIN_LATCH, LOW);
      shiftOut(PIN_DATA, PIN_CLOCK, LSBFIRST, Bit_Reverse(phoneme|(PIN_I1<<6)|(PIN_I2<<7)));
      digitalWrite(PIN_LATCH, HIGH);
      //PORTB = phoneme;
      // Set PIN_STB = 1 for 5usec to tell the chip to read the Port (Jean-Luc had 2usec, dunno why I changed it, but it works)
      digitalWrite(PIN_STB, HIGH);
      delayMicroseconds(5);
      digitalWrite(PIN_STB, LOW);
      break;
  }
}

