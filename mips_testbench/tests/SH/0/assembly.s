addi $3, $0, 0
addi $4, $0, 1
addi $5, $0, 2
addi $6, $0, 3

addi $1, $0, 0 #1 used as shift

sllv $6, $6, $1 #0b00000000000000000000000000000011
addi $1, $1, 8
sllv $5, $5, $1 #0b00000000000000000000001000000000
addi $1, $1, 8
sllv $4, $4, $1 #0b00000000000000010000000000000000
addi $1, $1, 8
sllv $3, $3, $1 #0b00000000000000000000000000000000
OR $2, $3, $4
OR $2, $2, $5
OR $2, $2, $6 #0b00000000000000010000001000000011

#testbench confirms up to this point correct, decimal value of $2 is 66051 as expected

li $1, 0x20000000
SH $2, 0($1) #stores 0b0000001000000011 as most significant half
LW $2, 0($1) #now most significant half of $2
SRL $3, $2, 16
SRL $2, $3, 7
OR $2, $2, $3
jr $0
#expect 0b0111 = 7
