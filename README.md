# Loopless

A braindead specification for string manipulation.

I've used it for several embedded projects.

For more, see [HelloWorld.lop](HelloWorld.lop), where Loopless is presented in a literate fashion.

---

## Hello, World!

```Loopless
++++++++.---.+++++++..+++.>.<++++++++.--------.+++.------.--------.
```

```
HELLO WORLD
```

For how numbers map to characters, see [alphabet.csv](alphabet.csv).

---

## Operators

* ```+``` Increment current cell. If cell value is 255, doesn't increment.
* ```-``` Decrement current cell. If cell value is 0, doesn't decrement.
* ```<``` Select previous cell. If first cell, doesn't change cell.
* ```>``` Select next cell. If last cell, doesn't change cell.
* ```.``` Print alphabet representation of current cell.
* ```!``` Print current cell's number value, followed by a newline.

Note: There should be exactly 999 cells available.

--- 

## LICENSE

Both the reference implementation, [loopless.c](loopless.c), and all specification information found in this repository, are covered by the same license: [Creative Commons Zero, v1.0](https://creativecommons.org/publicdomain/zero/1.0/).

[![CC 0](https://i.creativecommons.org/p/zero/1.0/88x31.png)](https://creativecommons.org/publicdomain/zero/1.0/)

To the extent possible under law, James Milne has waived all copyright and related or neighboring rights to Loopless. This work is published from: Australia.