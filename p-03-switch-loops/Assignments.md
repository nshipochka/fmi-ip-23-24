# Какво ще изведе програмата? Защо?
### Програма 1
```c++
int x = 6, y = 4;
while(x > 0){
    if(x % y == 0)
        break;
    else
        x -= 1;
}
cout << x;
```

### Програма 2
```c++
int x;
x = 12;
switch(x%10){
    case 1: cout << 1;
    case 2: cout << 2;
    case 3: cout << 3; 
        break;
    case 0: cout << 0; 
        break;
    default: cout << "def";
        break; 
}
```

### Програма 3
```c++
int x = 6, y = 4;
do{
    if(x % y == 0)
        continue;
    x -= 1;
    y = y + 1;
}while(x > 0);
cout << y;
```

### Програма 4
```c++
int x, sum;
for(int i = 0; i < 6; i++){
    for(sum = 0, x = 2; x <= i; x++){
        sum += i;
    }
}
cout << sum;
```

### Програма 5
```c++
for(int i = 0; ++i < 5; i++)
    cout << n << " ";
```
# Задачи за решаване
Където се налага, валидирайте входа.

## Switch
### Задача 1
Напишете програма, която при въвеждането на число от 1 до 7
извежда деня от седмицата.
Вход: 2 Изход: Tuesday

### Задача 2
Напишете програма, която по въвеждането на буква `j, f, m или a` извежда съответния месец `January, February, March или April`

### Задача 3
Напишете програма, която по въведен знак `+, -, *, /` и две числа, извършва съответната операция.

## Loops
### Задача 4
Отпечатайте на конзолата целите числа от 0 до 10.

### Задача 5
По въведени две цели числа N и M отпечатайте на конзолата целите
числа от N до M.

### Задача 6
Напишете програма, която по въведено едно число N и едно цяло
положително число М, извежда на конзолата резултата от
повдигането на числото N на степен M. (Без да използвате `pow(n, m)`)

### Задача 7
Напишете програма, която по въведено цяло положително число N
извежда редицата на Фибоначи до N-тия член.

### Задача 8
Напишете програма, която по въведено цяло положително число N
извежда на конзолата сумата от цифрите му.  
Вход: 4523 Изход: 14 // 4+5+2+3 = 14

### Задача 9
Напишете програма, която извежда цялото неотрицателно число n в двоичен вид без водещи нули.

## Nested Loops

### Задача 10
Напишете програма, която по въведено цяло число в двоична
бройна система го превръща в десетична.      
Вход: 101 Изход: 5      
Вход: 11101 Изход: 29

### Задача 11
Да се напише програма, която по въведено цяло положително число n, прочита n на брой цели числа, а след това отпечатва общата сума от цифрите на числата.    
Например: 221, 5, 18 -> 2 + 2 + 1 + 5 + 1 + 8 = 19

### Задача 12
Да се напише програма, която по въведени числа x < 10 и y < 10 извежда на екрана:
- правоъгълник 

```
* * * * *
* * * * *
* * * * *
```
- рамка

```
* * * * *
*       *
* * * * *
```
с тези размери.

### Задача 13
Да се напише програма, която по въведено число n < 10 извежда на екрана следните картинки:
```
      *
    * *
  * * *
* * * *
  ...
```

```
  ...
* * * *
* * *
* *
*
```
до n-тия ред.

### Задача 14
Да се напише програма, която по въведено число n < 10 извежда числата до n по следните начини:
```
   1
  1 2
 1 2 3 
1 2 3 4 
  ...
```
```
  ...
1 2 3 4
 1 2 3
  1 2
   1
```
```
1     1
 2   2
  3 3 
   4
  3 3
 2   2 
1     1 
```


