#define ledPin 13  // LED는 디지털 핀 13에 연결됨

int linesensor_data[5] = {0, 0, 0, 0, 0};      // 센서 값 저장
int linesensor_pin[5]  = {34, 35, 36, 37, 38};      // 센서가 연결된 핀 번호

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(linesensor_pin[i], INPUT);
  }
}

// 단순히 센서 값을 읽고 출력만 하는 함수
void print_line_sensor() {
  for (int i = 0; i < 5; i++) {
    linesensor_data[i] = digitalRead(linesensor_pin[i]); // HIGH/LOW 읽기
    Serial.print(linesensor_data[i]);
    Serial.print(" ");
  }
  Serial.println();
}

// 라인 인덱스를 계산해서 반환하는 함수
int read_line_sensor() {
  int sum = 0;
  int line_index = 0;

  for (int i = 0; i < 5; i++) {
    linesensor_data[i] = digitalRead(linesensor_pin[i]); // HIGH/LOW 읽기
    if (linesensor_data[i] == HIGH) {
      linesensor_data[i] = 0;
    } else {
      linesensor_data[i] = 1;
      sum++;
    }
    Serial.print(linesensor_data[i]);
    Serial.print(" ");
  }

  if (sum == 1) {
    if (linesensor_data[0] == 1) line_index = -4;
    if (linesensor_data[1] == 1) line_index = -2;
    if (linesensor_data[2] == 1) line_index = 0;
    if (linesensor_data[3] == 1) line_index = 2;
    if (linesensor_data[4] == 1) line_index = 4;
  }

  if (sum == 2) {
    if (linesensor_data[0] == 1 && linesensor_data[1] == 1) line_index = -3;
    if (linesensor_data[1] == 1 && linesensor_data[2] == 1) line_index = -1;
    if (linesensor_data[2] == 1 && linesensor_data[3] == 1) line_index = 1;
    if (linesensor_data[3] == 1 && linesensor_data[4] == 1) line_index = 3;
  }

  Serial.print("Line index: ");
  Serial.println(line_index);
  return line_index;
}

void loop() {
  int pos = read_line_sensor();
  delay(200);
}
