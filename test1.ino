
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

bool überprüfKipp()
{
    if (digitalRead(kippPins[0]) == LOW)
    {
        if (digitalRead(kippPins[1]) == HIGH)
        {
            if (digitalRead(kippPins[2]) == LOW)
            {
                if (digitalRead(kippPins[3]) == LOW)
                {
                    return true;
                }
//---------------------------------------
                else {return false;}
            }
//---------------------------------------
            else {return false;}
        }
//---------------------------------------
        else {return false;}
    }
//---------------------------------------
    else {return false;}
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
            case 0:
                /* code */
                break;
            
            case 1:
                /* code */
                break;
            
            case 2:
                /* code */
                break;
            
            case 3:
                /* code */
                break;
            
            case 4:
                /* code */
                break;
            }
            delay(200);
        }
    }
}