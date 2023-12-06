# Cut 的細節

嚴格一點可以更好的減少呼叫，但同時也可能在檢查時花費更多時間。

## Local Test

| Property    | mainAC.c        | mainModified.c    |
| ----------- | --------------- | ----------------- |
| check       | all before cur  | only (cur - 1)    |
| time(local) | 953ms           | 149ms             |
| graph       | store with bond | store with matrix |
