data segment ;  
X db 0,0,0,0,0,'$'  
array dw 10000,1000,100,10,1   
Y dw 12345
data ends   

stack segment;
db 100 dup(0)
stack ends   

code segment ;
start:        ; 
     mov ax,data
     mov ds,ax  
     
     mov cx,5
     lea si,X
     lea di,array
     mov ax,Y 
next1:           
     mov dx,0      
     mov bx,[di]
     div bx  ; dx:ax/bx
     add al,30h
     mov [si],al
     
     mov ax,dx
     inc di
     inc di
     inc si
     loop next1

     lea dx,X
     mov ah,09h
     int 21h

     
;     mov cx,5;
;     lea si,X
;next:               
;     mov dl,[si] 
;     add dl,30h         
;     mov ah,02h
;     int 21h
;     inc si
;     loop next
      
code ends    
end start    