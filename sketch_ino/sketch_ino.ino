#include <Arduino.h>

#include <Adafruit_NeoPixel.h> // Biblioteca para controle da fita LED
// Necessário para Trinket Adafruit de 16 MHz
#ifdef __AVR__
#include <avr/power.h>
#endif

#define DATA_PIN 2  // Pino de E/S digital conectado aos NeoPixels.
#define NUM_LEDS 45 // Número de LEDs na fita

int _UM = 0;       //1        A   	  RainbowCycle
int _DOIS = 0;     //2        B   	  Rainbow
int _TRES = 0;     //3        C   	  FadeInOut
int _QUATRO = 0;   //4        D   	  Random
int _CINCO = 0;    //5        E   	  Running Lights	(RED)
int _SEIS = 0;     //6        F   	  Running Lights	(GREEN)
int _SETE = 0;     //7        G   	  Running Lights  (BLUE)
int _OITO = 0;     //8        H   	  Running Lights  (WHITE)
int _NOVE = 0;     //9        I   	  Color Wipe      (BLUE)
int _DEZ = 0;      //a        J   	  Color Wipe      (CIAN)
int _ONZE = 0;     //b        K   	  Color Wipe      (GREEN)
int _DOZE = 0;     //c        L   	  Color Wipe      (MAGENTA)
int _TREZE = 0;    //d        M   	  Color Wipe      (RED)
int _QUATORZE = 0; //e        N   	  Color Wipe      (WHITE)

//variaveis switch para trocas
char dado;
char troca;

//***PROTOTIPAÇÃO DE FUNÇÕES***
void rainbowCycle(int SpeedDelay);
byte *Wheel(byte WheelPos); /*PERTENCE A RAINBOW CYCLE*/
void rainbow(uint8_t wait);
uint32_t Wheel2(byte WheelPos); /*PERTENCE A RAINBOW*/
void FadeInOut(byte red, byte green, byte blue);
void RunningLights(byte red, byte green, byte blue, int WaveDelay);
void colorWipe(byte red, byte green, byte blue, int SpeedDelay);
// ***NOT REPLACE HERE***
void showStrip();
void setPixel(int Pixel, byte red, byte green, byte blue);
void setAll(byte red, byte green, byte blue);

// FUNCTION RESET ARDUINO
void (*funcReset)() = 0;

// Cria um "objeto" Adafruit_NeoPixel (Fita LED)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  // Estas linhas são especificamente para suportar a Adafruit Trinket 5V 16 MHz.
  // Qualquer outra placa, você pode remover esta parte (mas nenhum dano deixando-a)
#if defined(__AVR_ATtiny85__)
  if (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
#endif
  // FIM do código específico do Trinket.
  Serial.begin(9600);       //frequência da porta serial
  strip.begin();            //Inicialize o objeto de tira NeoPixel (NECESSÁRIO)
  strip.show();             //DESLIGUE todos os pixels o mais rápido possível
  strip.setBrightness(25); //Brilho da tira
}

