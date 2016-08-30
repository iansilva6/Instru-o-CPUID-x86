#include <stdio.h>
#include <stdint.h>
#include <cpuid.h>
#include <string.h>

int main(int argc, char **argv)
{
    // a função opcode CPUID:
    int op;
    
    // registradores:
    int eax;
    int ebx;
    int ecx;
    int edx;
    
    // parâmetro zero para CPUID indica que você quer o fabricante.
    op = 0;
    
    __asm__ ("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx)
             : "a" (op));
    
    // Receberá os valores de EBX, ECX e EDX para sistemas 32bits:
    char vendor[sizeof(int) * 3 + 1];
    strncpy(vendor, (const char*) &ebx, sizeof(int));
    strncpy(&vendor[8], (const char*) &ecx, sizeof(int));
    strncpy(&vendor[4], (const char*) &edx, sizeof(int));
    vendor[12] = '\0'; // terminador nulo
    
    printf("CPU: %s", vendor);
    
    return 0;
}