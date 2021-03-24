/***/
if (Serial.available() > 0)
{
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