void loop()
{
  if (Serial.available() > 0) //verifica se existe comunicação com a porta serial
  {
    dado = Serial.read(); //lê os dados da porta serial

    switch (dado)
    {
      //EFEITOS
      case '1':
        while (_UM < 2048)
        {
          rainbowCycle(30);
          _UM++;
        }
        break;

      case '2':
        while (_DOIS < 2048)
        {
          rainbow(20);
          _DOIS++;
        }
        break;

      case '3':
        while (_TRES < 2048)
        {
          FadeInOut(0xff, 0x00, 0xff); // magenta
          FadeInOut(0x00, 0x00, 0xff); // blue
          FadeInOut(0x00, 0xff, 0xff); // ciano
          FadeInOut(0x00, 0xff, 0x00); // green
          FadeInOut(0xff, 0xff, 0x00); // yellow
          FadeInOut(0xff, 0x00, 0x00); // red
          FadeInOut(0xff, 0x14, 0x93); // pink
          _TRES++;
        }
        break;

      case '4':
        while (_QUATRO < 2048)
        {
          /*random*/
          rainbowCycle(10);
          rainbow(10);
          FadeInOut(0xff, 0x00, 0xff);         // magenta
          FadeInOut(0x00, 0x00, 0xff);         // blue
          FadeInOut(0x00, 0xff, 0xff);         // ciano
          FadeInOut(0x00, 0xff, 0x00);         // green
          FadeInOut(0xff, 0xff, 0x00);         // yellow
          FadeInOut(0xff, 0x00, 0x00);         // red
          FadeInOut(0xff, 0x14, 0x93);         // pink
          RunningLights(0xff, 0x00, 0x00, 50); //red
          RunningLights(0x00, 0xff, 0x00, 50); //green
          RunningLights(0x00, 0x00, 0xff, 50); //blue
          RunningLights(0xff, 0xff, 0xff, 50); //white
          colorWipe(0x00, 0x00, 0xff, 50);     //blue
          colorWipe(0x00, 0xff, 0xff, 50);     //Ciano
          colorWipe(0x00, 0xff, 0x00, 50);     //Green
          colorWipe(0xff, 0x00, 0xff, 50);     //Magenta
          colorWipe(0xff, 0x00, 0x00, 50);     //Red
          colorWipe(0xff, 0xff, 0xff, 50);     //white
          _QUATRO++;
        }
        break;

      case '5':
        while (_CINCO < 2048)
        {
          RunningLights(0xff, 0x00, 0x00, 50); //red
          _CINCO++;
        }
        break;

      case '6':
        while (_SEIS < 2048)
        {
          RunningLights(0x00, 0xff, 0x00, 50); //green
          _SEIS++;
        }
        break;

      case '7':
        while (_SETE < 2048)
        {
          RunningLights(0x00, 0x00, 0xff, 50); //blue
          _SETE++;
        }
        break;

      case '8':
        while (_OITO < 2048)
        {
          RunningLights(0xff, 0xff, 0xff, 50); //white
          _OITO++;
        }
        break;

      case '9':
        while (_NOVE < 2048)
        {
          colorWipe(0x00, 0x00, 0xff, 50); //blue
          _NOVE++;
        }
        break;

      case 'a':
        while (_DEZ < 2048)
        {
          colorWipe(0x00, 0xff, 0xff, 50); //Ciano
          _DEZ++;
        }
        break;

      case 'b':
        while (_ONZE < 2048)
        {
          colorWipe(0x00, 0xff, 0x00, 50); //Green
          _ONZE++;
        };
        break;

      case 'c':
        while (_DOZE < 2048)
        {
          colorWipe(0xff, 0x00, 0xff, 50); //Magenta
          _DOZE++;
        }
        break;

      case 'd':
        while (_TREZE < 2048)
        {
          colorWipe(0xff, 0x00, 0x00, 50); //Red
          _TREZE++;
        }
        break;

      case 'e':
        while (_QUATORZE < 2048)
        {
          colorWipe(0xff, 0xff, 0xff, 50); //white
          _QUATORZE++;
        }
        break;

      default:
        Serial.println(dado);
        break;
    }
  }
}

