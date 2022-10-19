.model small
.stack
.data 

inicio db '-------------------------Bienvenido al juego de totito--------------------------$'
inicio1 db '                                                                                 $'
inicio2 db '--------------------------Universidad mesoamericana-----------------------------$'  
colrojo db 0ch   

.code

modo_texto proc
push ax
mov ah,00
mov al,03h
int 10h
pop ax
ret
modo_texto endp

modo_grafico proc
    push ax
    mov ah,00
    mov al,12h
    int 10h
    pop ax
    ret
modo_grafico endp

pixel proc
    push ax
    push bx
    push cx
    push dx
    push bp
    mov ah,0ch
    mov al,colrojo
    mov bh,00
    mov bp,sp
    mov cx,[bp+12]
    mov dx,[bp+14]
    int 10h
    pop bp
    pop dx
    pop cx
    pop bx
    pop ax
    ret 
pixel endp



base proc
mov cx, 75
mov dx, 50
linea0:
    push dx
    push cx
    call pixel
    pop cx
    pop dx
loop linea0
mov cx,75
mov dx,50
linea1:       
    push cx
    push dx     
    call pixel
    pop dx
    pop cx
loop linea1
mov cx, 75
mov dx, 25
linea2:       
    push cx
    push dx     
    call pixel
    pop dx
    pop cx
loop linea2    
mov cx, 75
mov dx, 25
linea3:
    push dx
    push cx        
    call pixel
    pop cx
    pop dx
loop linea3
base endp

insertar proc
mov ah, 01
int 21h
ret
insertar endp

start:
mov dx,@data
mov ds,dx

mov ah,09
lea dx,inicio
int 21h
mov ah,01
int 21h

call modo_grafico
call base

mov ah, 01
int 21h
mov ax,4c00h
int 21h
end start