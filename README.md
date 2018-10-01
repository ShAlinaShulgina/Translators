# Translators

## 6

### Результат работы:

1. Вывод в терминале:

```
sInput pow(3,pow(1,pow(2,pow(1*2+1,1))))
SYMBOL_POW
SYMBOL_LP
SYMBOL_I
SYMBOL_COMMA
SYMBOL_POW
SYMBOL_LP
SYMBOL_I
SYMBOL_COMMA
SYMBOL_POW
SYMBOL_LP
SYMBOL_I
SYMBOL_COMMA
SYMBOL_POW
SYMBOL_LP
SYMBOL_I
SYMBOL_MULT
SYMBOL_I
SYMBOL_PLUS
SYMBOL_I
SYMBOL_COMMA
SYMBOL_I
SYMBOL_RP
SYMBOL_RP
SYMBOL_RP
SYMBOL_RP

YES! 3
```

2. Вывод в файл

```

Input string != Output string '---'
1+5*8+1
sx = 41
test: NO

(1+5*8)+1
sx = 42
test: YES

8*2+1
sx = 17
test: YES

Input string != Output string '---'
8*2*5
sx = 16
test: NO

Input string != Output string '---'
1+1+1
sx = 2
test: NO

1+(1+1)
sx = 3
test: YES

pow(2,2)
sx = 4
test: YES

pow(2+3,2*5)
sx = 9765625
test: YES

pow(5*2+1,2)
sx = 121
test: YES

3+pow(3*(2+3),3)
sx = 3378
test: YES

154*pow(1,0)
sx = 154
test: YES

pow(2*pow(2+2,2),2*1)
sx = 1024
test: YES

pow(pow(2,1),pow(2,0)+pow(2,2))
sx = 32
test: YES

Input string != Output string '---'
2+pow(2*4,2)*2+5
sx = 130
test: NO

Input string != Output string '---'
3+2*pow(1+3*2,2)+21
sx = 101
test: NO

Input string != Output string '---'
3+2*pow((1+3)*2,3)+21
sx = 1027
test: NO

(3+2)*pow(1+3*2,3)+21
sx = 1736
test: YES

Missing character ','
Missing character ')'
Input string != Output string '---'
2+pow(2+3*2+1,pow(1+1,1))
sx = 1118759457
test: NO

2+pow(2+3*2,pow(1+1,1))
sx = 66
test: YES

Missing character '('
2++
sx = 1118759325
test: NO

3*pow(3*pow(2+2,1),2)+2
sx = 434
test: YES

pow(1,pow(1,pow(2,pow(2+2,1))))
sx = 1
test: YES

pow(2,pow(1,pow(2,pow(1*2,1))))
sx = 2
test: YES

pow(3,pow(1,pow(2,pow(1*2+1,1))))
sx = 3
test: YES
```