void rainbowCycle(int SpeedDelay)
{
  byte *c;
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++)
  { // 5 ciclos de todas as cores na roda
    for (i = 0; i < NUM_LEDS; i++)
    {
      c = Wheel(((i * 256 / NUM_LEDS) + j) & 255);
      setPixel(i, *c, *(c + 1), *(c + 2));
      /***/
      if (Serial.available() > 0)
      {
        troca = Serial.read(); //lê os dados da porta serial

        switch (troca)
        {

          case '0':
            funcReset(); //Reset
            break;

          // case 'a':
          //   while (_UM < 2048)
          //   {
          //     rainbowCycle(30);
          //     _UM++;
          //   }
          //   break;

          case 'b':
            while (_DOIS < 2048)
            {
              rainbow(20);
              _DOIS++;
            }
            break;

          case 'c':
            while (_TRES < 2048)
            {
              FadeInOut(0xff, 0x00, 0xff); // magenta
              FadeInOut(0x00, 0x00, 0xff); // blue
              FadeInOut(0x00, 0xff, 0xff); // ciano
              FadeInOut(0x00, 0xff, 0x00); // green
              FadeInOut(0xff, 0xff, 0x00); // yellow
              FadeInOut(0xff, 0x00, 0x00); // red
              FadeInOut(0xff, 0x14, 0x93); // pink
              _TRES++;
            }
            break;

          case 'd':
            while (_QUATRO < 2048)
            {
              /*random*/
              rainbowCycle(30);
              rainbow(20);
              FadeInOut(0xff, 0x00, 0xff);         // magenta
              FadeInOut(0x00, 0x00, 0xff);         // blue
              FadeInOut(0x00, 0xff, 0xff);         // ciano
              FadeInOut(0x00, 0xff, 0x00);         // green
              FadeInOut(0xff, 0xff, 0x00);         // yellow
              FadeInOut(0xff, 0x00, 0x00);         // red
              FadeInOut(0xff, 0x14, 0x93);         // pink
              RunningLights(0xff, 0x00, 0x00, 50); //red
              RunningLights(0x00, 0xff, 0x00, 50); //green
              RunningLights(0x00, 0x00, 0xff, 50); //blue
              RunningLights(0xff, 0xff, 0xff, 50); //white
              colorWipe(0x00, 0x00, 0xff, 50);     //blue
              colorWipe(0x00, 0xff, 0xff, 50);     //Ciano
              colorWipe(0x00, 0xff, 0x00, 50);     //Green
              colorWipe(0xff, 0x00, 0xff, 50);     //Magenta
              colorWipe(0xff, 0x00, 0x00, 50);     //Red
              colorWipe(0xff, 0xff, 0xff, 50);     //white
              _QUATRO++;
            }
            break;

          case 'e':
            while (_CINCO < 2048)
            {
              RunningLights(0xff, 0x00, 0x00, 50); //red
              _CINCO++;
            }
            break;

          case 'f':
            while (_SEIS < 2048)
            {
              RunningLights(0x00, 0xff, 0x00, 50); //green
              _SEIS++;
            }
            break;

          case 'g':
            while (_SETE < 2048)
            {
              RunningLights(0x00, 0x00, 0xff, 50); //blue
              _SETE++;
            }
            break;

          case 'h':
            while (_OITO < 2048)
            {
              RunningLights(0xff, 0xff, 0xff, 50); //white
              _OITO++;
            }
            break;

          case 'i':
            while (_NOVE < 2048)
            {
              colorWipe(0x00, 0x00, 0xff, 50); //blue
              _NOVE++;
            }
            break;

          case 'j':
            while (_DEZ < 2048)
            {
              colorWipe(0x00, 0xff, 0xff, 50); //Ciano
              _DEZ++;
            }
            break;

          case 'k':
            while (_ONZE < 2048)
            {
              colorWipe(0x00, 0xff, 0x00, 50); //Green
              _ONZE++;
            };

          case 'l':
            while (_DOZE < 2048)
            {
              colorWipe(0xff, 0x00, 0xff, 50); //Magenta
              _DOZE++;
            }

            break;
          case 'm':
            while (_TREZE < 2048)
            {
              colorWipe(0xff, 0x00, 0x00, 50); //Red
              _TREZE++;
            }

            break;
          case 'n':
            while (_QUATORZE < 2048)
            {
              colorWipe(0xff, 0xff, 0xff, 50); //white
              _QUATORZE++;
            }

            break;

          default:
            Serial.println(troca);
            break;
        }
      }
      /***/
    }
    showStrip();
    delay(SpeedDelay);
  }
}

byte *Wheel(byte WheelPos) /*PERTENCE A RAINBOW CYCLE*/
{
  static byte c[3];

  if (WheelPos < 85)
  {
    c[0] = WheelPos * 3;
    c[1] = 255 - WheelPos * 3;
    c[2] = 0;
  }
  else if (WheelPos < 170)
  {
    WheelPos -= 85;
    c[0] = 255 - WheelPos * 3;
    c[1] = 0;
    c[2] = WheelPos * 3;
  }
  else
  {
    WheelPos -= 170;
    c[0] = 0;
    c[1] = WheelPos * 3;
    c[2] = 255 - WheelPos * 3;
  }

  return c;
}

