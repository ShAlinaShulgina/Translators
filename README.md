# Translators

### Грамматика:

```
<S> ::= <S> + <M> | <M>
<M> ::= <M> * <E> | <E>
<E> ::= pow( <S>, <S> ) | <F>
<F> ::= i | (<S>)
```
,где
```
<SYMBOL> - нетерминальные символы
pow ( , ) + * i = INT - терминальные символы
```

## 6

### Результат работы:

#### Вывод из test.txt

1. Вывод в терминале:

```
sInput 1+5*8+1
SYMBOL_I
SYMBOL_PLUS
SYMBOL_I
SYMBOL_MULT
SYMBOL_I
SYMBOL_PLUS
!NO! 42 != 41

ERROR
Input string != Output string ''
sInput (1+5*8)+1
SYMBOL_LP
SYMBOL_I
SYMBOL_PLUS
SYMBOL_I
SYMBOL_MULT
SYMBOL_I
SYMBOL_RP
SYMBOL_PLUS
SYMBOL_I

YES! 42

sInput 2+pow(2+3*2+1,pow(1+1,1))
SYMBOL_I
SYMBOL_PLUS
SYMBOL_POW
SYMBOL_LP
SYMBOL_I
SYMBOL_PLUS
SYMBOL_I
SYMBOL_MULT
SYMBOL_I
SYMBOL_PLUS
ERROR
Missing character ','
ERROR
Missing character ')'
!NO! 83 != 1967940001

ERROR
Input string != Output string ''
sInput 2+pow(2+3*2,pow(1+1,1))
SYMBOL_I
SYMBOL_PLUS
SYMBOL_POW
SYMBOL_LP
SYMBOL_I
SYMBOL_PLUS
SYMBOL_I
SYMBOL_MULT
SYMBOL_I
SYMBOL_COMMA
SYMBOL_POW
SYMBOL_LP
SYMBOL_I
SYMBOL_PLUS
SYMBOL_I
SYMBOL_COMMA
SYMBOL_I
SYMBOL_RP
SYMBOL_RP

YES! 66

sInput 2++
SYMBOL_I
SYMBOL_PLUS
SYMBOL_PLUS
ERROR
Missing symbol in the grammar
!NO! -1 != 1967939837
```

2. Вывод в файл

```
ERROR
Input string != Output string ''
1+5*8+1
sx = 41
test: NO

(1+5*8)+1
sx = 42
test: YES

8*2+1
sx = 17
test: YES

ERROR
Input string != Output string ''
8*2*5
sx = 16
test: NO

ERROR
Input string != Output string ''
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

ERROR
Input string != Output string ''
2+pow(2*4,2)*2+5
sx = 130
test: NO

ERROR
Input string != Output string ''
3+2*pow(1+3*2,2)+21
sx = 101
test: NO

ERROR
Input string != Output string ''
3+2*pow((1+3)*2,3)+21
sx = 1027
test: NO

(3+2)*pow(1+3*2,3)+21
sx = 1736
test: YES

ERROR
Missing character ','
ERROR
Missing character ')'
ERROR
Input string != Output string ''
2+pow(2+3*2+1,pow(1+1,1))
sx = 1967940001
test: NO

2+pow(2+3*2,pow(1+1,1))
sx = 66
test: YES

ERROR
Missing symbol in the grammar
2++
sx = 1967939837
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


#### Вывод, после приема данных от пользователя


1. Вывод в консоль после приема данных:

```
1+6*8
SYMBOL_I
SYMBOL_PLUS
SYMBOL_I
SYMBOL_MULT
SYMBOL_I

sx = 49
pow(3*2,2+3)
SYMBOL_POW
SYMBOL_LP
SYMBOL_I
SYMBOL_MULT
SYMBOL_I
SYMBOL_COMMA
SYMBOL_I
SYMBOL_PLUS
SYMBOL_I
SYMBOL_RP

sx = 7776
11+5*10
SYMBOL_I
SYMBOL_PLUS
SYMBOL_I
SYMBOL_MULT
SYMBOL_I

sx = 61
pow(1+1+1,2225)
SYMBOL_POW
SYMBOL_LP
SYMBOL_I
SYMBOL_PLUS
SYMBOL_I
SYMBOL_PLUS
ERROR
Missing character ','
```

2. Вывод в файл после приема данных из консоли

```
1+6*8
sx = 49
pow(3*2,2+3)
sx = 7776
11+5*10
sx = 61
ERROR
Missing character ','
```
