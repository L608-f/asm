#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

extern void unch(); 
extern void snch();
extern void unint();
extern int16_t va, vb, vc;
extern int32_t res, divd, divr;
int main()
{
    printf("(a + b*c - 1)/(a/3 + 1)\n");
    printf("a: ");
    scanf("%hd", &va);
    printf("b: ");
    scanf("%hd", &vb);
    printf("c: ");
    scanf("%hd", &vc);
    printf("\n");

    //(a + b*c - 1)/(a/3 + 1)

    unch();
    uint8_t a = va, b = vb, c = vc;
    printf("---UnsignedChar---\n");
    printf("from 0 to 255\n\n");
    if ((uint16_t)(a/3 + 1) != 0)
    {
        printf("Numerator: %hu\n", (uint16_t)(a + b*c - 1));
        printf("Denominator: %hu\n", (uint16_t)(a/3 + 1));
        printf("cResult: %hu\n\n", (uint16_t)(a + b*c - 1) / (uint16_t)(a/3 + 1));
    }
    else
        printf("cResult: division by zero\n\n");
    printf("Numerator: %hu\n", divd);
    printf("Denominator: %hu\n", divr);
    printf("Result: %hu\n\n", res);


    snch();
    printf("---SignedChar---\n");
    printf("from -128 to 127\n\n");
    if ((int16_t)(va/3+1) != 0)
    {
        printf("Numerator: %hd\n", (int16_t)(va + vb*vc - 1));
        printf("Denominator: %hd\n", (int16_t)(va/3 + 1));
        printf("cResult: %hd\n\n", (int16_t)(va + vb*vc - 1) / (int16_t)(va/3 + 1));
    }
    else
        printf("cResult: division by zero\n\n");
    printf("Numerator: %hd\n", divd);
    printf("Denominator: %hd\n", divr);
    printf("Result: %hd\n\n", res);


    unint();
    uint16_t wa = va, wb = vb, wc = vc;
    printf("---UnsignedInt---\n");
    printf("from 0 to 65 535\n\n");
    if ((uint32_t)(wa/3 + 1) != 0)
    {
        printf("Numerator: %u\n", (uint32_t)(wa + wb*wc - 1));
        printf("Denominator: %u\n", (uint32_t)(wa/3 + 1));
        printf("cResult: %u\n\n", (uint32_t)(wa + wb*wc - 1) / (uint32_t)(wa/3 + 1));
    }
    else
        printf("cResult: division by zero\n\n");
    printf("Numerator: %u\n", divr);
    printf("Denominator: %u\n", divd);
    printf("Result: %u\n\n", res);
}