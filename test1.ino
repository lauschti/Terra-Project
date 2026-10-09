const int poti1max = 30;
const int poti1min = 20;
const int poti2max = 30;
const int poti2min = 20;
const int poti3max = 30;
const int poti3min = 20;

bool module1 = false;
bool module2 = false;
bool module3 = false;
bool module4 = false;
bool module5 = false;
bool module6 = false;

int fehler = 0;

//-------KEYPAD-PINS-------
const int rowPins[4] = {22, 23, 24, 25};
const int colPins[4] = {26, 27, 28, 29};

//-------POTI-PINS-------
const int potiPins[3] = {A1, A2, A3};

//-------KIPPSCHALTER-PINS-------
const int kippPins[6] = {4, 5, 6, 7, 10, 11};

//-------KABEL-PINS-------
const int kabelPins[5] = {13, 14, 15, 16, 17};

//-------Taster-PINS-------
const int tastPins[5] = {2, 3, 8, 9, 12}; 

//-------LED-PINS-------
const int LEDROT = 30;
const int LEDGRUEN = 31;

void initKEYPAD()
{
    for (int i = 0; i<4; i++)
    {
        pinMode(rowPins[i], OUTPUT);
        pinMode(colPins[i], INPUT_PULLUP);
    }
}
   
void initKIPP()
{
    for (int i = 0; i<6; i++)
    {
        pinMode(kippPins[i], INPUT_PULLUP);
    }
}

void initKABEL()
{
    for (int i = 0; i<5; i++)
    {
        pinMode(kabelPins[i], INPUT_PULLUP);
    }
}

void initTAST()
{
    for (int i = 0; i<5; i++)
    {
        pinMode(tastPins[i], INPUT_PULLUP);
    }
}

bool ueberpruefKipp()
{
    return(digitalRead(kippPins[0]) == LOW && digitalRead(kippPins[1]) == HIGH && digitalRead(kippPins[2]) == LOW && digitalRead(kippPins[3]) == LOW);
}

bool ueberpruefPoti()
{
    return(analogRead(potiPins[0]) >= poti1min && analogRead(potiPins[0]) <= poti1max && analogRead(potiPins[1]) >= poti2min && analogRead(potiPins[1]) <= poti2max && analogRead(potiPins[2]) >= poti3min && analogRead(potiPins[2]) <= poti3max);
}

bool ueberpruefGeheim()
{
    return (digitalRead(kippPins[4])==LOW && digitalRead(kippPins[5])==HIGH);
}

void richtig(int modulnummer)
{
    // was passiert, wenn richtig entschärft
    digitalWrite(LEDGRUEN, HIGH);
    delay(2000);
    digitalWrite(LEDGRUEN, LOW);

    switch (modulnummer)
    {
    case 1:
        module1 = true;
        break;
    
    case 2:
        module2 = true;
        break;
    
    case 3:
        module3 = true;
        break;
    
    case 4:
        module4 = true;
        break;
    
    case 5:
        module5 = true;
        break;
    
    case 6:
        module6 = true;
        break;
    }
}

void falsch(int modulnummer)
{
    //was passiert, wenn fehler
    digitalWrite(LEDROT, HIGH);
    delay(2000);
    digitalWrite(LEDROT, LOW);

    fehler = fehler + 1;

    if (fehler >= 3)
    {
        Serial.println("GAME OVER");
        while (true)
        {
            digitalWrite(LEDROT, HIGH);
            delay(500);
            digitalWrite(LEDROT, LOW);
            delay(500);
        }
    }


    switch (modulnummer)
    {
    case 1:
        module1 = true;
        break;
    
    case 2:
        module2 = true;
        break;
    
    case 3:
        module3 = true;
        break;
    
    case 4:
        module4 = true;
        break;
    
    case 5:
        module5 = true;
        break;
    
    case 6:
        module6 = true;
        break;
    }
}

void setup()
{ 
    //setup with minimal user-experience
    Serial.begin(9600);
    initKEYPAD();
    Serial.println("KEYPAD INITIALISIERT");
    initKIPP();
    Serial.println("KIPPSCHALTER INITIALISIERT");
    initKABEL();
    Serial.println("KABEL INITIALISIERT");
    initTAST();
    Serial.println("TASTER INITIALISIERT");
}

void loop()
{
    for (int i = 0; i<5; i++)
    {
        if (digitalRead(tastPins[i]) == LOW)
        {
            switch (i)
            {
//---------------------------------------
            case 0: //D2 (Poti) Modul 1 (Potentiometer)
                if (ueberpruefPoti())
                {
                    richtig(1);
                }
                else
                {
                    falsch(1);
                }
                break;
//---------------------------------------
            case 1: //D3 (kipp) Modul 2 (Kippschalter)
                if (ueberpruefKipp())
                {
                    richtig(2);
                }
                else 
                {
                    falsch(2);
                }
                break;
//---------------------------------------
            case 2: //D8 Modul 4 (Taster)
                richtig(4);
                break;
//---------------------------------------
            case 3: //D9 Modul 4 (Taster)
                falsch(4);
                break;
//---------------------------------------
            case 4: //D12 Modul 5 (geheim)
                if (ueberpruefGeheim())
                {
                    richtig(5);
                }
                else
                {
                    falsch(5);
                }
                break;
//---------------------------------------
            }
            delay(200);
        }
    }
}