void rainbow(uint8_t wait)
{
  uint16_t i, j;

  for (j = 0; j < 256; j++)
  {
    for (i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, Wheel2((i + j) & 255));
      /***/
      if (Serial.available() > 0)
      {
        troca = Serial.read(); //lê os dados da porta serial

        switch (troca)
        {

          case '0':
            funcReset(); //Reset
            break;

          case 'a':
            while (_UM < 2048)
            {
              rainbowCycle(30);
              _UM++;
            }
            break;

          // case 'b':
          //   while (_DOIS < 2048)
          //   {
          //     rainbow(20);
          //     _DOIS++;
          //   }
          //   break;

          case 'c':
            while (_TRES < 2048)
            {
              FadeInOut(0xff, 0x00, 0xff); // magenta
              FadeInOut(0x00, 0x00, 0xff); // blue
              FadeInOut(0x00, 0xff, 0xff); // ciano
              FadeInOut(0x00, 0xff, 0x00); // green
              FadeInOut(0xff, 0xff, 0x00); // yellow
              FadeInOut(0xff, 0x00, 0x00); // red
              FadeInOut(0xff, 0x14, 0x93); // pink
              _TRES++;
            }
            break;

          case 'd':
            while (_QUATRO < 2048)
            {
              /*random*/
              rainbowCycle(30);
              rainbow(20);
              FadeInOut(0xff, 0x00, 0xff);         // magenta
              FadeInOut(0x00, 0x00, 0xff);         // blue
              FadeInOut(0x00, 0xff, 0xff);         // ciano
              FadeInOut(0x00, 0xff, 0x00);         // green
              FadeInOut(0xff, 0xff, 0x00);         // yellow
              FadeInOut(0xff, 0x00, 0x00);         // red
              FadeInOut(0xff, 0x14, 0x93);         // pink
              RunningLights(0xff, 0x00, 0x00, 50); //red
              RunningLights(0x00, 0xff, 0x00, 50); //green
              RunningLights(0x00, 0x00, 0xff, 50); //blue
              RunningLights(0xff, 0xff, 0xff, 50); //white
              colorWipe(0x00, 0x00, 0xff, 50);     //blue
              colorWipe(0x00, 0xff, 0xff, 50);     //Ciano
              colorWipe(0x00, 0xff, 0x00, 50);     //Green
              colorWipe(0xff, 0x00, 0xff, 50);     //Magenta
              colorWipe(0xff, 0x00, 0x00, 50);     //Red
              colorWipe(0xff, 0xff, 0xff, 50);     //white
              _QUATRO++;
            }
            break;

          case 'e':
            while (_CINCO < 2048)
            {
              RunningLights(0xff, 0x00, 0x00, 50); //red
              _CINCO++;
            }
            break;

          case 'f':
            while (_SEIS < 2048)
            {
              RunningLights(0x00, 0xff, 0x00, 50); //green
              _SEIS++;
            }
            break;

          case 'g':
            while (_SETE < 2048)
            {
              RunningLights(0x00, 0x00, 0xff, 50); //blue
              _SETE++;
            }
            break;

          case 'h':
            while (_OITO < 2048)
            {
              RunningLights(0xff, 0xff, 0xff, 50); //white
              _OITO++;
            }
            break;

          case 'i':
            while (_NOVE < 2048)
            {
              colorWipe(0x00, 0x00, 0xff, 50); //blue
              _NOVE++;
            }
            break;

          case 'j':
            while (_DEZ < 2048)
            {
              colorWipe(0x00, 0xff, 0xff, 50); //Ciano
              _DEZ++;
            }
            break;

          case 'k':
            while (_ONZE < 2048)
            {
              colorWipe(0x00, 0xff, 0x00, 50); //Green
              _ONZE++;
            };

          case 'l':
            while (_DOZE < 2048)
            {
              colorWipe(0xff, 0x00, 0xff, 50); //Magenta
              _DOZE++;
            }

            break;
          case 'm':
            while (_TREZE < 2048)
            {
              colorWipe(0xff, 0x00, 0x00, 50); //Red
              _TREZE++;
            }

            break;
          case 'n':
            while (_QUATORZE < 2048)
            {
              colorWipe(0xff, 0xff, 0xff, 50); //white
              _QUATORZE++;
            }

            break;

          default:
            Serial.println(troca);
            break;
        }
      }
      /***/
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel2(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85)
  {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170)
  {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void FadeInOut(byte red, byte green, byte blue)
{
  float r, g, b;

  for (int k = 0; k < 256; k = k + 1)
  {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    setAll(r, g, b);
    /***/
    if (Serial.available() > 0)
    {
      troca = Serial.read(); //lê os dados da porta serial

      switch (troca)
      {

        case '0':
          funcReset(); //Reset
          break;

        case 'a':
          while (_UM < 2048)
          {
            rainbowCycle(30);
            _UM++;
          }
          break;

        case 'b':
          while (_DOIS < 2048)
          {
            rainbow(20);
            _DOIS++;
          }
          break;

        // case 'c':
        //   while (_TRES < 2048)
        //   {
        //     FadeInOut(0xff, 0x00, 0xff); // magenta
        //     FadeInOut(0x00, 0x00, 0xff); // blue
        //     FadeInOut(0x00, 0xff, 0xff); // ciano
        //     FadeInOut(0x00, 0xff, 0x00); // green
        //     FadeInOut(0xff, 0xff, 0x00); // yellow
        //     FadeInOut(0xff, 0x00, 0x00); // red
        //     FadeInOut(0xff, 0x14, 0x93); // pink
        //     _TRES++;
        //   }
        //   break;

        case 'd':
          while (_QUATRO < 2048)
          {
            /*random*/
            rainbowCycle(30);
            rainbow(20);
            FadeInOut(0xff, 0x00, 0xff);         // magenta
            FadeInOut(0x00, 0x00, 0xff);         // blue
            FadeInOut(0x00, 0xff, 0xff);         // ciano
            FadeInOut(0x00, 0xff, 0x00);         // green
            FadeInOut(0xff, 0xff, 0x00);         // yellow
            FadeInOut(0xff, 0x00, 0x00);         // red
            FadeInOut(0xff, 0x14, 0x93);         // pink
            RunningLights(0xff, 0x00, 0x00, 50); //red
            RunningLights(0x00, 0xff, 0x00, 50); //green
            RunningLights(0x00, 0x00, 0xff, 50); //blue
            RunningLights(0xff, 0xff, 0xff, 50); //white
            colorWipe(0x00, 0x00, 0xff, 50);     //blue
            colorWipe(0x00, 0xff, 0xff, 50);     //Ciano
            colorWipe(0x00, 0xff, 0x00, 50);     //Green
            colorWipe(0xff, 0x00, 0xff, 50);     //Magenta
            colorWipe(0xff, 0x00, 0x00, 50);     //Red
            colorWipe(0xff, 0xff, 0xff, 50);     //white
            _QUATRO++;
          }
          break;

        case 'e':
          while (_CINCO < 2048)
          {
            RunningLights(0xff, 0x00, 0x00, 50); //red
            _CINCO++;
          }
          break;

        case 'f':
          while (_SEIS < 2048)
          {
            RunningLights(0x00, 0xff, 0x00, 50); //green
            _SEIS++;
          }
          break;

        case 'g':
          while (_SETE < 2048)
          {
            RunningLights(0x00, 0x00, 0xff, 50); //blue
            _SETE++;
          }
          break;

        case 'h':
          while (_OITO < 2048)
          {
            RunningLights(0xff, 0xff, 0xff, 50); //white
            _OITO++;
          }
          break;

        case 'i':
          while (_NOVE < 2048)
          {
            colorWipe(0x00, 0x00, 0xff, 50); //blue
            _NOVE++;
          }
          break;

        case 'j':
          while (_DEZ < 2048)
          {
            colorWipe(0x00, 0xff, 0xff, 50); //Ciano
            _DEZ++;
          }
          break;

        case 'k':
          while (_ONZE < 2048)
          {
            colorWipe(0x00, 0xff, 0x00, 50); //Green
            _ONZE++;
          };

        case 'l':
          while (_DOZE < 2048)
          {
            colorWipe(0xff, 0x00, 0xff, 50); //Magenta
            _DOZE++;
          }

          break;
        case 'm':
          while (_TREZE < 2048)
          {
            colorWipe(0xff, 0x00, 0x00, 50); //Red
            _TREZE++;
          }

          break;
        case 'n':
          while (_QUATORZE < 2048)
          {
            colorWipe(0xff, 0xff, 0xff, 50); //white
            _QUATORZE++;
          }

          break;

        default:
          Serial.println(troca);
          break;
      }
    }
    /***/
    showStrip();
    delay(3);
  }

  for (int k = 255; k >= 0; k = k - 2)
  {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    setAll(r, g, b);
    /***/
    if (Serial.available() > 0)
    {
      troca = Serial.read(); //lê os dados da porta serial

      switch (troca)
      {

        case '0':
          funcReset(); //Reset
          break;

        case 'a':
          while (_UM < 2048)
          {
            rainbowCycle(30);
            _UM++;
          }
          break;

        case 'b':
          while (_DOIS < 2048)
          {
            rainbow(20);
            _DOIS++;
          }
          break;

        // case 'c':
        //   while (_TRES < 2048)
        //   {
        //     FadeInOut(0xff, 0x00, 0xff); // magenta
        //     FadeInOut(0x00, 0x00, 0xff); // blue
        //     FadeInOut(0x00, 0xff, 0xff); // ciano
        //     FadeInOut(0x00, 0xff, 0x00); // green
        //     FadeInOut(0xff, 0xff, 0x00); // yellow
        //     FadeInOut(0xff, 0x00, 0x00); // red
        //     FadeInOut(0xff, 0x14, 0x93); // pink
        //     _TRES++;
        //   }
        //   break;

        case 'd':
          while (_QUATRO < 2048)
          {
            /*random*/
            rainbowCycle(30);
            rainbow(20);
            FadeInOut(0xff, 0x00, 0xff);         // magenta
            FadeInOut(0x00, 0x00, 0xff);         // blue
            FadeInOut(0x00, 0xff, 0xff);         // ciano
            FadeInOut(0x00, 0xff, 0x00);         // green
            FadeInOut(0xff, 0xff, 0x00);         // yellow
            FadeInOut(0xff, 0x00, 0x00);         // red
            FadeInOut(0xff, 0x14, 0x93);         // pink
            RunningLights(0xff, 0x00, 0x00, 50); //red
            RunningLights(0x00, 0xff, 0x00, 50); //green
            RunningLights(0x00, 0x00, 0xff, 50); //blue
            RunningLights(0xff, 0xff, 0xff, 50); //white
            colorWipe(0x00, 0x00, 0xff, 50);     //blue
            colorWipe(0x00, 0xff, 0xff, 50);     //Ciano
            colorWipe(0x00, 0xff, 0x00, 50);     //Green
            colorWipe(0xff, 0x00, 0xff, 50);     //Magenta
            colorWipe(0xff, 0x00, 0x00, 50);     //Red
            colorWipe(0xff, 0xff, 0xff, 50);     //white
            _QUATRO++;
          }
          break;

        case 'e':
          while (_CINCO < 2048)
          {
            RunningLights(0xff, 0x00, 0x00, 50); //red
            _CINCO++;
          }
          break;

        case 'f':
          while (_SEIS < 2048)
          {
            RunningLights(0x00, 0xff, 0x00, 50); //green
            _SEIS++;
          }
          break;

        case 'g':
          while (_SETE < 2048)
          {
            RunningLights(0x00, 0x00, 0xff, 50); //blue
            _SETE++;
          }
          break;

        case 'h':
          while (_OITO < 2048)
          {
            RunningLights(0xff, 0xff, 0xff, 50); //white
            _OITO++;
          }
          break;

        case 'i':
          while (_NOVE < 2048)
          {
            colorWipe(0x00, 0x00, 0xff, 50); //blue
            _NOVE++;
          }
          break;

        case 'j':
          while (_DEZ < 2048)
          {
            colorWipe(0x00, 0xff, 0xff, 50); //Ciano
            _DEZ++;
          }
          break;

        case 'k':
          while (_ONZE < 2048)
          {
            colorWipe(0x00, 0xff, 0x00, 50); //Green
            _ONZE++;
          };

        case 'l':
          while (_DOZE < 2048)
          {
            colorWipe(0xff, 0x00, 0xff, 50); //Magenta
            _DOZE++;
          }

          break;
        case 'm':
          while (_TREZE < 2048)
          {
            colorWipe(0xff, 0x00, 0x00, 50); //Red
            _TREZE++;
          }

          break;
        case 'n':
          while (_QUATORZE < 2048)
          {
            colorWipe(0xff, 0xff, 0xff, 50); //white
            _QUATORZE++;
          }

          break;

        default:
          Serial.println(troca);
          break;
      }
    }
    /***/
    showStrip();
    delay(3);
  }
}

void RunningLights(byte red, byte green, byte blue, int WaveDelay)
{
  int Position = 0;

  for (int i = 0; i < NUM_LEDS * 2; i++)
  {
    Position++; // = 0; //Position + Rate;
    //= 0; //Posição + Taxa;
    for (int i = 0; i < NUM_LEDS; i++)
    {
      //  onda seno, 3 ondas offset fazem um arco-íris!
      //  float level = sin(i+Position) * 127 + 128;
      //  setPixel(i,level,0,0);
      //  float level = sin(i+Position) * 127 + 128;
      setPixel(i, ((sin(i + Position) * 127 + 128) / 255) * red,
               ((sin(i + Position) * 127 + 128) / 255) * green,
               ((sin(i + Position) * 127 + 128) / 255) * blue);

      /***/
      if (Serial.available() > 0)
      {
        troca = Serial.read(); //lê os dados da porta serial

        switch (troca)
        {

          case '0':
            funcReset(); //Reset
            break;

          case 'a':
            while (_UM < 2048)
            {
              rainbowCycle(30);
              _UM++;
            }
            break;

          case 'b':
            while (_DOIS < 2048)
            {
              rainbow(20);
              _DOIS++;
            }
            break;

          case 'c':
            while (_TRES < 2048)
            {
              FadeInOut(0xff, 0x00, 0xff); // magenta
              FadeInOut(0x00, 0x00, 0xff); // blue
              FadeInOut(0x00, 0xff, 0xff); // ciano
              FadeInOut(0x00, 0xff, 0x00); // green
              FadeInOut(0xff, 0xff, 0x00); // yellow
              FadeInOut(0xff, 0x00, 0x00); // red
              FadeInOut(0xff, 0x14, 0x93); // pink
              _TRES++;
            }
            break;

          case 'd':
            while (_QUATRO < 2048)
            {
              /*random*/
              rainbowCycle(30);
              rainbow(20);
              FadeInOut(0xff, 0x00, 0xff);         // magenta
              FadeInOut(0x00, 0x00, 0xff);         // blue
              FadeInOut(0x00, 0xff, 0xff);         // ciano
              FadeInOut(0x00, 0xff, 0x00);         // green
              FadeInOut(0xff, 0xff, 0x00);         // yellow
              FadeInOut(0xff, 0x00, 0x00);         // red
              FadeInOut(0xff, 0x14, 0x93);         // pink
              RunningLights(0xff, 0x00, 0x00, 50); //red
              RunningLights(0x00, 0xff, 0x00, 50); //green
              RunningLights(0x00, 0x00, 0xff, 50); //blue
              RunningLights(0xff, 0xff, 0xff, 50); //white
              colorWipe(0x00, 0x00, 0xff, 50);     //blue
              colorWipe(0x00, 0xff, 0xff, 50);     //Ciano
              colorWipe(0x00, 0xff, 0x00, 50);     //Green
              colorWipe(0xff, 0x00, 0xff, 50);     //Magenta
              colorWipe(0xff, 0x00, 0x00, 50);     //Red
              colorWipe(0xff, 0xff, 0xff, 50);     //white
              _QUATRO++;
            }
            break;

          case 'e':
            while (_CINCO < 2048)
            {
              RunningLights(0xff, 0x00, 0x00, 50); //red
              _CINCO++;
            }
            break;

          case 'f':
            while (_SEIS < 2048)
            {
              RunningLights(0x00, 0xff, 0x00, 50); //green
              _SEIS++;
            }
            break;

          case 'g':
            while (_SETE < 2048)
            {
              RunningLights(0x00, 0x00, 0xff, 50); //blue
              _SETE++;
            }
            break;

          case 'h':
            while (_OITO < 2048)
            {
              RunningLights(0xff, 0xff, 0xff, 50); //white
              _OITO++;
            }
            break;

          case 'i':
            while (_NOVE < 2048)
            {
              colorWipe(0x00, 0x00, 0xff, 50); //blue
              _NOVE++;
            }
            break;

          case 'j':
            while (_DEZ < 2048)
            {
              colorWipe(0x00, 0xff, 0xff, 50); //Ciano
              _DEZ++;
            }
            break;

          case 'k':
            while (_ONZE < 2048)
            {
              colorWipe(0x00, 0xff, 0x00, 50); //Green
              _ONZE++;
            };

          case 'l':
            while (_DOZE < 2048)
            {
              colorWipe(0xff, 0x00, 0xff, 50); //Magenta
              _DOZE++;
            }

            break;
          case 'm':
            while (_TREZE < 2048)
            {
              colorWipe(0xff, 0x00, 0x00, 50); //Red
              _TREZE++;
            }

            break;
          case 'n':
            while (_QUATORZE < 2048)
            {
              colorWipe(0xff, 0xff, 0xff, 50); //white
              _QUATORZE++;
            }

            break;

          default:
            Serial.println(troca);
            break;
        }
      }
      /***/
    }

    showStrip();
    delay(WaveDelay);
  }
}

void colorWipe(byte red, byte green, byte blue, int SpeedDelay)
{
  for (uint16_t i = 0; i < NUM_LEDS; i++)
  {
    setPixel(i, red, green, blue);
    /***/
    if (Serial.available() > 0)
    {
      troca = Serial.read(); //lê os dados da porta serial

      switch (troca)
      {

        case '0':
          funcReset(); //Reset
          break;

        case 'a':
          while (_UM < 2048)
          {
            rainbowCycle(30);
            _UM++;
          }
          break;

        case 'b':
          while (_DOIS < 2048)
          {
            rainbow(20);
            _DOIS++;
          }
          break;

        case 'c':
          while (_TRES < 2048)
          {
            FadeInOut(0xff, 0x00, 0xff); // magenta
            FadeInOut(0x00, 0x00, 0xff); // blue
            FadeInOut(0x00, 0xff, 0xff); // ciano
            FadeInOut(0x00, 0xff, 0x00); // green
            FadeInOut(0xff, 0xff, 0x00); // yellow
            FadeInOut(0xff, 0x00, 0x00); // red
            FadeInOut(0xff, 0x14, 0x93); // pink
            _TRES++;
          }
          break;

        case 'd':
          while (_QUATRO < 2048)
          {
            /*random*/
            rainbowCycle(30);
            rainbow(20);
            FadeInOut(0xff, 0x00, 0xff);         // magenta
            FadeInOut(0x00, 0x00, 0xff);         // blue
            FadeInOut(0x00, 0xff, 0xff);         // ciano
            FadeInOut(0x00, 0xff, 0x00);         // green
            FadeInOut(0xff, 0xff, 0x00);         // yellow
            FadeInOut(0xff, 0x00, 0x00);         // red
            FadeInOut(0xff, 0x14, 0x93);         // pink
            RunningLights(0xff, 0x00, 0x00, 50); //red
            RunningLights(0x00, 0xff, 0x00, 50); //green
            RunningLights(0x00, 0x00, 0xff, 50); //blue
            RunningLights(0xff, 0xff, 0xff, 50); //white
            colorWipe(0x00, 0x00, 0xff, 50);     //blue
            colorWipe(0x00, 0xff, 0xff, 50);     //Ciano
            colorWipe(0x00, 0xff, 0x00, 50);     //Green
            colorWipe(0xff, 0x00, 0xff, 50);     //Magenta
            colorWipe(0xff, 0x00, 0x00, 50);     //Red
            colorWipe(0xff, 0xff, 0xff, 50);     //white
            _QUATRO++;
          }
          break;

        case 'e':
          while (_CINCO < 2048)
          {
            RunningLights(0xff, 0x00, 0x00, 50); //red
            _CINCO++;
          }
          break;

        case 'f':
          while (_SEIS < 2048)
          {
            RunningLights(0x00, 0xff, 0x00, 50); //green
            _SEIS++;
          }
          break;

        case 'g':
          while (_SETE < 2048)
          {
            RunningLights(0x00, 0x00, 0xff, 50); //blue
            _SETE++;
          }
          break;

        case 'h':
          while (_OITO < 2048)
          {
            RunningLights(0xff, 0xff, 0xff, 50); //white
            _OITO++;
          }
          break;

        case 'i':
          while (_NOVE < 2048)
          {
            colorWipe(0x00, 0x00, 0xff, 50); //blue
            _NOVE++;
          }
          break;

        case 'j':
          while (_DEZ < 2048)
          {
            colorWipe(0x00, 0xff, 0xff, 50); //Ciano
            _DEZ++;
          }
          break;

        case 'k':
          while (_ONZE < 2048)
          {
            colorWipe(0x00, 0xff, 0x00, 50); //Green
            _ONZE++;
          };

        case 'l':
          while (_DOZE < 2048)
          {
            colorWipe(0xff, 0x00, 0xff, 50); //Magenta
            _DOZE++;
          }

          break;
        case 'm':
          while (_TREZE < 2048)
          {
            colorWipe(0xff, 0x00, 0x00, 50); //Red
            _TREZE++;
          }

          break;
        case 'n':
          while (_QUATORZE < 2048)
          {
            colorWipe(0xff, 0xff, 0xff, 50); //white
            _QUATORZE++;
          }

          break;

        default:
          Serial.println(troca);
          break;
      }
    }
    /***/
    showStrip();
    delay(SpeedDelay);
  }
}

/**
  ESPACO PARA
  theaterChase
  theaterChaseRainbow
*/

// ***NOT REPLACE HERE DOWN***
void showStrip()
{
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.show();
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  FastLED.show();
#endif
}
void setPixel(int Pixel, byte red, byte green, byte blue)
{
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
#endif
}
void setAll(byte red, byte green, byte blue)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
