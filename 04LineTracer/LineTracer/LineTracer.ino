const int _RIGHT_IR_PIN_ = A7;
const int _LEFT_IR_PIN_ = A6;

const int _RIGHT_PWM_PIN_ = 6;
const int _RIGHT_DIR_PIN_ = 8;

const int _LEFT_PWM_PIN_ = 5;
const int _LEFT_DIR_PIN_ = 7;

const int _BTN_UP_ = A0;    // UP 
const int _BTN_DOWN_ = A1;  // Down

// 높아지면 STOP
int _nLeftReference;
int _nRightReference;

class Wheel
{
private:
  int _pwmPin;
  int _dirPin;
  int _curDuty;
  bool _bRightwheel;
  const int _REF_DUTY_ = 120;
public:  
  Wheel()
  : _pwmPin(0)
  , _bRightwheel(false)
  , _dirPin(0)
  , _curDuty(_REF_DUTY_)
  {
    
  }
  void Init(int pwmPin, int dirPin, bool bRightWheel) 
  {
    _pwmPin = pwmPin;
    _dirPin = dirPin;
    _bRightwheel = bRightWheel;
    pinMode(_pwmPin, OUTPUT);
    pinMode(_dirPin, OUTPUT);
    digitalWrite(_dirPin, (_bRightwheel)?LOW:HIGH);   
     
    analogWrite(_pwmPin, _curDuty - (bRightWheel)?10:0);
  }
  void Start(){
    _curDuty = _REF_DUTY_;
    analogWrite(_pwmPin, _curDuty);  
  }
  void StepDown()
  {
    if (_curDuty > 8)
      _curDuty -=8;
    analogWrite(_pwmPin, _curDuty);
  }
  void StepToREF()
  {
    if (_curDuty < _REF_DUTY_)
    {
      _curDuty+=5;
      analogWrite(_pwmPin, _curDuty);
    }
  }
  void Stop()
  {
    _curDuty = 0;
    analogWrite(_pwmPin, _curDuty);
  }
};
class Button
{
private:
  int _nPinNumber;
  int _nCurState;
    
  bool _bRepeatFlag; 
  const int _REPEAT_INTERVAL_ = 15;  
  int  _nLastRepeatTime;
public:
  Button()
  : _nPinNumber(0)
  , _bRepeatFlag(false)
  , _nLastRepeatTime(millis())
  , _nCurState(HIGH)
  {
  }
  void Init(int nPin, bool bRepeat = false)
  {
    _nPinNumber = nPin;
    _bRepeatFlag = bRepeat;
    pinMode(_nPinNumber, INPUT);
  }
  bool Check() 
  {
    bool bEvent = false;
    int nCurState = digitalRead(_nPinNumber);
    if (nCurState) 
    {
      _nCurState = nCurState;
    } 
    else 
    { 
      if (nCurState != _nCurState) // Event Occured 
      {
        _nCurState = nCurState;
        _nLastRepeatTime = millis();    
        bEvent = true;
      } 
      else if (_bRepeatFlag) 
      {  // Repeat Check
        int cur = millis();
        if (cur > _nLastRepeatTime + _REPEAT_INTERVAL_) 
        {
          _nLastRepeatTime = cur;  
          bEvent = true;
        }
      }
    }
    return bEvent;
  }
};

Wheel rightW;
Wheel leftW;

Button btnUP;
Button btnDown;

void Trace()
{
  // put your main code here, to run repeatedly:
  int right = analogRead(_RIGHT_IR_PIN_)>>6;
  int left = analogRead(_LEFT_IR_PIN_)>>6;
  
  //Serial.print( String(left)+ "["+String(_nLeftReference)+"]"+"/"+String(right)+"["+String(_nRightReference)+"]"+"\n");  

  if (right > _nRightReference) {
    rightW.StepDown();
  } else {
    rightW.StepToREF();
  }
  if (left > _nLeftReference) {
    leftW.StepDown();
  } else {
    leftW.StepToREF();
  }
}



void setup() {
  // put your setup code here, to run once:
  pinMode(_RIGHT_IR_PIN_, INPUT);
  pinMode(_LEFT_IR_PIN_, INPUT);
  Serial.begin(9600);

  rightW.Init(_RIGHT_PWM_PIN_, _RIGHT_DIR_PIN_, true);
  leftW.Init(_LEFT_PWM_PIN_, _LEFT_DIR_PIN_, false);
  btnUP.Init(_BTN_UP_, false);
  btnDown.Init(_BTN_DOWN_, false);
}
bool g_bRun = false;
void loop() {
  if (btnUP.Check() && (!g_bRun)){
    _nRightReference = (analogRead(_RIGHT_IR_PIN_)>>6);
    _nLeftReference= (analogRead(_LEFT_IR_PIN_)>>6);
    rightW.Start();
    g_bRun = true;
    leftW.Start();
  }
  if (btnDown.Check() && (g_bRun)){
    g_bRun = false;
    leftW.Stop();
    rightW.Stop();
  }
  if (g_bRun){
    Trace();
  }
}
