lui $25, 0xfff0;
bgtz $25, 8;

#code that is executed if false
addi $2, $0, 5; 
jr $0;

#code that is executed if true
addi $2, $0, 7;
jr $0; 
