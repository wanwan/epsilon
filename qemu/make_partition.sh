#!/bin/bash

gdisk $1 << END
?
p
n
1
$'\n'
+5M
ef00
n
2



w
Y
END
