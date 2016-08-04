GLOBAL _test

_test:
push ebp
mov ebp, esp
mov eax, [ebp+8]
xor edx, edx
div  dword [ebp+12]
mov esp, ebp
pop ebp
ret
