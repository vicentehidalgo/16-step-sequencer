
#define RESET 2
//saving 3, for the future

int reset_val = HIGH;
int reset_old_val = LOW;
int current_step = 4;
int first_step_pin = 4;
int last_step_pin = 19;
  
void setup ()
{
  Serial.begin(9600);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (14, OUTPUT); // A0  //Analog pins here
  pinMode (15, OUTPUT); // A1
  pinMode (16, OUTPUT); // A2
  pinMode (17, OUTPUT); // A3
  pinMode (18, OUTPUT); // A4
  pinMode (19, OUTPUT); // A5

  pinMode (RESET, INPUT);
}


void loop ()
{        
   reset_val = digitalRead (RESET);
 
   if((reset_val == HIGH) && (reset_old_val == LOW))
   {
     if (current_step == last_step_pin + 1){
      current_step = first_step_pin;
     }
    lit_step(current_step);
    current_step = current_step + 1;
   }
  reset_old_val = reset_val;
}

void lit_step(int step){
  for(int i = first_step_pin; i <= last_step_pin; i++){
    digitalWrite(i, LOW);
  }
  digitalWrite(step, HIGH);
}
